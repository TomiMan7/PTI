#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(int argc, char* argv[])
{
int szo 	= 0;
int sor 	= 0;
int betu 	= 0;
int szam 	= 0;
int specko 	= 0;
int sum;

ifstream file(argv[1] );

char input;

while(file.get(input) )
{
	if(input ==' ' || input =='\n' || input =='\t')
	szo++;
	
	if(input =='\n')
	sor++;

	if(isalpha(input) )
	betu++;

	if(isdigit(input) )
	szam++;

	if(ispunct(input) )
	specko++;
}

sum = betu + szam + specko;

cout<<"Ebben a fajlban ennyi szo van: "<< szo <<endl;
cout<<"Ebben a fajlban ennyi sor van: "<< sor <<endl;
cout<<"Ebben a fajlban ennyi betu van: "<< betu<<endl;
cout<<"Ebben a fajlban ennyi szam van: "<<szam<<endl;
cout<<"Ebben a fajlban ennyi specialis karakter van: "<< specko<<endl;

}
