#include <stdio.h>
#include <stdlib.h>
int main(){
	register int *n=(int *)malloc(sizeof(int)*5),yuan,jiao,fen;
	if(n==0)
		return 1;
	double total;
	printf("Please type num of\n1 fen, 2 fen, 5 fen, 1 jiao, 5 jiao: \n\n");
	scanf("%d%d%d%d%d",n,n+1,n+2,n+3,n+4);
	total=0.01**n+0.02**(n+1)+0.05**(n+2)+0.1**(n+3)+0.5**(n+4);
	free(n);
	yuan=(int)total;
	fen=(int)(total*100)%10;
	jiao=(total-yuan-fen*0.01)*10;
	printf("\n\tTotal\r%.2lf\n",total);
	printf("\n%d yuan %d jiao %d fen\n",yuan,jiao,fen);
	return 0;
}

