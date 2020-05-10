#include <stdio.h>

int main (void){
    int x;
    printf("x: ");
    scanf("%d", &x);
    
    int y;
    printf("y: ");
    scanf("%d", &y);

    if (x<y){
        printf("x<y");
    }
    else if (x>y){
        printf("x>y");
    }
    else{
        printf("x=y");
    }

}