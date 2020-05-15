#include <stdio.h>

int main(void){
    int n=50;
    printf("%p\n", &n); // & operator gets the address of the variable.
    printf("%i\n", *&n); // * operator is a pointer that lets us go to the location of the variable.
        //int *p = &n;
        //printf("%p\n", p);

    
}