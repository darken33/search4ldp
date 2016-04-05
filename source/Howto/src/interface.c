/*
 * NE PAS ÉDITER CE FICHIER - il est généré par Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#include <gnome.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

GtkWidget*
create_dialog1 (void)
{
  GtkWidget *dialog1;
  GtkWidget *dialog_vbox1;
  GtkWidget *frame1;
  GtkWidget *fixed1;
  GtkWidget *entry1;
  GtkWidget *hbox1;
  GtkWidget *label1;
  GtkWidget *combo1;
  GList *combo1_items = NULL;
  GtkWidget *combo_entry1;
  GtkWidget *checkbutton1;
  GtkWidget *frame2;
  GtkWidget *MAJBase;
  GtkWidget *dialog_action_area1;
  GtkWidget *hbuttonbox1;
  GtkWidget *button3;
  GtkWidget *button4;
  GtkWidget *button5;

  dialog1 = gtk_dialog_new ();
  gtk_object_set_data (GTK_OBJECT (dialog1), "dialog1", dialog1);
  gtk_window_set_title (GTK_WINDOW (dialog1), _("HOWTOs"));
  gtk_window_set_policy (GTK_WINDOW (dialog1), FALSE, FALSE, FALSE);

  dialog_vbox1 = GTK_DIALOG (dialog1)->vbox;
  gtk_object_set_data (GTK_OBJECT (dialog1), "dialog_vbox1", dialog_vbox1);
  gtk_widget_show (dialog_vbox1);

  frame1 = gtk_frame_new (_("Elément à rechercher"));
  gtk_widget_ref (frame1);
  gtk_object_set_data_full (GTK_OBJECT (dialog1), "frame1", frame1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (frame1);
  gtk_box_pack_start (GTK_BOX (dialog_vbox1), frame1, TRUE, TRUE, 0);

  fixed1 = gtk_fixed_new ();
  gtk_widget_ref (fixed1);
  gtk_object_set_data_full (GTK_OBJECT (dialog1), "fixed1", fixed1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (frame1), fixed1);
  gtk_widget_set_usize (fixed1, 310, 50);

  entry1 = gtk_entry_new ();
  gtk_widget_ref (entry1);
  gtk_object_set_data_full (GTK_OBJECT (dialog1), "entry1", entry1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (entry1);
  gtk_fixed_put (GTK_FIXED (fixed1), entry1, 8, 8);
  gtk_widget_set_uposition (entry1, 8, 8);
  gtk_widget_set_usize (entry1, 300, 24);

  hbox1 = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (hbox1);
  gtk_object_set_data_full (GTK_OBJECT (dialog1), "hbox1", hbox1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox1);
  gtk_box_pack_start (GTK_BOX (dialog_vbox1), hbox1, TRUE, TRUE, 0);

  label1 = gtk_label_new (_("  Rechercher:  "));
  gtk_widget_ref (label1);
  gtk_object_set_data_full (GTK_OBJECT (dialog1), "label1", label1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (label1);
  gtk_box_pack_start (GTK_BOX (hbox1), label1, FALSE, FALSE, 0);

  combo1 = gtk_combo_new ();
  gtk_widget_ref (combo1);
  gtk_object_set_data_full (GTK_OBJECT (dialog1), "combo1", combo1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (combo1);
  gtk_box_pack_start (GTK_BOX (hbox1), combo1, TRUE, TRUE, 0);
  gtk_widget_set_usize (combo1, 139, -2);
  combo1_items = g_list_append (combo1_items, (gpointer) _("Un des mots"));
  combo1_items = g_list_append (combo1_items, (gpointer) _("Tous les mots"));
  combo1_items = g_list_append (combo1_items, (gpointer) _("La phrase"));
  gtk_combo_set_popdown_strings (GTK_COMBO (combo1), combo1_items);
  g_list_free (combo1_items);

  combo_entry1 = GTK_COMBO (combo1)->entry;
  gtk_widget_ref (combo_entry1);
  gtk_object_set_data_full (GTK_OBJECT (dialog1), "combo_entry1", combo_entry1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (combo_entry1);
  gtk_entry_set_editable (GTK_ENTRY (combo_entry1), FALSE);
  gtk_entry_set_text (GTK_ENTRY (combo_entry1), _("Un des mots"));

  checkbutton1 = gtk_check_button_new_with_label (_("Rapide"));
  gtk_widget_ref (checkbutton1);
  gtk_object_set_data_full (GTK_OBJECT (dialog1), "checkbutton1", checkbutton1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (checkbutton1);
  gtk_box_pack_start (GTK_BOX (hbox1), checkbutton1, FALSE, FALSE, 0);
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (checkbutton1), TRUE);

  frame2 = gtk_frame_new (NULL);
  gtk_widget_ref (frame2);
  gtk_object_set_data_full (GTK_OBJECT (dialog1), "frame2", frame2,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (frame2);
  gtk_box_pack_start (GTK_BOX (dialog_vbox1), frame2, FALSE, FALSE, 0);

  MAJBase = gtk_button_new_with_label (_("Mettre à jour la base de référence"));
  gtk_widget_ref (MAJBase);
  gtk_object_set_data_full (GTK_OBJECT (dialog1), "MAJBase", MAJBase,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (MAJBase);
  gtk_container_add (GTK_CONTAINER (frame2), MAJBase);

  dialog_action_area1 = GTK_DIALOG (dialog1)->action_area;
  gtk_object_set_data (GTK_OBJECT (dialog1), "dialog_action_area1", dialog_action_area1);
  gtk_widget_show (dialog_action_area1);
  gtk_container_set_border_width (GTK_CONTAINER (dialog_action_area1), 10);

  hbuttonbox1 = gtk_hbutton_box_new ();
  gtk_widget_ref (hbuttonbox1);
  gtk_object_set_data_full (GTK_OBJECT (dialog1), "hbuttonbox1", hbuttonbox1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbuttonbox1);
  gtk_box_pack_start (GTK_BOX (dialog_action_area1), hbuttonbox1, TRUE, TRUE, 0);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (hbuttonbox1), GTK_BUTTONBOX_END);
  gtk_button_box_set_spacing (GTK_BUTTON_BOX (hbuttonbox1), 0);

  button3 = gnome_stock_button (GNOME_STOCK_BUTTON_HELP);
  gtk_widget_ref (button3);
  gtk_object_set_data_full (GTK_OBJECT (dialog1), "button3", button3,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (button3);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), button3);
  GTK_WIDGET_SET_FLAGS (button3, GTK_CAN_DEFAULT);

  button4 = gnome_stock_button (GNOME_STOCK_BUTTON_OK);
  gtk_widget_ref (button4);
  gtk_object_set_data_full (GTK_OBJECT (dialog1), "button4", button4,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (button4);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), button4);
  GTK_WIDGET_SET_FLAGS (button4, GTK_CAN_DEFAULT);

  button5 = gnome_stock_button (GNOME_STOCK_BUTTON_CANCEL);
  gtk_widget_ref (button5);
  gtk_object_set_data_full (GTK_OBJECT (dialog1), "button5", button5,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (button5);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), button5);
  GTK_WIDGET_SET_FLAGS (button5, GTK_CAN_DEFAULT);

  gtk_signal_connect (GTK_OBJECT (dialog1), "destroy",
                      GTK_SIGNAL_FUNC (on_dialog1_destroy),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (checkbutton1), "toggled",
                      GTK_SIGNAL_FUNC (on_checkbutton1_toggled),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (MAJBase), "clicked",
                      GTK_SIGNAL_FUNC (on_MAJBase_clicked),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (button3), "clicked",
                      GTK_SIGNAL_FUNC (on_button3_clicked),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (button4), "clicked",
                      GTK_SIGNAL_FUNC (on_button4_clicked),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (button5), "clicked",
                      GTK_SIGNAL_FUNC (on_button5_clicked),
                      NULL);

  gtk_widget_grab_focus (entry1);
  gtk_widget_grab_default (button4);
  return dialog1;
}

GtkWidget*
create_about1 (void)
{
  const gchar *authors[] = {
    "Philippe BOUSQUET",
    "229 rue Sainte Catherine,",
    "33000 BORDEAUX, FRANCE.",
    "Tel: 06.61.99.25.84",
    NULL
  };
  GtkWidget *about1;

  about1 = gnome_about_new ("Howto", VERSION,
                        _("Copyright (c) 2001 - Philippe BOUSQUET"),
                        authors,
                        _("Logiciel distribué sous la licence GNU GENERAL PUBLIC LICENSE"),
                        NULL);
  gtk_object_set_data (GTK_OBJECT (about1), "about1", about1);
  gtk_window_set_modal (GTK_WINDOW (about1), TRUE);

  gtk_signal_connect (GTK_OBJECT (about1), "destroy",
                      GTK_SIGNAL_FUNC (on_about1_destroy),
                      NULL);

  return about1;
}

GtkWidget*
create_Patience (void)
{
  GtkWidget *Patience;
  GtkWidget *dialog_vbox2;
  GtkWidget *button6;
  GtkWidget *button7;
  GtkWidget *dialog_action_area2;

  /* We create it with an OK button, and then remove the button, to work
     around a bug in gnome-libs. */
  Patience = gnome_message_box_new (_("Veuillez patienter:\nLe système va mettre à jour votre base de référence..."),
                              GNOME_MESSAGE_BOX_WARNING,
                              GNOME_STOCK_BUTTON_OK, NULL);
  gtk_container_remove (GTK_CONTAINER (GNOME_DIALOG (Patience)->action_area), GNOME_DIALOG (Patience)->buttons->data);
  GNOME_DIALOG (Patience)->buttons = NULL;
  gtk_object_set_data (GTK_OBJECT (Patience), "Patience", Patience);
  gtk_window_set_title (GTK_WINDOW (Patience), _("Information"));
  gtk_window_set_position (GTK_WINDOW (Patience), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (Patience), TRUE);
  gtk_window_set_policy (GTK_WINDOW (Patience), FALSE, FALSE, FALSE);

  dialog_vbox2 = GNOME_DIALOG (Patience)->vbox;
  gtk_object_set_data (GTK_OBJECT (Patience), "dialog_vbox2", dialog_vbox2);
  gtk_widget_show (dialog_vbox2);

  gnome_dialog_append_button (GNOME_DIALOG (Patience), GNOME_STOCK_BUTTON_OK);
  button6 = GTK_WIDGET (g_list_last (GNOME_DIALOG (Patience)->buttons)->data);
  gtk_widget_ref (button6);
  gtk_object_set_data_full (GTK_OBJECT (Patience), "button6", button6,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (button6);
  GTK_WIDGET_SET_FLAGS (button6, GTK_CAN_DEFAULT);

  gnome_dialog_append_button (GNOME_DIALOG (Patience), GNOME_STOCK_BUTTON_CANCEL);
  button7 = GTK_WIDGET (g_list_last (GNOME_DIALOG (Patience)->buttons)->data);
  gtk_widget_ref (button7);
  gtk_object_set_data_full (GTK_OBJECT (Patience), "button7", button7,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (button7);
  GTK_WIDGET_SET_FLAGS (button7, GTK_CAN_DEFAULT);

  dialog_action_area2 = GNOME_DIALOG (Patience)->action_area;
  gtk_widget_ref (dialog_action_area2);
  gtk_object_set_data_full (GTK_OBJECT (Patience), "dialog_action_area2", dialog_action_area2,
                            (GtkDestroyNotify) gtk_widget_unref);

  gtk_signal_connect (GTK_OBJECT (Patience), "destroy",
                      GTK_SIGNAL_FUNC (on_Patience_destroy),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (button6), "clicked",
                      GTK_SIGNAL_FUNC (on_button6_clicked),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (button7), "clicked",
                      GTK_SIGNAL_FUNC (on_button7_clicked),
                      NULL);

  return Patience;
}

