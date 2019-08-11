/*   Author: poly000
 *   License: Anti 996 (MIT-like)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
	float fGrace;
	char *cpName;
} per;

int main() {
	FILE *fipFilePointer;
	unsigned long long uI64N;
	fipFilePointer=fopen("data.txt","r");
	if(fipFilePointer==0)
		return 1;
	fscanf(fipFilePointer,"%I64u",&uI64N);
	per t,*p=(per *)malloc(sizeof(per)*uI64N);
	if(p==0)
		return 1;
	char cName[25];
	register unsigned long long i,j;
	for(i=0; i<uI64N; i++) {
		fscanf(fipFilePointer,"%s",cName);
		(p+i)->cpName=(char *)malloc(sizeof(char)*25);
		if((p+i)->cpName==0)
			return 1;
		strncpy((p+i)->cpName,cName,25);
		fscanf(fipFilePointer,"%f",&(p+i)->fGrace);
	}
	for(j=uI64N-1; j>0; j--) {
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
	fclose(fipFilePointer);
	fipFilePointer=fopen("output.txt","w+");
	if(fipFilePointer==0)
		return 1;
	fprintf(fipFilePointer,"Name\nGrace\n\n");
	for(i=0; i<uI64N; i++)
		fprintf(fipFilePointer,"%s\n%.1f\n\n",(p+i)->cpName,(p+i)->fGrace);
	fclose(fipFilePointer);
	return 0;
}
