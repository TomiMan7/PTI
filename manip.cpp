#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

	srand (time(NULL));
	for(int i = 0; i < 10; i++)
	{
		int r = (int)(16.0 * rand() / (RAND_MAX + 1.0 ));
		cout<<setw(3)<<dec<<r<<
			setw(3)<<hex<<r<<endl;
	}

}

