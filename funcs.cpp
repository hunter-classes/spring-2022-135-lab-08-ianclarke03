#include <iostream>
#include "funcs.h"
#include "imageio.h"

//Task A

void invert(std::string input){

  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int inverted[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      inverted[row][col] = img[255 - row][255 - col];
      //inverted[row][col] = abs(255 - img[row][col]);
    }
  }
  
  // and save this new image to file "outImage.pgm"
  writeImage("invertedImage.pgm",inverted, h, w);

}

/*Task B

void inverthalf(std::string input){

  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int inverted_half[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      inverted_half[row][col] = img[row][col];
    }
  }
  
  writeImage("halfInverted.pgm",inverted_half, h, w);
}

//Task C

void box(std::string input){

  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int arrbox[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      arrbox[row][col] = img[row][col];
    }
  }
  
  writeImage("box.pgm",arrbox, h, w);
}


//Task D

void frame(std::string input){

  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int arrframe[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      arrframe[row][col] = img[row][col];
    }
  }
  
  writeImage("frame.pgm",arrframe, h, w);
}


//Task E

void scale(std::string input){

  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int arrscale[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      arrscale[row][col] = img[2 * row][2* col];
    }
  }
  
  writeImage("scaled.pgm",arrscale, h, w);
}

//Task F

void pixelate(std::string input){

  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int pixel[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      pixel[row][col] = img[row][col];
    }
  }
  
  writeImage("pixelate.pgm",pixel, h, w);
}
*/


int invertHalf(std::string filename)
{
  std::string input = filename;
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w); // read it from the file "inImage.pgm"
  // h and w were passed by reference and
  // now contain the dimensions of the picture
  // and the 2-dimesional array img contains the image data
  // Now we can manipulate the image the way we like
  // for example we copy its contents into a new array
  int out[MAX_H][MAX_W];
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      if (col >= w/2) {
        out[row][col] = 255-img[row][col];
      }
      else {
        out[row][col] = img[row][col];
      }
    }
  }
  // and save this new image to file "outImage.pgm"
  writeImage("halfInvertedImage.pgm",out, h, w);
  return 0;
}

int box(std::string filename)
{
  std::string input = filename;
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w); // read it from the file "inImage.pgm"
  // h and w were passed by reference and
  // now contain the dimensions of the picture
  // and the 2-dimesional array img contains the image data
  // Now we can manipulate the image the way we like
  // for example we copy its contents into a new array
  int out[MAX_H][MAX_W];
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      if (row < h*3/4 && row > h/4 && col > w/4 && col < w*3/4) {
        out[row][col] = 255;
      }
      else {
        out[row][col] = img[row][col];
      }
    }
  }
  // and save this new image to file "outImage.pgm"
  writeImage("boxImage.pgm",out, h, w);
  return 0;
}

int frame(std::string filename)
{
  std::string input = filename;
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w); // read it from the file "inImage.pgm"
  // h and w were passed by reference and
  // now contain the dimensions of the picture
  // and the 2-dimesional array img contains the image data
  // Now we can manipulate the image the way we like
  // for example we copy its contents into a new array
  int out[MAX_H][MAX_W];
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      if ((row <= h*3/4 && row >= h/4 && col >= w/4 && col <= w*3/4) && (row == h*3/4 || row == h/4 || col == w/4 || col == w*3/4)) {
        out[row][col] = 255;
      }
      else {
        out[row][col] = img[row][col];
      }
    }
  }
  // and save this new image to file "outImage.pgm"
  writeImage("frameImage.pgm",out, h, w);
  return 0;
}