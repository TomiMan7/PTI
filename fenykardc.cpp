#include <iostream>
#include <fstream> //fajlkezelesehez szukseges
#include <vector>
#include <algorithm> //erase hasznalata
#include <unistd.h> //chdri hasznalata
#include <fstream>

#define ERASE temp.erase (remove(temp.begin(), temp.end(), '"'), temp.end() );

using namespace std;

class fenykard
{
public:
  vector<string> nevek; //emberkek neve
  vector<string> nev; //egyes feladathoz tartozo nev
  vector<string> feladat; //minden feladatot tartalmaz ebbol szurjuk majd a prog1eseket
  vector<string> feladatIdeje; //feladtok ideje
  vector<string> vegso_nev; //nem 0 ponttal rendelkezo emberek neve
  vector<int> vegso_pontok; //az emberek pontjai
  string keresettnev;
  string temp;
  string fajl_nev;
  ifstream fajlnev;
  string home = "/home/tomiman/prog1/jedi_sajat";
  string propsfajl;  
  int pontok = 0; 
//   ifstream fajlnev;
  ifstream props;
  
  
void emberek_beolvasasa( string database ) //mindenkinek a neve egyszer fog szerepelni a nev vectorban
{
    ifstream file( database ); 
 if( !file.is_open() )
  {
    cout<< "Nem sikerult a fajlt megnyitni(emberek_beolvasasa)"<<endl;
    exit;
  }
  
while( file.good() )
  {  
      getline(file,temp,',');
      ERASE; //a nevek/feladatok " " koze vannak zarva ezek leszedese
      
    if(find(nevek.begin(), nevek.end(), temp) != nevek.end() )
	{
	 getline(file,temp,',');
	 getline(file,temp,'\n');
	 continue; 
	}

      nevek.push_back(temp);
      getline(file,temp,',');
      getline(file,temp,'\n');
  }  
    
// for(int i = 0; i < nevek.size(); i++ ) //kiirja a neveket
//   cout<<nevek[i]<<endl;
     
file.close();
feladatok_beolvasasa(database);

}

void feladatok_beolvasasa( string database )
{    
ifstream file( database ); 
        
if( !file.is_open() )
  {
    cout<< "Nem sikerult a fajlt megnyitni(feladatok_beolvasasa"<<endl;
    exit;
  }  
  
while( file.good() )
  {  
       getline(file,temp,',');
       ERASE; //a nevek/feladatok " " koze vannak zarva ezek leszedese 
       nev.push_back(temp);
	
       getline(file,temp,',');
       ERASE;
       feladat.push_back(temp);     
      
       getline(file,temp,'\n');
       ERASE;
       feladatIdeje.push_back(temp);//idobelyeg kiszedese mint utolso oszlop    
      
  }
  file.close();
  
//   for(int i = 0; i < nev.size(); i++)
//     cout<<nev[i]<<"\t"<<feladat[i]<<"\t"<<endl;
  
  pontok_kiszamitasa( /*vector<string> nevek, vector<string> nev, vector<string> feladat */);
  
  
  };

void pontok_kiszamitasa( /*vector<string> nevek, vector<string> nev, vector<string> feladat*/ )
{
  
  for(int i = 0; i < nevek.size(); i++)
  {
    for(int j = 0; j < nev.size(); j++) //osszes bejegyzes
    {
      if(nevek[i] == nev[j])
      {
	chdir(home.c_str() );
	chdir(feladat[ j ].c_str());
	system("ls > fajlnev.txt");
//        system("pwd");
  
	fajlnev.open("fajlnev.txt");
  
	while(fajlnev.good() )
	  {
	    getline(fajlnev,fajl_nev,'\n');
    
	    if(fajl_nev.find(".props") != std::string::npos )
	    {
	      propsfajl = fajl_nev;
//            cout<<fajl_nev<<endl;
	      props.open( fajl_nev.c_str() );
	    }
	  }

while(props.good() ) //props falj megniytasa es a pontok beolvasasa
{
  getline(props,temp,'\n');
//   cout<<temp<<endl;
  for(int j = 0; j < temp.size(); j++)
    {    
      if( isdigit( temp[j] ) )
      {		
	 pontok += (temp[j] - 48);
	  //pontok += atoi(temp[i].c_str() );
      }
    } 
}
    system("rm fajlnev.txt");
     fajlnev.close();
     props.close();
    }
  }
  
  if(pontok != 0)
  {
//       cout<<"\n"<<nevek[i]<<" pontjai: "<<pontok<<endl;
    vegso_nev.push_back(nevek[i]);
    vegso_pontok.push_back(pontok);    
  }
   pontok = 0;  
 }
pontok_rendezese();
}

void pontok_rendezese()
{
  int temp1;
  string temp2;
  
  for(int i = 0; i < vegso_pontok.size(); i++)
  {
    for(int j = i; j < vegso_pontok.size(); j++)
    {
      if(vegso_pontok[i] < vegso_pontok[j] )
      {
	temp1 = vegso_pontok[i];
	vegso_pontok[i] = vegso_pontok[j];
	vegso_pontok[j] = temp1;
	
	temp2 = vegso_nev[i];
	vegso_nev[i] = vegso_nev[j];
	vegso_nev[j] = temp2;
      }
    }
  }

  for(int i = 0; i < vegso_pontok.size(); i++)
  {
    cout<<vegso_nev[i]<<" pontjai:"<<vegso_pontok[i]<<endl<<endl;
  } 
}
};

int main(int argc, char* argv[] )
{
  fenykard ember;
  string database = argv[1];
  ember.emberek_beolvasasa(database);
}