#include <stdio.h>
int main() {
	register unsigned long s=1;
	unsigned long x;
	fprintf(stderr,"Please type a num: "); 
	scanf("%lu",&x);
	if(x>33) {
		fprintf(stderr,"TOO BIG!");
		return 1;
	}
	if(x<3) {
		fprintf(stdout,"%lu\n",x);
		return 0;
	}
	do {
		s*=x--;
	} while(x>1);
	fprintf(stdout,"result: %lu\n",s);
	return 0;
}
