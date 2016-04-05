#!/usr/bin/bin/perl
## Search4LDP v0.5
## Moteur de recherche pour le LDP
## ----------------------------------------- 
## Par Philippe BOUSQUET
## Copyright (c) 2001 - Philippe BOUSQUET
## Sous License: GENERAL PUBLIC LICENSE

## Ce script à besoin de find.pl
require ("find.pl");
## Script CGI
use CGI qw(param);

## Version du logiciel
$VERSION = "0.5";
## Variables passées en paramètres
## Paramétrage de la page de sortie
$DOCTITRE=param("DocTitre");
$BDYTITRE=param("Titre");
$LINK=param("Link");
$VLINK=param("VLink");
$CLTITRE=param("ClTitre");
$CLBACK=param("ClBack");
$CLTEXT=param("ClText");
$CLBAN=param("ClBaniere");
$CLBTEXT=param("ClBText");
## répertoire de recherche
$NBMAX=param("NbMax");
$BASEDIR=param("Base");
$ALIASSRC=param("AliasSrc");
$ALIASDEST=param("AliasDest");
## termes à rechercher
$TERMR=param("Texte");
## Operation sur les termes
$OPE=param("Operateur");
## Recherche Rapide
$RECR=param("Rapide");
## nombre de pages trouvées
$NBPF=0;
$NBMOTS=0;
## TABLEAUX FINAUX
@TABF_TITRE="";
@TABF_REF="";
@TABF_NBL="";
$TB_TM="";

## Paramétrage par défaut
if ($DOCTITRE eq "") { $DOCTITRE="Recherche pour les HOWTOs en Francais"; }
if ($BDYTITRE eq "") { $BDYTITRE="Search4LDP v$VERSION"; }
if ($LINK eq "") { $LINK="#0000FF"; }
if ($VLINK eq "") { $VLINK="#FF00FF"; }
if ($CLTITRE eq "") { $CLTITRE="#FF0000"; }
if ($CLBACK eq "") { $CLBACK="#FFFFFF"; }
if ($CLTEXT eq "") { $CLTEXT="#000000"; }
if ($CLBAN eq "") { $CLBAN="#FFCC00"; }
if ($CLBTEXT eq "") { $CLBTEXT="#666699"; }
if ($NBMAX eq "") { $NBMAX=0; }

## Découper les termes
if ($OPE eq "ET") { @TB_TM=split(' ',$TERMR); }
elsif ($OPE eq "OU") { @TB_TM=split(' ',$TERMR); }
else { @TB_TM[0]=$TERMR; $OPE="PHRASE"; }
## Recherche rapide ?
if ($RECR eq "Oui") { $RECR="Oui"; }
else { $RECR="Non"; }

## le commentaire suivant est a supprimer pour les script CGI
print "Content-type: text/html\n\n";
print "<HTML>\n";
print "<HEAD>\n";
print "<META HTTP-EQUIV=\"CONTENT-TYPE\" CONTENT=\"text/html; charset=iso-8859-1\">\n";
print "<TITLE>$DOCTITRE</TITLE>\n";
print "</HEAD>\n";
print "<BODY BGCOLOR=\"$CLBACK\" TEXT=\"$CLTEXT\" LINK=\"$LINK\" VLINK=\"$VLINK\">\n";
print "<TABLE BORDER=0 CELLSPACING=2 CELLPADDING=2 COLS=1 WIDTH=\"100%\" STYLE=\"page-break-before: always\" >\n";
print "<TR>\n";
print "<TD><FONT COLOR=\"$CLTITRE\" SIZE=8><I><B>$BDYTITRE</B></I></FONT><BR></TD>\n";
print "</TR>\n";
print "</TABLE>\n";
print "<TABLE BORDER=\"0\" WIDTH=100% COLS=1>\n";
print "<TR>\n";
print "<TD BGCOLOR=\"$CLBAN\">\n";
print "<CENTER><FONT COLOR=\"$CLBTEXT\">\n";
print "<B>Résultat de la recherche</B>\n";
print "</TD>\n";
print "</TR>\n";
print "<TR>\n";
print "<TD><BR></TD>\n";
print "</TR>\n";
print "<TR>\n";

## Si la base est MaBase alors recupérer le contenu de ~/.search4ldp/base.ldp
if (-f $BASEDIR)
{
  open(FILE,$BASEDIR);
  @BASE=<FILE>;
  close(FILE);
  $BASEDIR="MaBase";
}
else { @BASE=split(':',$BASEDIR); }

