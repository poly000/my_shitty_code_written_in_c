#include <stdio.h>
int main() {
	unsigned long x;
	printf("Please type a num: "); 
	scanf("%lu",&x);
	printf("result: ");
	if(x%2==0)
		printf("%lu\n",(x+1)*(x/2));
	else
		printf("%lu\n",x*(x/2)+x);
	return 0;
} 
