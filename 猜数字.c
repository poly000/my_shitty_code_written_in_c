/*   Author: poly000
 *   License: WTFPL
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maxp1 100001
#define max_wrong_times 30
int main()
{
    register unsigned long true_num,wronged_times;
    unsigned long guest_num;
    char yesno;
    goto b;
a:
    if (wronged_times <= max_wrong_times)
        fprintf(stderr,"You won as %lu wronged times only!\nPlay again? (y)\n",wronged_times);
    else
        fprintf(stderr,"You lost...\nTry again? (y)\n");
    getchar();
    yesno = getchar();
    if (yesno == 'Y' || yesno == 'y')
        goto b;
    else
        return 0;
b:
    srand(time(0));
    true_num = rand()%maxp1;
    wronged_times = 0;
c:
    fprintf(stderr,"Please type a number: ");
    scanf("%lu",&guest_num);
    if (guest_num == true_num)
        goto a;
    else
    {
        wronged_times++;
        if(guest_num > true_num)
            fprintf(stderr,"Too big!\n\n");
        else
            fprintf(stderr,"Too small!\n\n");
        goto c;
    }
}
