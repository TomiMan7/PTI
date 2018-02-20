#include <iostream>

using namespace std;

int main()
{
int h = 0, n = 0x01;

	do
	   ++h;
	while(n<<=1);
	
cout<<"A szo hossza: "<<h<<endl;
	
return 0;
}
