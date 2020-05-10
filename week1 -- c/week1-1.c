#include <stdio.h>

int main(void){
    printf("what's your name?\n");
    char str[100];
    scanf("%s", str);
    
    printf("hello %s\n", str);

}