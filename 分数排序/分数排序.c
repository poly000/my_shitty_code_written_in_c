#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct person {
	float grace;
	char *name;
} P;
int main() {
	P t,*p=(P *)malloc(sizeof(P)*3);
	if(p==0)
		return 1;
	char name[N][25]= {0};
	register int i,j;
	for(i=0; i<N; i++) {
		printf("Please type name %d: ",i);
		scanf("%s",name[i]);
		(p+i)->name=name[i];
		putchar('\n');
		printf("Please type grace %d: ",i);
		scanf("%f",&(p+i)->grace);
		putchar('\n');
	}
	for(j=1; j<N; j++) {
		i=j;
		while(i>0) {
			if((p+i)->grace>(p+i-1)->grace) {
				t=*(p+i-1);
				*(p+i-1)=*(p+i);
				*(p+i)=t;
			}
			i--;
		}
	}
	printf("Name%11crace\n\n",'G');
	for(i=0; i<N; i++)
		printf("%19.1f\r%s\n",(p+i)->grace,(p+i)->name);
	return 0;
}
