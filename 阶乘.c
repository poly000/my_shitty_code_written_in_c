#include <stdio.h>
int main() {
	unsigned long s,x;
	scanf("%lu",&x);
	if(x>33){
		printf("TOO BIG!");
		return 1;
	}
	if(x<3) {
		printf("%lu\n",x);
		return 0;
	}
	s=x;
	do {
		s*=--x;
	} while(x>2);
	printf("%lu\n",s);
	return 0;
}
