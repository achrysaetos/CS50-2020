#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc != 2){
        return 1;
    }// check correct number of arguments

    FILE *file = fopen(argv[1], "r");
    if (file == NULL){
        return 2;
    }// open file

    unsigned char *buffer = malloc(512);
    int jpg_number = 0;
    FILE *img;

    while (fread(buffer, 512, 1, file)){
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && 
            buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){// new jpeg file found

            if (jpg_number > 0){
                fclose(img);
            }// close old jpeg file

            char filename[7];
            sprintf(filename, "%03i.jpg", jpg_number);
            img = fopen(filename, "w");// create new jpeg file

            jpg_number++;
        }

        if (!jpg_number){
            continue;
        }
        fwrite(buffer, 512, 1, img);
    }

    fclose(file);
    fclose(img);
    free(buffer);
}