## Lancer la recherche
foreach $TERM (@TB_TM)
{
  $NBMOTS++;
  @TAB_TITRE="";
  @TAB_REF="";
  @TAB_NBL=0;
  $NBP=0;
  if ($BASEDIR eq "MaBase")
  {
    foreach $name (@BASE)
    {
      &wanted ();
    }
  }
  else
  {
    foreach $dir (@BASE)
    {
      if (-d $dir)
      {   
        &find ($dir);
      }
    }
  }
  ## Remplir les tableau suivant la valeur de l'opérateur
  if ($OPE eq "PHRASE")
  {
    ## Opérateur PHRASE: on rempli le Tableau avec la recherche Trouvée
    if ($NBP > 0)
    {
      @TABF_TITRE=@TAB_TITRE;
      @TABF_REF=@TAB_REF;
      @TABF_NBL=@TAB_NBL;
      $NBPF=$NBP;
    }
  }
  elsif ($OPE eq "OU")
  {
    ## Opérateur OU: on fait une union entre la recherche précedente et l'actuelle
    $j=0;
    while ($j < $NBP)
    {
      $i=0;
      $trouve=0;
      while ($i<$NBPF)
      {
        if (@TABF_REF[$i] eq @TAB_REF[$j])
        {
          $trouve=1;
          @TABF_NBL[$i]+=@TAB_NBL[$j]
        }
        $i++;
      }
      if ($trouve==0)
      {
        @TABF_TITRE[$NBPF]=@TAB_TITRE[$j];
        @TABF_REF[$NBPF]=@TAB_REF[$j];
        @TABF_NBL[$NBPF]=@TAB_NBL[$j];
        $NBPF++;
      }
      $j++;
    }
  }
  else
  {
    ## Opérateur ET: on fait une intersection entre la recherche précedente et l'actuelle
    if ($NBMOTS==1)
    {
      @TABF_TITRE=@TAB_TITRE;
      @TABF_REF=@TAB_REF;
      @TABF_NBL=@TAB_NBL;
      $NBPF=$NBP;
    }
    else
    {
      @TABT_TITRE=@TABF_TITRE;
      @TABT_REF=@TABF_REF;
      @TABT_NBL=@TABF_NBL;
      $NBPT=$NBPF;
      @TABF_TITRE="";
      @TABF_REF="";
      @TABF_NBL="";
      $NBPF=0;
      $j=0;
      while ($j < $NBP)
      {
        $i=0;
        while ($i<$NBPT)
        {
          if (@TABT_REF[$i] eq @TAB_REF[$j])
          {
            @TABF_TITRE[$NBPF]=@TABT_TITRE[$i];
            @TABF_REF[$NBPF]=@TABT_REF[$i];
            @TABF_NBL[$NBPF]=@TABT_NBL[$i] + @TAB_NBL[$j];
            $NBPF++;
          }
          $i++;
        }
        $j++;
      }
    }
  }
}

## Afficher les résultats
if ($NBMAX>0 and $NBPF>=$NBMAX) 
{ 
  $NBPF=$NBMAX; 
  print "<TD>Maximum Atteint, veuillez afficner votre recherche.</TD></TR><TR>\n";
}
$TERMR=join(', ',@TB_TM) ;
print "<TD>Liste des $NBPF pages contenant ";
if  ($OPE eq "ET") {print "tous les mots : $TERMR<BR></TD>\n";}
elsif ($OPE eq "OU") {print "l'un des mots : $TERMR<BR></TD>\n";}
else {print "la chaine : $TERMR<BR></TD>\n";}
print "</TR>\n";
print "<TR><TD><UL>\n";

## Trier le tableau en recherche complète
if ($RECR eq "Non") { &trie_tab (); }

## afficher le tableau
&affich_tab ();

## Fermer la page HTML
print "</UL></TD></TR>\n";
print "<TR><TD><HR><CENTER><FONT SIZE=1><B><I>Search4LDP v$VERSION</I></B> -=-\n";
print "Copyright (c) 2001 - Philippe BOUSQUET -=-\n";
print "Licence: GNU GENERAL PUBLIC LICENSE</FONT><BR>\n";
print "</CENTER></TD></TR></TABLE></BODY></HTML>\n";

