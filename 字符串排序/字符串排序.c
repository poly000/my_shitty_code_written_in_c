#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 400

int main() {
	unsigned long N;
	register unsigned long j,i,*k,l;
	FILE *fp=fopen("data.txt","r");
	if(fp==0)
		return 1;
	fscanf(fp,"%lu",&N);
	register char **p=(char **)malloc(sizeof(char *)*N); 
	k=(unsigned long *)malloc(sizeof(unsigned long)*N);
	if(k==0)
		return 1;
	for(i=0; i<N; i++) {
		k[i]=0;
		*(p+i)=(char *)malloc(sizeof(char)*size);
		if(*(p+i)==0)
			return 1;
		fscanf(fp,"%s",*(p+i));
	}
	fclose(fp);
	fp=fopen("output.txt","w+");
	l=time(0);
	for(j=0; j<N; j++) {
		do {
			srand(l++);
			i=(unsigned long)rand()%N;
		} while(k[i]!=0);
		k[i]=1;
		fprintf(fp,"%s\n",*(p+i));
	}
	fclose(fp);
	return 0;
}

