/*   Author: poly000
 *   License: WTFPL
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc == 1||strcmp(*(argv+1),"-h") == 0||strcmp(*(argv+1),"--help") == 0)
    {
        char *cpTmp = *argv,*cp_Last = 0;
        while (*(cpTmp) != 0)
        {
            if (*(cpTmp++) == '/'||*(cpTmp++) == '\\')
                cp_Last = cpTmp;
        }
        printf("Usage:\n %s [Image] [Archive] > [Outfile]\n %s [FILE]...\n",cp_Last,cp_Last);
    }
    int iNum = argc-1;
    long lFileSize;
    uint8_t **i8Tmp = (uint8_t **)malloc(sizeof(uint8_t *)*iNum);
    FILE **fipFilp = (FILE **)malloc(sizeof(FILE *)*iNum);
    for (int i=0; i<iNum; i++)
    {
        *(fipFilp+i) = fopen(*(argv+i+1),"rb");
        if (*(fipFilp+i) == 0)
        {
            fprintf(stderr,"can't read file:\n%s\n",*(argv+i+1));
            continue;
        }
        fseek(*(fipFilp+i),0L,2);
        lFileSize = ftell(*(fipFilp+i));
        rewind(*(fipFilp+i));
        *(i8Tmp+i) = (uint8_t *)malloc(sizeof(uint8_t)*lFileSize);
        fread((void *)*(i8Tmp+i),sizeof(uint8_t),lFileSize,*(fipFilp+i));
        if(fclose(*(fipFilp+i)) != 0)
        {
            fprintf(stderr,"can't close file:\n%s\n",*(argv+i+1));
        }
        for (int j=0; j<lFileSize; j++)
        {
            putchar(0xa3 ^ i8Tmp[i][j]);
        }
    }
    return 0;
}
