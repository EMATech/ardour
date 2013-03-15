/*
    Copyright (C) 2010 Paul Davis
    Author: Robin Gareus <robin@gareus.org>

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
#ifdef WITH_VIDEOTIMELINE

#ifndef __gtk_ardour_export_video_infobox_h__
#define __gtk_ardour_export_video_infobox_h__

#include <gtkmm.h>
#include "ardour_dialog.h"

/** @class ExportVideoInfobox
 *  @brief optional info box regarding video-export
 *
 * This dialog is optional and can be en/disabled in the
 * Preferences.
 */
class ExportVideoInfobox : public ArdourDialog
{
  public:
	ExportVideoInfobox (ARDOUR::Session*);
	~ExportVideoInfobox ();

	bool show_again () { return showagain_checkbox.get_active(); }

  private:
	//void on_show ();
	Gtk::CheckButton showagain_checkbox;
};

#endif /* __gtk_ardour_export_video_infobox_h__ */

#endif /* WITH_VIDEOTIMELINE */