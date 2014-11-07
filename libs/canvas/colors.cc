/*
    Copyright (C) 2014 Paul Davis

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include <algorithm>
#include <cmath>
#include <stdint.h>

#include "canvas/colors.h"

using namespace std;
using namespace ArdourCanvas;

using std::max;
using std::min;

void
ArdourCanvas::color_to_hsv (Color color, double& h, double& s, double& v)
{
	double r, g, b, a;
	double cmax;
	double cmin;
	double delta;
	
	color_to_rgba (color, r, g, b, a);
	
	if (r > g) {
		cmax = max (r, b);
	} else {
		cmax = max (g, b);
	}

	if (r < g) {
		cmin = min (r, b);
	} else {
		cmin = min (g, b);
	}

	v = cmax;

	delta = cmax - cmin;

	if (cmax == 0) {
		// r = g = b == 0 ... v is undefined, s = 0
		s = 0.0;  
		h = -1.0;
	}

	if (delta != 0.0) {	
		if (cmax == r) {
			h = fmod ((g - b)/delta, 6.0);
		} else if (cmax == g) {
			h = ((b - r)/delta) + 2;
		} else {
			h = ((r - g)/delta) + 4;
		}
		
		h *= 60.0;
	}

	if (delta == 0 || cmax == 0) {
		s = 0;
	} else {
		s = delta / cmax;
	}

}

ArdourCanvas::Color
ArdourCanvas::hsv_to_color (double h, double s, double v, double a)
{
	s = min (1.0, max (0.0, s));
	v = min (1.0, max (0.0, v));

	if (s == 0) {
		// achromatic (grey)
		return rgba_to_color (v, v, v, a);
	}

	h = min (360.0, max (0.0, h));

	double c = v * s;
        double x = c * (1.0 - fabs(fmod(h / 60.0, 2) - 1.0));
        double m = v - c;

        if (h >= 0.0 && h < 60.0) {
		return rgba_to_color (c + m, x + m, m, a);
        } else if (h >= 60.0 && h < 120.0) {
		return rgba_to_color (x + m, c + m, m, a);
        } else if (h >= 120.0 && h < 180.0) {
		return rgba_to_color (m, c + m, x + m, a);
        } else if (h >= 180.0 && h < 240.0) {
		return rgba_to_color (m, x + m, c + m, a);
        } else if (h >= 240.0 && h < 300.0) {
		return rgba_to_color (x + m, m, c + m, a);
        } else if (h >= 300.0 && h < 360.0) {
		return rgba_to_color (c + m, m, x + m, a);
        } 
	return rgba_to_color (m, m, m, a);
}

void
ArdourCanvas::color_to_rgba (Color color, double& r, double& g, double& b, double& a)
{
	r = ((color >> 24) & 0xff) / 255.0;
	g = ((color >> 16) & 0xff) / 255.0;
	b = ((color >>  8) & 0xff) / 255.0;
	a = ((color >>  0) & 0xff) / 255.0;
}

ArdourCanvas::Color
ArdourCanvas::rgba_to_color (double r, double g, double b, double a)
{
	/* clamp to [0 .. 1] range */

	r = min (1.0, max (0.0, r));
	g = min (1.0, max (0.0, g));
	b = min (1.0, max (0.0, b));
	a = min (1.0, max (0.0, a));

	/* convert to [0..255] range */

	unsigned int rc, gc, bc, ac;
	rc = rint (r * 255.0);
	gc = rint (g * 255.0);
	bc = rint (b * 255.0);
	ac = rint (a * 255.0);

	/* build-an-integer */

	return (rc << 24) | (gc << 16) | (bc << 8) | ac;
}

// Inverse of sRGB "gamma" function.
static inline double 
inv_gam_sRGB (double c) 
{
        if (c <= 0.04045) {
                return c/12.92;
        } else {
                return pow(((c+0.055)/(1.055)),2.4);
        }
}

// sRGB "gamma" function
static inline int 
gam_sRGB(double v) 
{
        if (v <= 0.0031308) {
                v *= 12.92;
        } else {
                v = 1.055 * pow (v, 1.0 / 2.4) - 0.055;
        }
        return int (v*255+.5);
}

static double 
luminance (uint32_t c)
{
        // sRGB luminance(Y) values
        const double rY = 0.212655;
        const double gY = 0.715158;
        const double bY = 0.072187;

        double r, g, b, a;

        ArdourCanvas::color_to_rgba (c, r, g, b, a);
        
        return (gam_sRGB (rY*inv_gam_sRGB(r) + gY*inv_gam_sRGB(g) + bY*inv_gam_sRGB(b))) / 255.0;
}    

uint32_t
ArdourCanvas::contrasting_text_color (uint32_t c)
{
        static const uint32_t white = ArdourCanvas::rgba_to_color (1.0, 1.0, 1.0, 1.0);
        static const uint32_t black = ArdourCanvas::rgba_to_color (0.0, 0.0, 0.0, 1.0);

	return (luminance (c) < 0.50) ? white : black;
}