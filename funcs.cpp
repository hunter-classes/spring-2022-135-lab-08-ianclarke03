#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <string>

#include "imageio.h"


//Task A: invert
void Invert(std::string input){
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w); // read it from the file "inImage.pgm"
  // h and w were passed by reference and
  // now contain the dimensions of the picture
  // and the 2-dimesional array img contains the image data
  
  // Now we can manipulate the image the way we like
  // for example we copy its contents into a new array
  int inverted[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      inverted[row][col] = img[255 - row][255 - col];
    }
  }
  
  // and save this new image to file "outImage.pgm"
  writeImage("invertedImage.pgm",inverted, h, w);

}

int main(){
  invert("image1.pgm");
}