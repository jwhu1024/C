#include <stdio.h>
int add(int x, int y)
{
    return x+y;
}
 
int sub(int x, int y)
{
    return x-y;
}
 
int calc(int (*pfunc)(int, int), int x, int y)
{
   return pfunc(x, y);
}
 
int main(void)
{
 
    printf("sum = %d\n", calc(add, 4, 2));
    printf("dif = %d\n", calc(sub, 4, 2));
	
	system("PAUSE");
    return 0;
}