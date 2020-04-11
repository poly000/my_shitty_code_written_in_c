/*   Author: poly000
 *   License: WTFPL
 */
_Static_assert(sizeof(char) == 1,"It\'s not works!"); //C11
#include <stdio.h>
#define BUF_SIZE 4096
inline static void help(char * name) {
	printf("Usage:\n"
          "%s [INPUTFILE] [ADDTOFILE] [NAME]\n"
          "\n"
          "The string [INPUTFILE] converted to will named [NAME] as a sign constant.\n",name);
}

int main(int argc,char *argv[]) {
	{
		register char * name = *argv,* temp = name,ch;
		do {
			ch = *temp;
			if (ch == '/' || ch == '\\')
				name = temp;
		} while(*++temp != '\0');
		name++;
		if (argc != 4) {
			help(name);
			return 4;
		}
	}
	register FILE * restrict fpi = fopen(argv[1],"rb");
	if (fpi != NULL) {
		register FILE * restrict fpo = fopen(argv[2],"a");
		if (fpo != NULL) {
			static char buf[BUF_SIZE];
			setvbuf(fpo,buf,_IOFBF,(size_t)BUF_SIZE);
			fprintf(fpo,"\n#define %s \"",argv[3]);
			while (1) {
				static char ch[4096];
				register int n;
				if (!(n = fread((void *)ch,(size_t)1,(size_t)4096,fpi))) {
					break;
					printf("我很纯洁！\n");
				}
				for (register int i=0; i<n;i++) {
					register unsigned char num1,num2;
					num1 = num2 = ch[i];
					num2 >>= 4;
					num1 &= 0xF;
					num2 &= 0xF;
					fprintf(fpo,"\\x%x%x",num2,num1);
				}
			}
			fprintf(fpo,"\"\n");
			fclose(fpi);
			fclose(fpo);
			return 0;
		} else {
			fclose(fpi);
			printf("%s can't open!\n",argv[2]);
		}
	} else {
		printf("%s can't open!\n",argv[1]);
	}
	return 1;
}
