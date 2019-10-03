/*   Author: poly000
 *   License: WTFPL
 */
#include <stdio.h>
#include <stdlib.h>
#define num_z 1024
#define num_y 1024
#define num_x 1024

int main() {
	register char *cpA = (char *)malloc(sizeof(char)*(num_x*num_y*num_z));
	if(cpA == 0)
		return 1;
	register int r_iX = 0,r_iY = 0,r_iZ = 0;
a:
	*(cpA+r_iX*num_y*num_z+r_iY*num_z+r_iZ++) = '2';
	*(cpA+r_iX*num_y*num_z+r_iY*num_z+r_iZ++) = '3';
	*(cpA+r_iX*num_y*num_z+r_iY*num_z+r_iZ++) = '3';
	*(cpA+r_iX*num_y*num_z+r_iY*num_z+r_iZ++) = '3';
	if (r_iZ == num_z) {
		r_iZ = 0;
		if (++r_iY == num_y) {
			r_iY = 0;
			if (++r_iX == num_x) {
				fprintf(stderr,"done.\n");
				free(cpA);
				getchar();
				return 0;
			}
			goto a;
		}
	}
	goto a;
}
