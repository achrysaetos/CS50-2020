
//Uses Luhn's algorithm to validate card numbers
#include <stdio.h>
#include <math.h>

int main(void){
    unsigned long total=4003600000000014;
    int sum=0;
    int nextsum=0;
    for(int i=1; i<17; i++){
        if (i%2==1){
            nextsum+=total%10;
            total=total/10;
        }else{
            if(2*(total%10)<10){
                sum+=2*(total%10);
                total=total/10;
            }else{
                sum+=(2*(total%10))/10+(2*(total%10))%10;
                total=total/10;
            }
        }
    }
    int sumsum = sum+nextsum;
    printf("%d", sumsum);

}