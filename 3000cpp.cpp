#include <iostream>
#include <string.h>

using namespace std;

int evszam (int ev, int dd)
{

	while(ev<3000)
	{
	ev++;
	if(((ev%4) == 0) && (((ev%100) != 0) || ((ev%400) == 0 )))
		dd = ( dd + 2 ) % 7;	

	else
		dd = ( dd + 1 ) % 7;	
}

return dd;
}


int main()
{
int ev;
int honap;
int nap;
cout<<"Ev:";
cin>>ev;
cout<<"Honap:";
cin>>honap;
cout<<"Nap:";
cin>>nap;

tm time_in = {0, 0, 0, nap, honap -1, ev - 1900 };
time_t time_temp = mktime(&time_in);

const tm * time_out = localtime(&time_temp);
string s;

switch(evszam(ev, static_cast<int>(time_out->tm_wday) ) )
{
	case 1: s = "Hetfo";	break;
	case 2: s = "Kedd";	break;
	case 3: s = "Szerda";	break;
	case 4: s = "Csutortok";	break;
	case 5: s = "Pentek";	break;
	case 6: s = "Szombat";	break;
	case 0: s = "Vasarnap";	break;


}

cout<<"3000-ben a szulinapom "<< s <<" napra esik"<<endl;
}
