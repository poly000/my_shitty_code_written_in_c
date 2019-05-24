#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 400

int main() {
	unsigned long long N;
	register unsigned long long j,i,*k,l;
	FILE *fp=fopen("data.txt","r");
	if(fp==0)
		return 1;
	fscanf(fp,"%llu",&N);
	register char **p=(char **)malloc(sizeof(char *)*N); 
	k=(unsigned long long *)malloc(sizeof(unsigned long long)*N);
	if(k==0)
		return 1;
	fseek(fp,1L,1);
	for(i=0; i<N; i++) {
		k[i]=0;
		*(p+i)=(char *)malloc(sizeof(char)*size);
		if(*(p+i)==0)
			return 1;
		fgets(*(p+i),size,fp);
	}
	fclose(fp);
	fp=fopen("output.txt","w+");
	l=time(0);
	for(j=0; j<N; j++) {
		do {
			srand(l++);
			i=(unsigned long long)rand()%N;
		} while(k[i]!=0);
		k[i]=1;
		fprintf(fp,"%s",*(p+i));
	}
	fclose(fp);
	return 0;
}

