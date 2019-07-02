#include <stdio.h>
#include <string.h>

int main() {
	int iWeishu,i,j;
	char a[1025],*p = a;
	FILE *fp;
	fp=fopen("output.txt","w+");
	fclose(fp);
a:
	gets(a);
	fp=fopen("output.txt","a+");
	iWeishu=strlen(a);
	for(j=-25; j<26; j++) {
		fprintf(fp,"%3d: ",j);
		for(i=0; i<iWeishu; i++)
			fputc((char)((int)*(p+i)+j),fp);
		fputc('\n',fp);
	}
	fclose(fp);
	goto a;
}
