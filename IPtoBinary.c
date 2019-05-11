#include <stdio.h>
int main() {
	int iNum[4],iTemp[4][129]= {0},iBinary[4][8]= {0};
	register int i=0,iTailNum,iDoubleNum,iTemp2,j,k;
	scanf("%i.%i.%i.%i",iNum,&iNum[1],&iNum[2],&iNum[3]);
	for (; i<4; i++)
		if (iNum[i]>255||iNum[i]<0) {
			printf("ERROR: WRONG VALUE\n");
			return 1;
		}
	i=0;
a:
	iDoubleNum=1;
	iTemp2=iNum[i];
	do {
		iDoubleNum*=2;
		iTailNum=iTemp2%iDoubleNum;
		iTemp2-=iTailNum;
		iTemp[i][iTailNum]=1;
	} while(iDoubleNum<=iNum[i]);
	for (j=1,k=7; k>-1; k--,j*=2)
		if (iTemp[i][j])
			iBinary[i][k]=1;
	printf("%i%i%i%i%i%i%i%i",iBinary[i][0],iBinary[i][1],iBinary[i][2],iBinary[i][3],iBinary[i][4],iBinary[i][5],iBinary[i][6],iBinary[i][7]);
	if (++i==4) {
		putchar('\n');
		return 0;
	} else
		putchar(' ');
	goto a;
}
