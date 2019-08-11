/*   Author: poly000
 *   License: Anti 996 (MIT-like)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char cGetNu(time_t tTime){
  srand(tTime++);
  return rand()%6+1;
}

int main(void) {
  time_t tTime = time(0);
  register int iType;
  printf("Press any key to start: ");
  getchar();
  do {
    printf("\nReslut: %d\nPress ENTER to continue, or any key else to quit.\n",cGetNu(tTime++));
    iType = getchar();
  } while(iType=='\n');
  return 0;
}
