#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int main(void){
#define n 1000000
    int Primer[n];
    Primer[0] = 2;
    for (int i=1,num = 3;i<n;num+=2) {
        register bool isprimer = true;
        for(int k=floor(sqrt(num)),j=0;Primer[j] <= k; j++) {
            if(num%Primer[j]==0){
                isprimer = false;
                break;
            }
        }
        if(isprimer) Primer[i++] = num;
    }
}
