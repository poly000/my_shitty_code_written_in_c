/*   Author: poly000
 *   License: WTFPL
 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    unsigned int iNum[4];
    register unsigned char iDouble,i,j;
    scanf("%u.%u.%u.%u",iNum,iNum+1,iNum+2,iNum+3);
    for(i=0; i<4; i++)
    {
        iDouble = 128;
        for (j=0; j<8; j++)
        {
            if ((*(iNum+i)&iDouble) == iDouble)
                putchar('1');
            else
                putchar('0');
            iDouble >>= 1;
        }
        putchar(' ');
    }
    putchar('\n');
    return 0;
}
