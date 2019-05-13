#include <stdio.h>
#define num 33
int main() {
	register unsigned long s=1,x=num;
#if num>33
	puts("TOO BIG!");
	return 1;
#else
	if(x<3) {
		printf("%lu\n",x);
		return 0;
	}
	do {
		s*=x--;
	} while(x>1);
	printf("%lu\n",s);
	return 0;
#endif
}
