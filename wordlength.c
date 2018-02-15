#include <stdio.h>

int main()
{
int h = 0, n = 0x01;

	do
	   ++h;
	while(n<<=1);

printf("A szo hossza:%d\n",h);

return 0;
}
