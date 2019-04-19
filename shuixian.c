#include <stdio.h>
int main(){
	int i,i_=0,w,x,y,z;
	for(i=1000;i<=9999;i++){
		w=i/1000;
		x=(i-w*1000)/100;
		y=(i-w*1000-x*100)/10;
		z=i%10;
		if(w*w*w*w+x*x*x*x+y*y*y*y+z*z*z*z==i){
			if(++i_==10){
				i_=0;
				printf("%d\n",i);
			}else{
				printf("%d ",i);
			}
		}
	}
	return 0;
}
