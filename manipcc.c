#include <stdlib.h>
#include <stdio.h>

int main()
{

	srand (time(NULL));
	for(int i = 0; i < 10; i++)
	{
		int r = (int)(16.0 * rand() / (RAND_MAX + 1.0 ));
		printf("%3d %3x\n", r, r);		
		
	}

}

