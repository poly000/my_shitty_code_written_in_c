#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define size 400

int main() {
	unsigned long long ullN=1;
	register unsigned long long j,i,*k;
	FILE *fiFilePointer=fopen("data.txt","r");
	if(fiFilePointer==0)
		return 1;
	for(;;) {
		if(fgetc(fiFilePointer)=='\n')
			ullN++;
		if(feof(fiFilePointer)) 
			break;
	}
	rewind(fiFilePointer);
	register char **r_cppPointer=(char **)malloc(sizeof(char *)*ullN);
	k=(unsigned long long *)malloc(sizeof(unsigned long long)*ullN);
	if(k==0)
		return 1;
	for(i=0; i<ullN; i++) {
		k[i]=0;
		*(r_cppPointer+i)=(char *)malloc(sizeof(char)*size);
		if(*(r_cppPointer+i)==0)
			return 1;
		fgets(*(r_cppPointer+i),size,fiFilePointer);
		if(ullN-i==1)
			strcat(*(r_cppPointer+i),"\n"); 
	}
	fclose(fiFilePointer);
	fiFilePointer=fopen("output.txt","w+");
	for(j=0; j<ullN; j++) {
		do {
			srand(time(0));
			i=(unsigned long long)rand()%ullN;
		} while(k[i]!=0);
		k[i]=1;
		fprintf(fiFilePointer,"%s",*(r_cppPointer+i));
	}
	fclose(fiFilePointer);
	return 0;
}
