#include <stdio.h>
int main(){
	double n1,n2;
	goto b;
a:
	printf("Smallest Num: %lf\n",n1);
b:
	scanf("%lf",&n1);
c:
	scanf("%lf",&n2);
	if(n2==0){
		goto a;
	}else{
		if(n2==0){
			goto a;
		}else{
			if(n2<n1){
				n1=n2;
			}
			goto c;
		}
	}
}
