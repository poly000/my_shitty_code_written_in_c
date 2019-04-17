#include <stdio.h>
int main(){
	register unsigned long x=3,i,n=1,amount=1;
	printf("         2");
a:
	i=3;
b:
	if(x/i*i==x){
		x+=2;
		goto a;
	}
	i+=2;
	if(i<x/2)
		goto b;
c:
	if(i>=x/2){
		if(++n==10){
			printf("%10lu\n",x);
			n=0;
		}else
			printf("%10lu",x);
	}
	if(++amount==1000) //求得质数的量
		return 0;
	x+=2;
	goto a;
}
