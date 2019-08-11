/*   Author: poly000
 *   License: Anti 996 (MIT-like)
 */

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char cGetNu(time_t tTime){
  srand(tTime++);
  return rand()%6+1;
}

int main(void) {
  register time_t tTime = time(0);
  register int iType;
  do {
	system("cls");
    printf("\nResult: %d\nPress ENTER to continue, or any key else to quit.\n",cGetNu(tTime++));
    iType = getch();
  } while(iType == 0x0d);
  return 0;
}
