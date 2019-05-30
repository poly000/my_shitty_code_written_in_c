#include <stdio.h>
#include <stdlib.h>
int main() {
	int iNum[4];
	register int iDouble,i,j;
	scanf("%d.%d.%d.%d",iNum,iNum+1,iNum+2,iNum+3);
	for(i=0; i<4; i++){
		if(*(iNum+i)>255)
			return 0;
		iDouble=256;
		for(j=0; j<8; j++){
			iDouble>>=1;
			if((*(iNum+i)&iDouble)==iDouble)
				putchar('1');
			else
				putchar('0');
		}
		if(i<3)
			putchar(' ');
	}
	putchar('\n');
	return 0;
}
