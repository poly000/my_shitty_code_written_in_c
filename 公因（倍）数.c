#include <stdio.h>
#define num1 6
#define num2 3
int main() {
#if num1<num2
	register unsigned long m=num1,n=num2,o;
#else
	register unsigned long n=num1,m=num2,o;
#endif
a:
	o=m%n;
	if(o) {
		m=n;
		n=o;
		goto a;
	}
	printf("%lu %lu",n,num1/n*num2);
	return 0;
}
