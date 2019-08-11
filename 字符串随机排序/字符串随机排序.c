/*   Author: poly000
 *   License: Anti 996 (MIT-like)
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define size 400

int main() {
	unsigned long long ullN=1;
	register unsigned long long j, i, _time = (unsigned long long)time(0);
	char *k;
	FILE *fiFilePointer=fopen("data.txt","r");
	if (fiFilePointer == 0)
		return 1;
	for (;;) {
		if (fgetc(fiFilePointer) == '\n')
			ullN++;
		if (feof(fiFilePointer))
			break;
	}
	rewind(fiFilePointer);
	register char **r_cppPointer = (char **)malloc(sizeof(char *)*ullN);
	k = (char *)malloc(sizeof(char)*ullN);
	if (k == (char *) 0)
		return 1;
	for (i=0; i<ullN; i++) {
		k[i] = (char) 0;
		*(r_cppPointer+i) = (char *)malloc(sizeof(char)*size);
		if (*(r_cppPointer+i) == 0)
			return 1;
		fgets(*(r_cppPointer+i),size,fiFilePointer);
	}
	strcat(*(r_cppPointer+--i),"\n");
	fclose(fiFilePointer);
	fiFilePointer = fopen("output.txt","w+");
	for(j=0; j<ullN; j++) {
		do {
			srand(++_time);
			i = (unsigned long long)rand()%ullN;
		} while(k[i] != (char) 0);
		k[i] = (char) 1;
		fprintf(fiFilePointer,"%s",*(r_cppPointer+i));
	}
	fclose(fiFilePointer);
	return 0;
}
