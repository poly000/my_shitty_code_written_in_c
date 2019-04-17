#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	register unsigned long max_wrong_times=100,true_num,wronged_times;
	unsigned long guest_num;
	char yesno;
	goto b;
a:
	if(wronged_times<=max_wrong_times){
		printf("You won as %lu wronged times only!\n",wronged_times);
		printf("Play again? (y)\n");
	}else{
		printf("You lost...\n");
		printf("Try again? (y)\n");
	}
	yesno=getchar();
	yesno=getchar();
	if(yesno=='Y'||yesno=='y'){
		goto b;
	}else{
		return 0;
	}
b:
	srand(time(0));
	true_num=rand()%10001; /*10001 means max true number added 1*/
	wronged_times=0;
c:
	printf("Please type a number: ");
	scanf("%lu",&guest_num);
	if(guest_num==true_num){
		goto a;
	}else{
		wronged_times++;
		if(guest_num>true_num){
			printf("Too big!\n\n");
		}else{
			printf("Too small!\n\n");
		}
		goto c;
	}
}
