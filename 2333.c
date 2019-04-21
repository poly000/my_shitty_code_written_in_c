#include <stdio.h>

char a[1024][1024][1024];
int main() {
	int x=0,y=0,z=0;
a:
	a[x][y][z++]='2';
	a[x][y][z++]='3';
	a[x][y][z++]='3';
	a[x][y][z++]='3';
	if(z==1024) {
		z=0;
		if(++y==1024) {
			if(++x==1024) {
				scanf("%d",&x);
				return 0;
			} else {
				y=0;
				goto a;
			}
		}
	}
	goto a;
}
