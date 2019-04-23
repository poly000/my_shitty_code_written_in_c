#include <stdio.h>
int main(){
	register unsigned long x=3,i,n=2,amount=2;
	printf("%10d%10d",2,3);
a:
	i=3;
b:
	if(x%i==0){
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
	if(++amount==100)
		return 0;
	x+=2;
	goto a;
}
