//Encryption -- A maps to first letter of secret key, B maps to second letter, etc.
#include <stdio.h>
#include <string.h>

int main(void){
    char secret[26] = 
    //"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    "QWERTYUIOPASDFGHJKLZXCVBNM";
    printf("plaintext: ");
    char plaintext[1000];
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("ciphertext: ");
    for(int i=0; i<strlen(plaintext); i++){
        if(plaintext[i]=='A'||plaintext[i]=='a'){
            printf("%c", secret[0]);
        }else if(plaintext[i]=='B'||plaintext[i]=='b'){
            printf("%c", secret[1]);
        }else if(plaintext[i]=='C'||plaintext[i]=='c'){
            printf("%c", secret[2]);
        }else if(plaintext[i]=='D'||plaintext[i]=='d'){
            printf("%c", secret[3]);
        }else if(plaintext[i]=='E'||plaintext[i]=='e'){
            printf("%c", secret[4]);
        }else if(plaintext[i]=='F'||plaintext[i]=='f'){
            printf("%c", secret[5]);
        }else if(plaintext[i]=='G'||plaintext[i]=='g'){
            printf("%c", secret[6]);
        }else if(plaintext[i]=='H'||plaintext[i]=='h'){
            printf("%c", secret[7]);
        }else if(plaintext[i]=='I'||plaintext[i]=='i'){
            printf("%c", secret[8]);
        }else if(plaintext[i]=='J'||plaintext[i]=='j'){
            printf("%c", secret[9]);
        }else if(plaintext[i]=='K'||plaintext[i]=='k'){
            printf("%c", secret[10]);
        }else if(plaintext[i]=='L'||plaintext[i]=='l'){
            printf("%c", secret[11]);
        }else if(plaintext[i]=='M'||plaintext[i]=='m'){
            printf("%c", secret[12]);
        }else if(plaintext[i]=='N'||plaintext[i]=='n'){
            printf("%c", secret[13]);
        }else if(plaintext[i]=='O'||plaintext[i]=='o'){
            printf("%c", secret[14]);
        }else if(plaintext[i]=='P'||plaintext[i]=='p'){
            printf("%c", secret[15]);
        }else if(plaintext[i]=='Q'||plaintext[i]=='q'){
            printf("%c", secret[16]);
        }else if(plaintext[i]=='R'||plaintext[i]=='r'){
            printf("%c", secret[17]);
        }else if(plaintext[i]=='S'||plaintext[i]=='s'){
            printf("%c", secret[18]);
        }else if(plaintext[i]=='T'||plaintext[i]=='t'){
            printf("%c", secret[19]);
        }else if(plaintext[i]=='U'||plaintext[i]=='u'){
            printf("%c", secret[20]);
        }else if(plaintext[i]=='V'||plaintext[i]=='v'){
            printf("%c", secret[21]);
        }else if(plaintext[i]=='W'||plaintext[i]=='w'){
            printf("%c", secret[22]);
        }else if(plaintext[i]=='X'||plaintext[i]=='x'){
            printf("%c", secret[23]);
        }else if(plaintext[i]=='Y'||plaintext[i]=='y'){
            printf("%c", secret[24]);
        }else if(plaintext[i]=='Z'||plaintext[i]=='z'){
            printf("%c", secret[25]);
        }else{
            printf("%c", plaintext[i]);
        }
    }

}
