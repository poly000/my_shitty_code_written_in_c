#include <stdio.h>
int main() {
	unsigned long long x;
	fprintf(stderr,"Please type a num: ");
	scanf("%I64u",&x);
	fprintf(stderr,"result: ");
	if(x%2==0)
		printf("%I64u",(x+1)*(x/2));
	else
		printf("%I64u",x*(x/2)+x);
	return 0;
}
