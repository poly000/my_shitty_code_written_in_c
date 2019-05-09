#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 100001 /* 10001 means max true number added 1 */
#define max_wrong_times 30 /* make it as you need */
int main() {
	register unsigned long true_num,wronged_times,guest_num;
	unsigned long guest_num_;
	char yesno;
	goto b;
a:
	if(wronged_times<=max_wrong_times) {
		printf("You won as %lu wronged times only!\n",wronged_times);
		printf("Play again? (y)\n");
	} else {
		printf("You lost...\n");
		printf("Try again? (y)\n");
	}
	getchar();
	yesno=getchar();
	if(yesno=='Y'||yesno=='y') {
		goto b;
	} else {
		return 0;
	}
b:
	srand(time(0));
	true_num=rand()%max;
	wronged_times=0;
c:
	printf("Please type a number: ");
	scanf("%lu",&guest_num_);
	guest_num=guest_num_;
	if(guest_num==true_num) {
		goto a;
	} else {
		wronged_times++;
		if(guest_num>true_num) {
			printf("Too big!\n\n");
		} else {
			printf("Too small!\n\n");
		}
		goto c;
	}
}
