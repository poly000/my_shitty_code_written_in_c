/*   Author: poly000
 *   License: Anti 996 (MIT-like)
 */
#include <stdio.h>

int main() {
	register unsigned long long s = 1;
	unsigned long long x;
	fprintf(stderr,"Please type a num: ");
	scanf("%I64u",&x);
	if (x > 65) {
		fprintf(stderr,"TOO BIG!");
		return 1;
	}
	if (x < 3) {
		fprintf(stdout,"%I64u\n",x);
		return 0;
	}
	do
		s *= x--;
	while(x > 1);
	fprintf(stdout,"result: %I64u\n",s);
	return 0;
}
