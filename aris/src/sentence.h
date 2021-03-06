/* The sentence structure.

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

#ifndef ARIS_SENTENCE_H
#define ARIS_SENTENCE_H

#include "pound.h"

#define SENTENCE(o) ((sentence *) o)
#define SEMI_NAME "semi"

typedef struct sentence sentence;
typedef struct sen_parent sen_parent;
typedef struct sen_data sen_data;
typedef struct list list_t;
typedef struct item item_t;
typedef struct proof proof_t;


struct sentence {
  // Data components
  int line_num;           // Keeps track of the line number.
  int rule;               // Index of the rule of this sentence.
  unsigned char * text;   // Contains the text of this item.
  int reference : 1;      // Whether or not this sentence is a reference.
  unsigned char * sexpr;  // The sexpr text of this sentence.

  unsigned char ** vars;  // The variables used in this sentence.

  int premise : 1;   // Whether or not this sentence is a premise.
  int subproof : 1;  // Whether or not this sentence starts a subproof.
  int depth;         // The depth of this sentence.  0 for all top levels.
  int * indices;     // The line numbers of the subproofs that contain this sentence.

  list_t * refs;         // A list of sentences that are references.

  unsigned char * file;   // The file name if lemma is used on this sentence.

  proof_t * proof;        // The proof for this sentence, if lemma is used.

  // GUI components
  GtkWidget * panel;      // Contains the other items. - GtkHBox
  GtkWidget * entry;      // Actual Text Entry. - GtkTextView
  GtkWidget * line_no;    // The line number of this sentence. - GtkLabel
  GtkWidget * value;      // True / False indicator. - GtkLabel
  GtkWidget * eventbox;   // Contains the line number label.
  GtkTextMark * mark;     // The mark that keeps track of the semi-colon in a sentence.
  int selected : 1;       // Whether or not this sentence is selected.
  int bg_color;    // The index in the_app->bg_colors of the background color.
  int value_type;  // The index of the value type of this sentence.

  sen_parent * parent;  // The parent of this sentence.

  int sig_id;  // The signal id of the mapping signal for this sentence.

  int matching_parens : 1;  // Whether or not parentheses are being matched.
};

sentence * sentence_init (sen_data * sd, sen_parent * sp, item_t * fcs);
void sentence_gui_init (sentence * sen);
void sentence_destroy (sentence * sen);

sen_data * sentence_copy_to_data (sentence * sen);

int sentence_out (sentence * sen);
int sentence_in (sentence * sen);
int sentence_key (sentence * sen, int key, int ctrl);
int sentence_text_changed (sentence * sen);

int select_reference (sentence * sen);
int select_sentence (sentence * sen);

int sentence_set_line_no (sentence * sen, int new_line_no);
void sentence_set_font (sentence * sen, int font);
void sentence_set_bg (sentence * sen, int bg_color);
void sentence_set_value (sentence * sen, int value_type);
int sentence_collect_variables (sentence * sen);
void sentence_set_reference (sentence * sen, int reference, int entire_subproof);
void sentence_set_selected (sentence * sen, int selected);
int sentence_check_entire (sentence * sen, sentence * ref);
int sentence_check_boolean_rule (sentence * sen, int boolean);
int sentence_can_select_as_ref (sentence * sen, sentence * ref);

void sentence_connect_signals (sentence * sen);

#endif  /*  ARIS_SENTENCE_H  */
