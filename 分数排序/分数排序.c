#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
	float fGrace;
	char *cpName;
} per;

int main() {
	FILE *fipFilePointer;
	unsigned long long ullN;
	fipFilePointer=fopen("data.txt","r");
	if(fipFilePointer==0)
		return 1;
	fscanf(fipFilePointer,"%llu",&ullN);
	per t,*p=(per *)malloc(sizeof(per)*ullN);
	if(p==0)
		return 1;
	char cName[25];
	register int i,j,k;
	for(i=0; i<ullN; i++) {
		fscanf(fipFilePointer,"%s",cName);
		k=strlen(cName)+1;
		(p+i)->cpName=(char *)malloc(sizeof(char)*k);
		if((p+i)->cpName==0)
			return 1;
		strncpy((p+i)->cpName,cName,k);
		fscanf(fipFilePointer,"%f",&(p+i)->fGrace);
	}
	for(j=ullN-1; j>0; j--) {
		i=j;
		while(i>0) {
			if((p+i)->fGrace>(p+i-1)->fGrace) {
				t=*(p+i-1);
				*(p+i-1)=*(p+i);
				*(p+i)=t;
			}
			i--;
		}
	}
	k=1;
	while(k!=0)
		k=fclose(fipFilePointer);
	fipFilePointer=fopen("output.txt","w+");
	if(fipFilePointer==0)
		return 1;
	fprintf(fipFilePointer,"Name\nGrace\n\n");
	for(i=0; i<ullN; i++)
		fprintf(fipFilePointer,"%s\n%.1f\n\n",(p+i)->cpName,(p+i)->fGrace);
	k=1;
	while(k!=0)
		k=fclose(fipFilePointer);
	return 0;
}
