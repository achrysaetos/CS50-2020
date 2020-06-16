#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            int a=floor((image[i][j].rgbtBlue+image[i][j].rgbtGreen+image[i][j].rgbtRed)/3);
            image[i][j].rgbtBlue=a;
            image[i][j].rgbtGreen=a;
            image[i][j].rgbtRed=a;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
       //     int tempb=image[i][j].rgbtBlue;
            image[i][j].rgbtBlue=image[i][width-j-1].rgbtBlue;
       //     image[i][width-j-1].rgbtBlue=tempb;

       //     int tempg=image[i][j].rgbtGreen;
            image[i][j].rgbtGreen=image[i][width-j-1].rgbtGreen;
       //     image[i][width-j-1].rgbtGreen=tempg;

       //     int tempr=image[i][j].rgbtRed;
            image[i][j].rgbtRed=image[i][width-j-1].rgbtRed;
       //     image[i][width-j-1].rgbtRed=tempr;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=1; i<height-1; i++){
        for(int j=1; j<width-1; j++){
            image[i][j].rgbtBlue=floor((image[i+1][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i][j+1].rgbtBlue+
                                image[i][j-1].rgbtBlue+image[i][j].rgbtBlue+image[i+1][j+1].rgbtBlue+
                                image[i+1][j-1].rgbtBlue+image[i-1][j+1].rgbtBlue+image[i-1][j-1].rgbtBlue)/9);
            image[i][j].rgbtGreen=floor((image[i+1][j].rgbtGreen+image[i-1][j].rgbtGreen+image[i][j+1].rgbtGreen+
                                image[i][j-1].rgbtGreen+image[i][j].rgbtGreen+image[i+1][j+1].rgbtGreen+
                                image[i+1][j-1].rgbtGreen+image[i-1][j+1].rgbtGreen+image[i-1][j-1].rgbtGreen)/9);
            image[i][j].rgbtRed=floor((image[i+1][j].rgbtRed+image[i-1][j].rgbtRed+image[i][j+1].rgbtRed+
                                image[i][j-1].rgbtRed+image[i][j].rgbtRed+image[i+1][j+1].rgbtRed+
                                image[i+1][j-1].rgbtRed+image[i-1][j+1].rgbtRed+image[i-1][j-1].rgbtRed)/9);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=1; i<height-1; i++){
        for(int j=1; j<width-1; j++){
            int bx= -1*image[i-1][j-1].rgbtBlue+    0*image[i-1][j].rgbtBlue+   1*image[i-1][j+1].rgbtBlue+
                    -2*image[i][j-1].rgbtBlue+      0*image[i][j].rgbtBlue+     2*image[i][j+1].rgbtBlue+
                    -1*image[i+1][j-1].rgbtBlue+    0*image[i+1][j].rgbtBlue+   1*image[i+1][j+1].rgbtBlue;
            int by= -1*image[i-1][j-1].rgbtBlue+    -2*image[i-1][j].rgbtBlue+  -1*image[i-1][j+1].rgbtBlue+
                    0*image[i][j-1].rgbtBlue+      0*image[i][j].rgbtBlue+     0*image[i][j+1].rgbtBlue+
                    1*image[i+1][j-1].rgbtBlue+    2*image[i+1][j].rgbtBlue+   1*image[i+1][j+1].rgbtBlue;
            if(floor(sqrt(pow(bx,2)+pow(by,2)))>255){
                image[i][j].rgbtBlue=255;
            }else{
                image[i][j].rgbtBlue=floor(sqrt(pow(bx,2)+pow(by,2)));
            }


            int gx= -1*image[i-1][j-1].rgbtGreen+    0*image[i-1][j].rgbtGreen+   1*image[i-1][j+1].rgbtGreen+
                    -2*image[i][j-1].rgbtGreen+      0*image[i][j].rgbtGreen+     2*image[i][j+1].rgbtGreen+
                    -1*image[i+1][j-1].rgbtGreen+    0*image[i+1][j].rgbtGreen+   1*image[i+1][j+1].rgbtGreen;
            int gy= -1*image[i-1][j-1].rgbtGreen+    -2*image[i-1][j].rgbtGreen+  -1*image[i-1][j+1].rgbtGreen+
                    0*image[i][j-1].rgbtGreen+      0*image[i][j].rgbtGreen+     0*image[i][j+1].rgbtGreen+
                    1*image[i+1][j-1].rgbtGreen+    2*image[i+1][j].rgbtGreen+   1*image[i+1][j+1].rgbtGreen;
            if(floor(sqrt(pow(gx,2)+pow(gy,2)))>255){
                image[i][j].rgbtGreen=255;
            }else{
                image[i][j].rgbtGreen=floor(sqrt(pow(gx,2)+pow(gy,2)));
            }

            int rx= -1*image[i-1][j-1].rgbtRed+    0*image[i-1][j].rgbtRed+   1*image[i-1][j+1].rgbtRed+
                    -2*image[i][j-1].rgbtRed+      0*image[i][j].rgbtRed+     2*image[i][j+1].rgbtRed+
                    -1*image[i+1][j-1].rgbtRed+    0*image[i+1][j].rgbtRed+   1*image[i+1][j+1].rgbtRed;
            int ry= -1*image[i-1][j-1].rgbtRed+    -2*image[i-1][j].rgbtRed+  -1*image[i-1][j+1].rgbtRed+
                    0*image[i][j-1].rgbtRed+      0*image[i][j].rgbtRed+     0*image[i][j+1].rgbtRed+
                    1*image[i+1][j-1].rgbtRed+    2*image[i+1][j].rgbtRed+   1*image[i+1][j+1].rgbtRed;
           if(floor(sqrt(pow(rx,2)+pow(ry,2)))>255){
                image[i][j].rgbtRed=255;
            }else{
                image[i][j].rgbtRed=floor(sqrt(pow(rx,2)+pow(ry,2)));
            }

        }
    }
    return;
}
