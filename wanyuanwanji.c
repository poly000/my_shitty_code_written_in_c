#include <stdio.h>
#define num 10000 
int main() {
	register unsigned long x,y,z,n,max;
	printf("         x         y         z\n");
	x=1;
	max=(num-4)/7;
a:
	n=num-7*x;
	if(n%4==0) {
		y=n/4;
		z=num-x-y;
		printf("%10lu%10lu%10lu\n",x,y,z);
	}
	if(++x<max)
		goto a;
	return 0;
}
