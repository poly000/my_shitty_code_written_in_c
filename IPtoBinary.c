#include <stdio.h>
#include <stdlib.h>
int main() {
	int iNum[4];
	register int *iTemp,*iBinary,i=0,iTailNum,iDoubleNum,iTemp2,j,k;
	printf("Please type a IP address: ");
	scanf("%i.%i.%i.%i",iNum,&iNum[1],&iNum[2],&iNum[3]);
	for (; i<4; i++)
		if (iNum[i]>255||iNum[i]<0) {
			printf("ERROR: WRONG VALUE\n");
			return 1;
		}
	i=0;
	printf("\nBinary:\n");
a:
	iTemp=(int *)malloc(129*sizeof(int));
	if(iTemp==0)
		return 1;
	iBinary=(int *)malloc(8*sizeof(int));
	if(iBinary==0)
		return 1;
	for (j=0;j<129;j++)
		iTemp[j]=0;
	for (j=0;j<8;j++)
		iBinary[j]=0;
	iDoubleNum=1;
	iTemp2=iNum[i];
	do {
		iDoubleNum*=2;
		iTailNum=iTemp2%iDoubleNum;
		iTemp2-=iTailNum;
		iTemp[iTailNum]=1;
	} while(iDoubleNum<=iNum[i]);
	for (j=1,k=7; k>-1; k--,j*=2)
		if (iTemp[j])
			iBinary[k]=1;
	printf("%i%i%i%i%i%i%i%i",*iBinary,iBinary[1],iBinary[2],iBinary[3],iBinary[4],iBinary[5],iBinary[6],iBinary[7]);
	if (++i==4) {
		putchar('\n');
		return 0;
	} else
		putchar(' ');
	free(iTemp);
	free(iBinary);
	goto a;
}
