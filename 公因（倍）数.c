/*   Author: poly000
 *   License: WTFPL
 */
#include <stdio.h>
int main(void)
{
    unsigned long long num0,num1,m,n,o;
    fprintf(stderr,"Please type num1 & num2: \n");
    scanf("%I64u%I64u",&num0,&num1);
    if(num0 < num1)
    {
        m = num0;
        n = num1;
    }
    else
    {
        n = num0;
        m = num1;
    }
    while ((o = m%n) != 0)
    {
        m = n;
        n = o;
    }
    fprintf(stdout,"%I64u %I64u",n,num0/n*num1);
    return 0;
}