## Sous Fonctions
## Sub Wanted
sub wanted
{
  if ($name =~ /\.htm/i)
  {
    if ($NBP<$NBMAX or $NBMAX==0) { &findstr($name, $TERM); }
  }
}

## Sub findstr
sub findstr
{
  ## récup des paramètres
  my ($file,$term) = @_;
  ## nombre de ligne contenant la chaine
  $NBL=0;
  $NBLP=0;
  $i=0;
  $fd=0;
  $trv=0;
  $end=0;
  @TITRE="";
  ## recherche pour chaque ligne
  open (FILE,"$file");
  while ((not eof(FILE)) and (($fd != 2) or ($RECR eq "Non")))
  {
    $LINES=<FILE>;
    $NBLP++;
    chomp $LINES;
    if ($RECR eq "Non")
    {
      if ($LINES =~ /$TERM/i)
      {
        $NBL++;
      }
    }
    if ($fd==0)
    {
      if ($LINES =~ /TITLE/i)
      {
       if ($LINES !~ /TITLE=/i) {$fd=1; }
      }
    }
    if ($fd==1)
    {
      $TITRE[$i]=$LINES;
      if ($LINES =~ /\/TITLE/i) { $fd=2;}
      $i++;
    }
  }
  close (FILE);
  ## récup titre de la page
  $title = join('',@TITRE);
  ## substitution des < et >
  $title=~s/\>//g;
  @TITRE=split('\<',$title);
  $i=0;
  $fd=0;
  @TITRE2="";
  foreach $t (@TITRE)
  {
    if ($fd==0)
    {
      ## on trouve la borne <TITLE>
       if ($t =~ /TITLE/i)
       {
         if ($t !~ /TITLE=/i) {$fd=1; }
       }
    }
    if ($fd==1)
    {
      $TITRE2[$i]=$t;
      $i++;
      ## on trouve la borne </TITLE>
      if ($t =~ /\/TITLE/i) { $fd=2; }
    }
  }
  ## récup titre de la page
  $title = join('',@TITRE2);
  if ($title =~ /$TERM/i) { $NBL=$NBL+10; }
  if ($file =~ /$TERM/i) { $NBL=$NBL+5; }
  ## recherche OK
  if ($NBL >= 1)
  {
    $title=~s/\/TITLE//ig;
    $title=~s/TITLE//ig;
    $title=~s/\>//g;
    $title=~s/\<//g;
    $title=~s/\/HTML//ig;
    if ($title eq "") { $title=$file; }
    $TAB_TITRE[$NBP]=$title;
    $TAB_REF[$NBP]=$file;
    $TAB_NBL[$NBP]=$NBL;
    if (not ($ALIASSRC eq "")) { @TAB_TITRE[$NBP]=~s/$ALIASSRC/$ALIASDEST/ig; }
    if (not ($ALIASSRC eq "")) { @TAB_REF[$NBP]=~s/$ALIASSRC/$ALIASDEST/ig; }
    $NBP++;
  }
}

## Sub trie_tab
sub trie_tab
{
  $i=0;
  while ($i<$NBPF)
  {
    if ($TABF_NBL[$i+1]>$TABF_NBL[$i])
    {
      $MAX=$TABF_NBL[$i];
      $titre_t=$TABF_TITRE[$i];
      $ref_t=$TABF_REF[$i];
      $nbl_t=$TABF_NBL[$i];
      $TABF_TITRE[$i]=$TABF_TITRE[$i+1];
      $TABF_REF[$i]=$TABF_REF[$i+1];
      $TABF_NBL[$i]=$TABF_NBL[$i+1];
      $TABF_TITRE[$i+1]=$titre_t;
      $TABF_REF[$i+1]=$ref_t;
      $TABF_NBL[$i+1]=$nbl_t;
      $i=0;
    }
    else
    {
      $i++;
    }
  }
}

## Sub affich_tab
sub affich_tab
{
  $i=0;
  if ($NBMAX>0 and $NBPF>=$NBMAX) { $NBPF=$NBMAX; } 
  while ($i<$NBPF)
  {
    @TABF_NBL[$i]=@TABF_NBL[$i] / $NBMOTS;
    print ("<LI><A HREF=\"@TABF_REF[$i]\">@TABF_TITRE[$i]</A></LI>\n");
    $i++;
  }
}
