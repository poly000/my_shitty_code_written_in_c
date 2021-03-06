/*   Author: poly000
 *   License: WTFPL
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    unsigned long long N;
    register unsigned long long j, i, _time = (unsigned long long)time(0);
    char *k;
    FILE *fp;
    fprintf(stderr,"Please type how many numbers are there: ");
    fscanf(stdin,"%I64u",&N);
    k = (char *)malloc(sizeof(char)*N);
    if (k == 0)
        return 1;
    for (i=0; i<N; i++)
        k[i] = (char) 0;
    fp = fopen("output.txt","w+");
    for(j=0; j<N; j++)
    {
        do
        {
            srand(++_time);
            i = (unsigned long long)rand()%N;
        }
        while(k[i] != (char) 0);
        k[i] = (char) 1;
        fprintf(fp,"%5I64u: %5I64u\n",j+1,i+1);
    }
    free(k);
    fclose(fp);
    return 0;
}
