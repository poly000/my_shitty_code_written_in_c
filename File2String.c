_Static_assert(sizeof(char) == 1,"It\'s not works!"); //C11
#include <stdio.h>
#define BUF_SIZE 4096U
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
			setvbuf(fpo,buf,_IOFBF,BUF_SIZE);
			fprintf(fpo,"\n#define %s \"",argv[3]);
			while (!feof(fpi)) {
				static char ch[1];
				fread((void *)ch,(size_t)1,(size_t)1,fpi);
				if (feof(fpi))
					break;
				fprintf(fpo,"\\x");
				static unsigned char num1,num2;
				num1 = num2 = ch[0];
				num2 >>= 4;
				num2 &= 0xF;
				num1 &= 0xF;
				fprintf(fpo,"%x%x",num2,num1);
			}
			fprintf(fpo,"\"");
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
