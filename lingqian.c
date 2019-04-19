#include <stdio.h>
int main(){
	int n1,n2,n3,n4,n5,yuan,jiao,fen;
	double total;
	scanf("%d%d%d%d%d",&n1,&n2,&n3,&n4,&n5);
	total=0.01*n1+0.02*n2+0.05*n3+0.1*n4+0.5*n5;
	yuan=(int)total;
	fen=(int)(total*100)%10;
	jiao=(total-yuan-fen*0.01)*10;
	printf("\t%.2lf Total\n",total);
	printf("\t\t%d yuan %d jiao %d fen\n",yuan,jiao,fen);
	return 0;
}

