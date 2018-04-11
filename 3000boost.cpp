#include <iostream>
#include <boost/date_time.hpp>
#include <string.h>

using namespace std;

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

boost::gregorian::date dateObj {ev,honap,nap};
int plus;
plus = 3000 - ev;
boost::gregorian::years yearsObj(plus);
dateObj = dateObj + yearsObj;

cout<<dateObj<<endl;
string s;
switch(dateObj.day_of_week() )
{	
	case boost::date_time::Monday: s="Hetfo";break;
	case boost::date_time::Tuesday: s="Kedd";break;
	case boost::date_time::Wednesday: s="Szerda";break;
	case boost::date_time::Thursday: s="Csutortok";break;
	case boost::date_time::Friday: s="Pentek";break;
	case boost::date_time::Saturday: s="Szombat";break;
	case boost::date_time::Sunday: s="Vasarnap";break;
}

cout<<"3000-ben a szulinapom "<< s <<" napra esik"<<endl;
}
