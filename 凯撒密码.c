/*   Author: poly000
 *   License: Anti 996 (MIT-like)
 */
#include <stdio.h>
#include <string.h>

int main() {
	int iNum,i,j;
	char a[1025];
	char *p = a;
	FILE *fp;
	fp = fopen("output.txt","w+");
	fclose(fp);
a:
	gets(a);
	fp = fopen("output.txt","a+");
	iNum = strlen(a);
	for(j=-25; j<26; j++) {
		fprintf(fp,"%3d: ",j);
		for(i=0; i<iNum; i++)
			fputc((char)((int)*(p+i)+j),fp);
		fputc('\n',fp);
	}
	fclose(fp);
	goto a;
}
