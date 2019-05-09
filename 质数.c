#include <stdio.h>
#define many 100000 
unsigned long num_[many]= {2};
int main() {
#if many==1
	printf("2\n");
	return 0;
#elif many>1
	printf("%10d",2);
	register unsigned long i=0,num=3,j=1,k=1;
	do {
		while(i<j) {
			if(num%num_[i]==0)
				break;
			i++;
		}
		if(i==j) {
			num_[i]=num;
			j++;
			if(++k==10) {
				printf("%10lu\n",num);
				k=0;
			} else
				printf("%10lu",num);
		}
		i=0;
		num+=2;
	} while(j<many);
	return 0;
#endif
}
