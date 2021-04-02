/*   Author: poly000
 *   License: WTFPL
 */
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <math.h>
//#define SHOW_TIME_USED
#define many 10000000

#ifdef SHOW_TIME_USED
#include <time.h>
#endif

uint64_t num_[many] = { [0]=2 };

int main()
{
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
    register uint64_t num=3,N=1,k=1;
    setvbuf(fp,NULL,_IOFBF,many);
    {
        bool primer = true;
        register uint32_t temp,temp1;
        for (; N<many; num+=2) {
            temp=floor(sqrt(num));
            for (int i=0; (temp1=num_[i]) <= temp; i++) {
                if (num%temp1 == 0) {
                    primer = false;
                    break;
                }
            }
            if (primer == true) {
                num_[N] = num;
                N++;/*
                if(++k == 10)
                {
                    fprintf(fp,"%10" PRIu64 "\n",num);
                    k = 0;
                }
                else
                    fprintf(fp,"%10" PRIu64 " ",num);
            */}
            primer=true;
        }

    }

    fflush(fp);
    fclose(fp);
#if defined(SHOW_TIME_USED)
    start = clock()-start;
    fprintf(stderr,"%lfs\n",(double)start/ (double)CLOCKS_PER_SEC);
#endif
    return 0;
#endif
}
