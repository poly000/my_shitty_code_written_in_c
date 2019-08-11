/*   Author: poly000
 *   License: Anti 996 (MIT-like)
 */
#include <stdio.h>
int main(int argc, char **argv){
  if (argc != 2){
    printf("Usage: %s HH\n code 1: invailed argments\n code 2: invailed hex\n",*argv);
    return 1;
  }
  int iA = **(argv+1), iB = *(*(argv+1)+1);
  if ('0' <= iA && iA <= '9')
    iA -= '0';
  else
    if ('A' <= iA && iA <= 'F')
      iA -= '7';
    else
      if ('a' <= iA && iA <= 'f')
        iA -= 'W';
      else
        return 2;
  if ('0' <= iB && iB <= '9')
    iB -= '0';
  else
    if ('A' <= iB && iB <= 'F')
      iB -= '7';
    else
      if ('a' <= iB && iB <= 'f')
        iB -= 'W';
      else
        return 2;
  printf("%i",(iA<<4)+iB);
  return 0;
}
