/*  Menu data types.

   Copyright (C) 2012 Ian Dunn.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ARIS_MENU_H
#define ARIS_MENU_H

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

// Menu ids for the aris proofs, used in other gui menus as well.

enum MENU_ID {
  MENU_NEW=0,
  MENU_OPEN,
  MENU_FILE_SEP_0,
  MENU_SAVE,
  MENU_SAVE_AS,
  MENU_FILE_SEP_1,
  MENU_CLOSE,
  MENU_QUIT,
  MENU_ADD_PREM,
  MENU_ADD_CONC,
  MENU_ADD_SUB,
  MENU_END_SUB,
  MENU_LINE_SEP_0,
  MENU_COPY,
  MENU_KILL,
  MENU_INSERT,
  MENU_EVAL_LINE,
  MENU_EVAL_PROOF,
  MENU_PROOF_SEP_0,
  MENU_GOAL,
  MENU_BOOLEAN,
  MENU_TOGGLE_RULES,
  MENU_RULES_SEP_1,
  MENU_SMALL,
  MENU_MEDIUM,
  MENU_LARGE,
  MENU_CUSTOM,
  MENU_CONTENTS,
  MENU_ABOUT
};

// Menu type enum, fairly self-explanatory.

enum MENU_TYPE {
    STANDARD=0,
    SEPARATOR,
    RADIO,
    PARENT
};

typedef struct menu_item_data mid_t;

// The actual menu item data type.

struct menu_item_data {
  char * label;     // The label of the menu item.
  char * tooltip;   // The tooltip text of the menu item.
  char * stock_id;  // The stock id of the menu icon.
  int keyval;       // The keyval of the keyboard shortcut to activate the menu item.
  int mods;         // Modifiers for the keyboard shortcut.
  int type;   // The menu type of this menu item.
  int id;       // The menu id of this menu item.
};

GtkWidget * construct_menu_item (mid_t data, GCallback func, GtkWidget * parent, GtkAccelGroup * accel, int * got_radio);

#endif  /*  ARIS_MENU_H  */
