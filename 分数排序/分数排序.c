#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
	float grace;
	char *name;
} P;

int main() {
	FILE *fp;
	unsigned long N;
	fp=fopen("data.txt","r");
	if(fp==0)
		return 1;
	fscanf(fp,"%lu",&N);
	P t,*p=(P *)malloc(sizeof(P)*N);
	if(p==0)
		return 1;
	char name[25];
	register int i,j,k;
	for(i=0; i<N; i++) {
		fscanf(fp,"%s",name);
		k=strlen(name)+1;
		(p+i)->name=(char *)malloc(sizeof(char)*k);
		if((p+i)->name==0)
			return 1;
		strncpy((p+i)->name,name,k);
		fscanf(fp,"%f",&(p+i)->grace);
	}
	for(j=N-1; j>0; j--) {
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
	k=1;
	while(k!=0)
		k=fclose(fp);
	fp=fopen("output.txt","w+");
	if(fp==0)
		return 1;
	fprintf(fp,"Name\nGrace\n\n");
	for(i=0; i<N; i++)
		fprintf(fp,"%s\n%.1f\n\n",(p+i)->name,(p+i)->grace);
	k=1;
	while(k!=0)
		k=fclose(fp);
	return 0;
}
