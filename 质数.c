#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int main(void){
    int n;
    scanf("%d",&n);
    int Primer[n];
    Primer[0] = 2;
    Primer[1] = 3;
    for (int i=2,num = 5;i<n;num+=2) {
        register bool isprimer = true;
        for(int k=floor(sqrt(num)),j=1;Primer[j] <= k; j++) {
            if(num%Primer[j]==0){
                isprimer = false;
                break;
            }
        }
        if(isprimer) Primer[i++] = num;
    }
}
