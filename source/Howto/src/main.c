/*
 * main.c initial généré par Glade. Editer ce fichier à votre
 * convenance. Glade n'écrira plus dans ce fichier.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gnome.h>
#include <dirent.h>
#include <stdio.h>

#include "interface.h"
#include "support.h"
#include "donnees.h"

  GtkWidget *dialog1;
  GtkWidget *about1;
  GtkWidget *Patience;
  char schdir [256];
  char baseref [256];
  char home [256];
  char cmd[512];
  int rapide;
  int first;
  DIR * dirp;
  FILE * fcbase;

int
main (int argc, char *argv[], char *env[])
{

#ifdef ENABLE_NLS
  bindtextdomain (PACKAGE, PACKAGE_LOCALE_DIR);
  textdomain (PACKAGE);
#endif

  gnome_init ("howto", VERSION, argc, argv);

  // Paramètrage des répertoires de XWine
  strcpy(home,getenv("HOME"));
  strcpy(schdir,home);
  strcat(schdir,"/.search4ldp");
  strcpy(baseref,schdir);
  strcat(baseref,"/base.ldp");

  //Verif répertoire Search4LDP
  dirp=opendir(schdir);
  if (dirp==NULL) mkdir(schdir,0755);
  else closedir(dirp);

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  dialog1 = create_dialog1 ();
  about1 = create_about1 ();
  Patience = create_Patience ();
  gtk_widget_show (dialog1);
  rapide=1;

  //Verif fichier baseref
  fcbase=fopen(baseref,"rt");
  if (fcbase==NULL)
  {
    first=1;
    gtk_widget_show (Patience);
  } 
  else fclose(fcbase);

  gtk_main ();
  return 0;
}

