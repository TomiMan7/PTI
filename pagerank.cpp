//#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

void print(double tomb[], int db)
{
	for(int i = 0; i < db; i++)
		//printf("PageRank[%d]: %lf\n",i,tomb[i]);
		cout<<"PageRank"<<"["<<i<<"]:\t"<<tomb[i]<<endl;
}

double distance(double PR[], double PRv[], int n)
{

double osszeg = 0.0;

	for(int i = 0; i < n; i++)
		osszeg += (PRv[i] - PR[i]) * (PRv[i] - PR[i]);

return sqrt(osszeg);
}

int main()
{

double L [4][4] = {
		{0.0, 0.0, 1.0 / 3.0, 0.0},
		{1.0, 1.0 / 2.0, 1.0 / 3.0, 1.0},
		{0.0, 1.0 / 2.0, 0.0, 0.0},
		{0.0, 0.0, 1.0 /3.0, 0.0}
		  };
double PR[4] = {0.0, 0.0, 0.0, 0.0};
double PRv[4] = {1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0};


for(;;)
{

	for(int i = 0; i < 4; i++)
	{
		PR[i] = 0.0;
			for(int j = 0; j < 4; j++)
				PR[i] += (L[i][j] * PRv[j]);

	}
	
	if (distance(PR,PRv, 4) < 0.0000000001)
		break;

	for(int i = 0; i < 4; i++)
		PRv[i] = PR[i];
}

print(PR, 4);

return 0;
}
