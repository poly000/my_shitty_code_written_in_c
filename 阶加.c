#include <stdio.h>
int main() {
	unsigned long x;
	fprintf(stderr,"Please type a num: "); 
	scanf("%lu",&x);
	fprintf(stderr,"result: ");
	if(x%2==0)
		fprintf(stdout,"%lu\n",(x+1)*(x/2));
	else
		fprintf(stdout,"%lu\n",x*(x/2)+x);
	return 0;
} 
