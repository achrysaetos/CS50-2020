
//Prints out Mario's blocks in a pattern
#include <stdio.h>

int main(void){
    int numBlocks;
    printf("how many blocks? ");
    scanf("%d", &numBlocks);
    numBlocks += 1;

    for (int i=2; i<numBlocks+1; i++) {
        for(int j=numBlocks-i; j>0; j--) {
            printf(" ");
        }
        for(int j=1; j<i; j++){
            printf("#");
        }
        printf("  ");
        for(int j=1; j<i; j++){
            printf("#");
        }
        for(int j=numBlocks-i; j>0; j--) {
            printf(" ");
        }
        printf("\n");
    }

}