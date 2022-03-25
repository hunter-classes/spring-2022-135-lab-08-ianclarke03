#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <string>
#include "imageio.h"
#include "funcs.h"

//task A

void invertColors(std::string imagefile, std::string outfile){
    int image[MAX_H][MAX_W];
    int height, width;

    readImage(imagefile, image, height, width); 

    int out[MAX_H][MAX_W]; 

    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){
            out[row][col] = 255 - (image[row][col]);
        }
    }

    writeImage(outfile, out, height, width);
}

//task B

void invertColors2(std::string imagefile, std::string outfile){

    int image[MAX_H][MAX_W];
    int height, width;

    readImage(imagefile, image, height, width);

    int out[MAX_H][MAX_W];
    int halfMark = width/2;
    
    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){
            
            if (col >= halfMark){
                out[row][col] = 255 - (image[row][col]);
            }
            else { 
                out[row][col] = image[row][col];
            }
        }
    }

    writeImage(outfile, out, height, width);
}


//task C

void whiteBox(std::string imagefile, std::string outfile){

    int image[MAX_H][MAX_W];
    int height, width;

    readImage(imagefile, image, height, width);

    int out[MAX_H][MAX_W];
    int colMark1 = width/4; 
    int colMark2 = 3 * colMark1; 

    int rowMark1 = height/4; 
    int rowMark2 = 3 * rowMark1; 

    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){


            if ( (col >= colMark1 && col <= colMark2) && (row >= rowMark1 && row <= rowMark2) ){
                int diff = 255 - image[row][col]; 
                out[row][col] = diff + (image[row][col]);
            }
            else {
                out[row][col] = image[row][col];
            }
        }
    }

    writeImage(outfile, out, height, width);

}


//task D

void addFrame(std::string imagefile, std::string outfile){
    
    int image[MAX_H][MAX_W];
    int height, width;

    readImage(imagefile, image, height, width);

    int out[MAX_H][MAX_W];
    int colMark1 = width/4; 
    int colMark2 = 3 * colMark1;

    int rowMark1 = height/4; 
    int rowMark2 = 3 * rowMark1; 

    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){
            if ( (col >= colMark1 && col <= colMark2) && (row == rowMark1 || row == rowMark2) ){
                int diff = 255 - image[row][col];
                out[row][col] = diff + image[row][col];
            }
            else if ( (row >= rowMark1 && row <= rowMark2) && (col == colMark1 || col == colMark2) ){
                int diff = 255 - image[row][col];
                out[row][col] = diff + image[row][col];
            }
            else {
                out[row][col] = image[row][col];
            }
        }
    }

    writeImage(outfile, out, height, width);

}

//task E

/*
void scaleBy200(std::string imagefile, std::string outfile){

    int image[MAX_H][MAX_W];
    int height, width;

    readImage(imagefile, image, height, width);

    int out[MAX_H][MAX_W];
    int newHeight = (height * 2);
    int newWidth = (width * 2);

    for (int row = 0; row < newHeight-10; row++){
        
        for (int col = 0; col < newWidth-10; col++){
            int r = row/2;
            int c = col/2;
            out[row][col] = image[r][c]; 
            out[row][col+1] = image[r][c];
            out[row+1][col] = image[r][c];
            out[row+1][col+1] = image[r][c];

        }
        
    }

    writeImage(outfile, out, newHeight, newWidth);
}
*/


//task F


void pixelate(std::string imagefile, std::string outfile){

    int image[MAX_H][MAX_W];
    int height, width;

    readImage(imagefile, image, height, width);

    int out[MAX_H][MAX_W];

    for (int row = 0; row < height; row+=2){ 
        for (int col = 0; col < width; col+=2){

            int average = (image[row][col] + image[row][col + 1] + image[row+1][col] + image[row+1][col+1])/4;
            out[row][col] = average;
            out[row][col+1] = average;
            out[row+1][col] = average;
            out[row+1][col+1] = average;
        }
    }

    writeImage(outfile, out, height, width);
}
