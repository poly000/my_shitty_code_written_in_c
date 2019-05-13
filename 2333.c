#include <stdio.h>
#define num_x 1024 
#define num_y 1024
#define num_z 1024

char a[num_x][num_y][num_z];
int main() {
	register int x=0,y=0,z=0;
a:
	a[x][y][z++]='2';
	a[x][y][z++]='3';
	a[x][y][z++]='3';
	a[x][y][z++]='3';
	if(z==num_z) {
		z=0;
		if(++y==num_y) {
			if(++x==num_x) {
				printf("done.\n");
				getchar();
				return 0;
			} else {
				y=0;
				goto a;
			}
		}
	}
	goto a;
}
