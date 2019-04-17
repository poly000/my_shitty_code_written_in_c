#include <stdio.h>
int main(){
	register int x,y,z,n;
	printf("    x    y    z\n");
	for(x=1;x<142;x++){
		n=1000-7*x;
		if(n%4==0){
			y=n/4;
			z=1000-x-y;
			printf("%5d%5d%5d\n",x,y,z);
		}
	}
	return 0;
}
