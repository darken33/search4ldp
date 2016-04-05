#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gnome.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "param.h"
#include "donnees.h"

char cmd [512];
char txt [255];
char * prefx=PREFIX;
char * nav=NAVIGATEUR;

void
on_dialog1_destroy                     (GtkObject       *object,
                                        gpointer         user_data)
{
  gtk_main_quit();
}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_widget_show (about1);
}


void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  strcpy(cmd,"perl \0");
  strcat(cmd,prefx);
  strcat(cmd,"/bin/search4ldp.pl Texte=\"\0");
  strcpy(txt, gtk_entry_get_text(GTK_ENTRY(lookup_widget(dialog1,"entry1"))));
  strcat(cmd,txt);
  strcat(cmd,"\" Base=");
  strcat(cmd,baseref);
  strcpy(txt, gtk_entry_get_text(GTK_ENTRY(lookup_widget(dialog1,"combo_entry1"))));
  if (strcmp(txt,"Un des mots\0")==0)
  {
    strcat(cmd," Operateur=OU");
  }
  else if (strcmp(txt,"Tous les mots\0")==0)
  {
    strcat(cmd," Operateur=ET");
  }
  else
  {
    strcat(cmd," Operateur=PHRASE");
  }
  if (rapide)
  {
    strcat(cmd," Rapide=Oui Titre=\"<IMG SRC=");
  }
  else
  {
    strcat(cmd," Rapide=Non Titre=\"<IMG SRC=");
  }
  strcat(cmd,prefx);
  strcat(cmd,"/share/search4ldp/search4ldp.jpg>\" >");
  strcat(cmd,schdir);
  strcat(cmd,"/.search4ldp.html 2>/dev/null");
  system(cmd);
  strcpy(cmd,nav);
  strcat(cmd,"  file://");
  strcat(cmd,schdir);
  strcat(cmd,"/.search4ldp.html & >/dev/null 2>/dev/null");
  system(cmd);
}


void
on_about1_destroy                      (GtkObject       *object,
                                        gpointer         user_data)
{
  about1 = create_about1 ();
}


void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_main_quit();
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  rapide=(! rapide);
}


void
on_MAJBase_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
    first=0; 
    gtk_widget_show (Patience);
}


void
on_Patience_destroy                    (GtkObject       *object,
                                        gpointer         user_data)
{
  Patience=create_Patience();
}


void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
    strcpy(cmd,"perl \0");
    strcat(cmd,prefx);
    strcat(cmd,"/bin/findhtml.pl 2>/dev/null >\0");
    strcat(cmd,baseref);
    system(cmd);
    gtk_widget_hide (Patience);
}


void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  if (first)
  {
    fprintf(stderr,"err01: la base de référence n'est pas à jour !!!\n");
    gtk_main_quit();
  }
  else gtk_widget_hide (Patience);
}

