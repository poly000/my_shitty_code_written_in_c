#include <stdio.h>
int main() {
	unsigned long long x;
	fprintf(stderr,"Please type a num: "); 
	scanf("%llu",&x);
	fprintf(stderr,"result: ");
	if(x%2==0)
		fprintf(stdout,"%llu\n",(x+1)*(x/2));
	else
		fprintf(stdout,"%llu\n",x*(x/2)+x);
	return 0;
} 
