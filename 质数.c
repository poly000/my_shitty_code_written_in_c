/*   Author: poly000
 *   License: WTFPL
 */
#include <stdio.h>
#include <inttypes.h>

#define SHOW_TIME_USED
#define many 100000

#ifdef SHOW_TIME_USED
#include <time.h>
#endif

uint64_t num_[many] = { [0]=2 };

int main() {
#if defined(SHOW_TIME_USED)
	register clock_t start = clock();
#endif
	FILE *fp = fopen("output.txt","w+");
	if(fp == 0)
		return 1;
#if many == 1
	fprintf(fp,"2\n");
	fclose(fp);
	return 0;
#elif many>1
	fprintf(fp,"%10d",2);
	register uint64_t i=0,num=3,j=1,k=1;
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
				fprintf(fp,"%10" PRIu64 "\n",num);
				k = 0;
			} else
				fprintf(fp,"%10" PRIu64 " ",num);
		}
		i = 0;
		num += 2;
	} while(j < many);
	fflush(fp);
	fclose(fp);
#if defined(SHOW_TIME_USED)
	start = clock()-start;
	fprintf(stderr,"%lfs\n",(double)start/ (double)CLOCKS_PER_SEC);
#endif
	return 0;
#endif
}
