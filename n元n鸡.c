#include <stdio.h>
#define num 100
int main(){
	register int x,y,z,n,i=0;
	if(num%4!=0||num<32){
		printf("%d is not able",num);
		return 1;
	}
	n=(num/4-1)/7;
a:
	x=++i*4;
	y=(num-7*x)/4;
	z=num-x-y;
	printf("%6d cock(s), %6d hen(s), %6d chick(s)\n",x,y,z);
	if(i==n)
		return 0;
	else
		goto a;
}
