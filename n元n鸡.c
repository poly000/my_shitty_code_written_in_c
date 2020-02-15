/*   Author: poly000
 *   License: WTFPL
 */
#include <stdio.h>

int main(){
	register int x,y,z,n;
	register int i = 0;
	int num;
	fprintf(stderr,"Please type num: ");
	scanf("%i",&num);
	if (num%4 != 0 || num < 32){
		fprintf(stderr,"%d is not able",num);
		return 1;
	}
	n = (num/4-1)/7;do {
		x = ++i*4;
		y = (num-7*x)/4;
		z = num-x-y;
		fprintf(stdout,"%6d cocks, %6d hens, %6d chicks\n",x,y,z);
	} while(i != n);
	return 0;
}
