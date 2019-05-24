#include <stdio.h>

int main() {
	register unsigned long long s=1;
	unsigned long long x;
	fprintf(stderr,"Please type a num: "); 
	scanf("%llu",&x);
	if(x>65) {
		fprintf(stderr,"TOO BIG!");
		return 1;
	}
	if(x<3) {
		fprintf(stdout,"%llu\n",x);
		return 0;
	}
	do {
		s*=x--;
	} while(x>1);
	fprintf(stdout,"result: %llu\n",s);
	return 0;
}
