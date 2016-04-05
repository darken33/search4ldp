#!/usr/bin/perl

# FindHtml v0.1
# Recherche des fichier Html pour la mise a jour de la base Search4LDP
#-------------------------------------------------
# Par Philippe BOUSQUET
# Copyright (c) 2001 - Philippe BOUSQUET
# Sous License: GENERAL PUBLIC LICENSE

# Ce script � besoin de find.pl
require ("/usr/lib/perl5/5.6.0/find.pl");

$VERSION = "0.1";

# Variables pass�es en param�tres
# r�pertoire de recherche
$BASEDIR="/usr";

# Lancer la recherche
&find ($BASEDIR);

# Sub Wanted
sub wanted
{
   if ($name =~ /\.htm/)
   {
      # Afficher le chemin de la page
      print ("$name\n")
   }
}
