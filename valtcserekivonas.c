#include <stdio.h>

int main()
{
int a = 7, b = 4;

printf("a:%d b:%d\n\n",a,b);

a = a - b;

b = a + b;

a = b - a;

printf("a:%d b:%d\n",a,b);

return 0;

}
