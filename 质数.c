/*   Author: poly000
 *   License: WTFPL
 */
#include <stdio.h>
#define many 1000000
unsigned long long num_[many] = { [0]=2 };
int main() {
	FILE *fp = fopen("output.txt","w+");
	if(fp == 0)
		return 1;
#if many == 1
	fprintf(fp,"2\n");
	fclose(fp);
	return 0;
#elif many>1
	fprintf(fp,"%10d",2);
	register unsigned long long i=0,num=3,j=1,k=1;
	setvbuf(fp,NULL,_IOFBF,many);
	do {
		while(i<j) {
			if(num%num_[i] == 0)
				break;
			i++;
		}
		if(i == j) {
			num_[i] = num;
			j++;
			if(++k == 10) {
				fprintf(fp,"%10I64u\n",num);
				k = 0;
			} else
				fprintf(fp,"%10I64u",num);
		}
		i = 0;
		num += 2;
	} while(j < many);
	fflush(fp);
	fclose(fp);
	return 0;
#endif
}
