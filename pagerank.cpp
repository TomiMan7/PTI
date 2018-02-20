//#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void print(vector<double>tomb, int db)
{
	for(double s : tomb)
		//printf("PageRank[%d]: %lf\n",i,tomb[i]);
		cout<<"PageRank"<<"["<<s<<"]:\t"<<endl;
}

//double distance(double PR[], double PRv[], int n)
double distance(vector<double> PR, vector<double> PRv, int n)
{

double osszeg = 0.0;

	for(int i = 0; i < n; i++)
		osszeg += (PRv[i] - PR[i]) * (PRv[i] - PR[i]);

return sqrt(osszeg);
}

int main()
{

vector<vector<double>> L = {
		{0.0, 0.0, 1.0 / 3.0, 0.0},
		{1.0, 1.0 / 2.0, 1.0 / 3.0, 1.0},
		{0.0, 1.0 / 2.0, 0.0, 0.0},
		{0.0, 0.0, 1.0 /3.0, 0.0}
		  };

//double PR[4] = {0.0, 0.0, 0.0, 0.0};
//double PRv[4] = {1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0};

vector<double> PR = {0.0, 0.0, 0.0, 0.0};
vector<double> PRv = {1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0};

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
