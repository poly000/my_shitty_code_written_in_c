#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	unsigned long N;
	register unsigned long j,i,*k,o=0;
	FILE *fp;
	fprintf(stderr,"Please type how many numbers are there: ");
	fscanf(stdin,"%lu",&N);
	k=(unsigned long *)malloc(sizeof(unsigned long)*N);
	if(k==0)
		return 1;
	for(i=0;i<N;i++)
		k[i]=0;
	fp=fopen("output.txt","w+");
	for(j=0; j<N; j++) {
		do {
			srand(time(0));
			i=(unsigned long)rand()%N;
		} while(k[i]!=0);
		k[i]=1;
		fprintf(fp,"%5lu: %5lu\n",j+1,i+1);
	}
	free(k);
	fclose(fp);
	return 0; 
}

