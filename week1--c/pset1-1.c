
//Prints out Mario's blocks in a pattern
#include <stdio.h>

int main(void){
    int numBlocks;
    printf("how many blocks? ");
    scanf("%d", &numBlocks);
    numBlocks += 1;


//K's solution
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


//Z's solution
    // for (int row = 0; row < numBlocks; row++){
    //     for (int i =0; i< 2 * numBlocks + 2; i++){
    //         if(i > numBlocks + 1){
    //             if(i > row){
    //                 printf(" ");
    //             }else{
    //                 printf("#");
    //             }
    //         }
    //         else if (i < numBlocks - 1) {
    //             if(i < row){
    //                 printf(" ");
    //             }
    //             else{
    //                 printf("#");
    //             }
    //         }else{
    //             printf(" ");
    //         }
    //     }
    // }


//L's solution
    // for ( int i = 1; i < numBlocks+1; i++){
    //     for ( int j = 0; j < i; j++)
    //     {
    //         printf("#");
    //     }
    //     printf("\n");
    // }
    

}