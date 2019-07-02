#include <stdio.h>
#include <stdlib.h>
int main() {
	int iNum[4];
	register unsigned short iDouble,i,j;
	scanf("%u.%u.%u.%u",iNum,iNum+1,iNum+2,iNum+3);
	for(i=0; i<4; i++){
		if (*(iNum+i) > 255){
			printf("\n%u ERROR: BAD NUM\n",i+1);
			return 1;
		}
		iDouble = 256;
		for (j=0; j<8; j++){
			iDouble >>= 1;
			if ((*(iNum+i)&iDouble) == iDouble)
				putchar('1');
			else
				putchar('0');
		}
		putchar(' ');
	}
	putchar('\b\n');
	return 0;
}
