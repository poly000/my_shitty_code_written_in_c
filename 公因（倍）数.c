/*   Author: poly000
 *   License: Anti 996 (MIT-like)
 */
#include <stdio.h>
int main() {
	unsigned long long num[2],m,n,o;
	fprintf(stderr,"Please type num1 & num2: ");
	scanf("%I64u%I64u",num,num+1);
	if(*num<*(num+1)) {
		m = *num;
		n = *(num+1);
	} else {
		n = *num;
		m = *(num+1);
	}
a:
	o = m%n;
	if(o != 0) {
		m = n;
		n = o;
		goto a;
	}
	fprintf(stdout,"%I64u %I64u",n,*num/n**(num+1));
	return 0;
}
