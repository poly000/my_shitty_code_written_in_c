#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
	if (argc == 1||strcmp(argv[1],"-h") == 0||strcmp(argv[1],"--help") == 0) {
		char *cp_TMP = *argv,*cp_Last = 0;
		while (*(cp_TMP) != 0) {
			if (*(cp_TMP++) == '/'||*(cp_TMP++) == '\\')
				cp_Last = cp_TMP;
		}
		printf("Usage:\n %s [Image] [Archive] > [Outfile]\n %s [FILE]...\n",cp_Last,cp_Last);
	}
	int i_NUM = argc-1;
	long l_FiSize;
	int8_t **i8_TMP = (int8_t **)malloc(sizeof(int8_t *)*i_NUM);
	FILE **fip_Fp = (FILE **)malloc(sizeof(FILE *)*i_NUM);
	for (int i=0; i<i_NUM; i++) {
		fip_Fp[i] = fopen(argv[i+1],"rb");
		if (fip_Fp[i] == 0) {
			fprintf(stderr,"can't read file:\n%s\n",argv[i+1]);
			continue;
		}
		fseek(fip_Fp[i],0L,2);
		l_FiSize = ftell(fip_Fp[i]);
		rewind(fip_Fp[i]);
		i8_TMP[i] = (int8_t *)malloc(sizeof(int8_t)*l_FiSize);
		fread((void *)i8_TMP[i],sizeof(int8_t),l_FiSize,fip_Fp[i]);
		if(fclose(fip_Fp[i]) != 0) {
			fprintf(stderr,"can't close file:\n%s\n",argv[i+1]);
		}
		for (int j=0; j<l_FiSize; j++) {
			putchar(i8_TMP[i][j]);
		}
	}
	return 0;
}