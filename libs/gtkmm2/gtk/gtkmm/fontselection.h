// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_FONTSELECTION_H
#define _GTKMM_FONTSELECTION_H

#include <glibmm.h>

/* $Id$ */

/* Copyright (C) 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#include <gtkmm/dialog.h>
#include <gtkmm/box.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkFontSelection GtkFontSelection;
typedef struct _GtkFontSelectionClass GtkFontSelectionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class FontSelection_Class; } // namespace Gtk
#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkFontSelectionDialog GtkFontSelectionDialog;
typedef struct _GtkFontSelectionDialogClass GtkFontSelectionDialogClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class FontSelectionDialog_Class; } // namespace Gtk
namespace Gtk
{

class Button;
class Entry;
class RadioButton;


/** A widget for selecting fonts.
 *
 * The Gtk::FontSelection widget lists the available fonts, styles and
 * sizes, allowing the user to select a font. It is used in the
 * Gtk::FontSelectionDialog widget to provide a dialog box for selecting
 * fonts. 
 * 
 * @ingroup Widgets
 */

class FontSelection : public VBox
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef FontSelection CppObjectType;
  typedef FontSelection_Class CppClassType;
  typedef GtkFontSelection BaseObjectType;
  typedef GtkFontSelectionClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~FontSelection();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class FontSelection_Class;
  static CppClassType fontselection_class_;

  // noncopyable
  FontSelection(const FontSelection&);
  FontSelection& operator=(const FontSelection&);

protected:
  explicit FontSelection(const Glib::ConstructParams& construct_params);
  explicit FontSelection(GtkFontSelection* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkFontSelection*       gobj()       { return reinterpret_cast<GtkFontSelection*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkFontSelection* gobj() const { return reinterpret_cast<GtkFontSelection*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

  
public:
  FontSelection();

  
  Glib::ustring get_font_name() const;
  
  bool set_font_name(const Glib::ustring& fontname);
  
  Glib::ustring get_preview_text() const;
  
  void set_preview_text(const Glib::ustring& fontname);

  // Font page
  Entry* get_font_entry();
  const Entry* get_font_entry() const;
  Entry* get_font_style_entry();
  const Entry* get_font_style_entry() const;
  Entry* get_size_entry();
  const Entry* get_size_entry() const;

  RadioButton* get_pixels_button();
  const RadioButton* get_pixels_button() const;
  RadioButton* get_points_button();
  const RadioButton* get_points_button() const;
  Button* get_filter_button();
  const Button* get_filter_button() const;

  Entry* get_preview_entry();
  const Entry* get_preview_entry() const;

  /** The X string that represents this font.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<Glib::ustring> property_font_name() ;

/** The X string that represents this font.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Glib::ustring> property_font_name() const;

  /** The text to display in order to demonstrate the selected font.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<Glib::ustring> property_preview_text() ;

/** The text to display in order to demonstrate the selected font.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Glib::ustring> property_preview_text() const;


};

/** A dialog box for selecting fonts.
 *
 * The Gtk::FontSelectionDialog widget is a dialog box for selecting a font. 
 *
 * @ingroup Dialogs
 */

class FontSelectionDialog : public Dialog
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef FontSelectionDialog CppObjectType;
  typedef FontSelectionDialog_Class CppClassType;
  typedef GtkFontSelectionDialog BaseObjectType;
  typedef GtkFontSelectionDialogClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~FontSelectionDialog();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class FontSelectionDialog_Class;
  static CppClassType fontselectiondialog_class_;

  // noncopyable
  FontSelectionDialog(const FontSelectionDialog&);
  FontSelectionDialog& operator=(const FontSelectionDialog&);

protected:
  explicit FontSelectionDialog(const Glib::ConstructParams& construct_params);
  explicit FontSelectionDialog(GtkFontSelectionDialog* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkFontSelectionDialog*       gobj()       { return reinterpret_cast<GtkFontSelectionDialog*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkFontSelectionDialog* gobj() const { return reinterpret_cast<GtkFontSelectionDialog*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

  
public:

  FontSelectionDialog();
  explicit FontSelectionDialog(const Glib::ustring& title);

  
  bool set_font_name(const Glib::ustring& fontname);
  
  Glib::ustring get_font_name() const;
  
  Glib::ustring get_preview_text() const;
  
  void set_preview_text(const Glib::ustring& fontname);

  FontSelection* get_font_selection();
  const FontSelection* get_font_selection() const;
  Button* get_ok_button();
  const Button* get_ok_button() const;
  Button* get_apply_button();
  const Button* get_apply_button() const;
  Button* get_cancel_button();
  const Button* get_cancel_button() const;


};

} // namespace Gtk


namespace Glib
{
  /** @relates Gtk::FontSelection
   * @param object The C instance
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   */
  Gtk::FontSelection* wrap(GtkFontSelection* object, bool take_copy = false);
}
namespace Glib
{
  /** @relates Gtk::FontSelectionDialog
   * @param object The C instance
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   */
  Gtk::FontSelectionDialog* wrap(GtkFontSelectionDialog* object, bool take_copy = false);
}
#endif /* _GTKMM_FONTSELECTION_H */
