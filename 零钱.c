#include <stdio.h>
#include <stdlib.h>
int main(){
	int *n=malloc(sizeof(int)*5);
	if(n==0)
		return 1; 
	register int yuan,jiao,fen;
	double total;
	scanf("%d%d%d%d%d",n,n+1,n+2,n+3,n+4);
	total=0.01**n+0.02**(n+1)+0.05**(n+2)+0.1**(n+3)+0.5**(n+4);
	free(n);
	yuan=(int)total;
	fen=(int)(total*100)%10;
	jiao=(total-yuan-fen*0.01)*10;
	printf("\t%.2lf Total\n",total);
	printf("\t\t%d yuan %d jiao %d fen\n",yuan,jiao,fen);
	return 0;
}

