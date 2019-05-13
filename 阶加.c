#include <stdio.h>
int main() {
	unsigned long x;
	scanf("%lu",&x);
	if(x%2==0)
		printf("%lu\n",(x+1)*(x/2));
	else
		printf("%lu\n",x*(x/2)+x);
	return 0;
} 
