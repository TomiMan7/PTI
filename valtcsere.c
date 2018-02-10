#include <stdio.h>

int main()
{

int a = 7, b = 4;

printf("a:%d  b:%d\n",a,b);

a ^= b;

b ^= a;

a ^= b;

printf("a:%d  b:%d\n",a,b);

return 0;
}
