#include <stdio.h>
int main() {
	register unsigned long s=1;
	unsigned long x;
	printf("Please type a num: "); 
	scanf("%lu",&x);
	if(x>33) {
		puts("TOO BIG!");
		return 1;
	}
	if(x<3) {
		printf("%lu\n",x);
		return 0;
	}
	do {
		s*=x--;
	} while(x>1);
	printf("result: %lu\n",s);
	return 0;
}
