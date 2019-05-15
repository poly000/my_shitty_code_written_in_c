#include <stdio.h>
int main() {
	int num[2],m,n,o;
	fprintf(stderr,"Please type num1 & num2: ");
	scanf("%i%i",num,num+1);
	if(*num<*(num+1)) {
		m=*num;
		n=*(num+1);
	}else {
		n=*num;
		m=*(num+1);
	}
a:
	o=m%n;
	if(o) {
		m=n;
		n=o;
		goto a;
	}
	fprintf(stdout,"%lu %lu",n,*num/n**(num+1));
	return 0;
}
