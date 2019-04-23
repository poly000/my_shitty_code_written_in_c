#include <stdio.h>
int main(){
	register unsigned long m,n,o;
	unsigned long m_,n_;
	scanf("%lu%lu",&m_,&n_);
	m=m_;
	n=n_;
	if(m>n){
		o=m;
		m=n;
		n=o;
	}
	a:
		o=m%n;
		if(o){
		m=n;
		n=o;
		goto a;
	}
	printf("%lu %lu",n,m_/n*n_);
	return 0;
}
