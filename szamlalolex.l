%{
#include <stdio.h>
int szo 	= 0;
int sor 	= 0;
int kbetu 	= 0;
int nbetu	= 0;
int szam 	= 0;
int specko 	= 0;
int sum;
%}
%%

\n { sor++; szo++;}
[\t ' '] szo++;
[A-Z] nbetu++;
[a-z] kbetu++;
[0-9] szam++;
. specko++;
%%

main(void)
{
yyin= fopen("szamlalo.cpp", "r" );
yylex();
sum = specko + kbetu + nbetu + szam;
printf("Ebben a fajlban ennyi sor van %d", sor);
printf("\nEbben a fajlban ennyi szo van %d", szo);
printf("\nEbben a fajlban ennyi betu van %d", nbetu+kbetu);
printf("\nEbben a fajlban ennyi szam van %d", szam);
printf("\nEbben a fajlban ennyi specialis karakter van %d", specko);
printf("\nEbben a fajlban osszesen ennyi karakter van %d\n", sum);
}

int yywrap()
{
return(1);
}
