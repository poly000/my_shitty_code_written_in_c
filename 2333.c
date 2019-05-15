#include <stdio.h>
#include <stdlib.h>
#define num_z 1024
#define num_y 1024
#define num_x 1024

int main() {
	register char *a=(char *)malloc(sizeof(char)*(num_x*num_y*num_z));
	if(a==0)
		return 1;
	register int x=0,y=0,z=0;
a:
	*(a+x*num_y*num_z+y*num_z+z++)='2';
	*(a+x*num_y*num_z+y*num_z+z++)='3';
	*(a+x*num_y*num_z+y*num_z+z++)='3';
	*(a+x*num_y*num_z+y*num_z+z++)='3';
	if(z==num_z) {
		z=0;
		if(++y==num_y) {
			y=0;
			if(++x==num_x) {
				fprintf(stderr,"done.\n");
				getchar();
				return 0;
			}
			goto a;
		}
	}
	goto a;
}
