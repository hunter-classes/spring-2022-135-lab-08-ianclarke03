#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <string>
#include "imageio.h"
#include "funcs.h"

//task A
//all colors are inverted (white to black OR black to white)
void invertColors(std::string imagefile, std::string outfile){
    // takes in a array called image, height, and width which are all empty and will be filled in with the image data
    int image[MAX_H][MAX_W];
    int height, width;

    readImage(imagefile, image, height, width); // reads the provided image and reports back the dimensions

    int out[MAX_H][MAX_W]; // modify the contents in a new array 

    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){

            // (note: black is 0 & white is 255)
            // examples: 2 --> 253 3 --> 252 to do this: subtract the pixel by 255
            out[row][col] = 255 - (image[row][col]); // image[row][col] is the individual pixel brightness on a scale from 0 to 255 
            
        }
    }

    writeImage(outfile, out, height, width);
}

//task B
//inverts the colors ONLY in the right half of the picture

void invertColors2(std::string imagefile, std::string outfile){

    int image[MAX_H][MAX_W];//2d array
    int height, width;

    readImage(imagefile, image, height, width);

    int out[MAX_H][MAX_W];
    int halfMark = width/2;
    
    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){
            
            if (col >= halfMark){ //column number has to be greater than or equal to the half point mark to be on the right
                out[row][col] = 255 - (image[row][col]);
            }
            else { //if not, just keep it the same and copy it to array out
                out[row][col] = image[row][col];
            }
        }
    }

    writeImage(outfile, out, height, width);
}


//task C
//add a white box exactly in the middle of the picture 

void whiteBox(std::string imagefile, std::string outfile){

    int image[MAX_H][MAX_W];
    int height, width;

    readImage(imagefile, image, height, width);

    int out[MAX_H][MAX_W];
    int colMark1 = width/4; // quarter of the width (left side of the box)
    int colMark2 = 3 * colMark1; // 3/4 of the width (right side of the box)

    int rowMark1 = height/4; // quarter of the height (top of the box)
    int rowMark2 = 3 * rowMark1; // 3/4 of the height (bottom of the box)

    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){

            // greater than or equal to mark 1 and below mark 2 which is going from 1/4 to 3/4 == 1/2
            if ( (col >= colMark1 && col <= colMark2) && (row >= rowMark1 && row <= rowMark2) ){
                int diff = 255 - image[row][col]; // to be white, the pixel brightness needs to be 255, so we calculate the difference then add that back
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
//add a frame (one pixel thick) in the middle of the picture

void addFrame(std::string imagefile, std::string outfile){
    
    int image[MAX_H][MAX_W];
    int height, width;

    readImage(imagefile, image, height, width);

    int out[MAX_H][MAX_W];
    int colMark1 = width/4; // quarter of the width (left side of the box)
    int colMark2 = 3 * colMark1; // 3/4 of the width (right side of the box)

    int rowMark1 = height/4; // quarter of the height (top of the box)
    int rowMark2 = 3 * rowMark1; // 3/4 of the height (bottom of the box)

    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){

            // top horizontal line must be on rowMark1 and can span through the columns
            // left vertical line must be on colMark1 and can span through all the rows
            // (same applies for right line and bottom line)

            // the column must be in between the column range and must belong on either marked row
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
//scale the original image by 200% (each pixel is 2x2)
// use 4 for loops --> for row, for 2(increase by the factor of 2 to add it twice), for col, for 2

void scaleBy200(std::string imagefile, std::string outfile){

    int image[MAX_H][MAX_W];
    int height, width;

    readImage(imagefile, image, height, width);

    int out[MAX_H][MAX_W];
    //increase the size of the image by a factor of 2:
    int newHeight = (height * 2);
    int newWidth = (width * 2);

    for (int row = 0; row < newHeight-10; row++){
        
        for (int col = 0; col < newWidth-10; col++){
            int r = row/2;
            int c = col/2;

            // to get a 2x2: --> 11 --> 11 11 
            //                          11 11
            // top left--> copy the pixel normally into the array out
            // top right --> increase the width by 1
            // bottom left --> increase the height by 1
            // bottom right --> increase the width and height both by 1
            out[row][col] = image[r][c]; // image[row][col] doesn't fill the entire space and when opened, we can see black unused space 
            out[row][col+1] = image[r][c];
            out[row+1][col] = image[r][c];
            out[row+1][col+1] = image[r][c];

        }
        
    }

    writeImage(outfile, out, newHeight, newWidth);
}

//task F
//pixelate the imagefile

void pixelate(std::string imagefile, std::string outfile){

    int image[MAX_H][MAX_W];
    int height, width;

    readImage(imagefile, image, height, width);

    int out[MAX_H][MAX_W];

    for (int row = 0; row < height; row+=2){ //going by 2's because 2x2 takes into account both rows/both columns
        for (int col = 0; col < width; col+=2){
            //take the average in a 2x2 window (assuming height and width are even)
            int average = (image[row][col] + image[row][col + 1] + image[row+1][col] + image[row+1][col+1])/4;
            //assign that average to each of the pixels in the 2x2 window
            out[row][col] = average;
            out[row][col+1] = average;
            out[row+1][col] = average;
            out[row+1][col+1] = average;
        }
    }

    writeImage(outfile, out, height, width);
}
