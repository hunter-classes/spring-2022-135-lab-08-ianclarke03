#include <iostream>
#include "funcs.h"
#include "imageio.h"

int main()
{
  invert("image1.pgm");
  inverthalf("image1.pgm");
  box("image1.pgm");
  frame("image1.pgm");
  scale("image1.pgm");
  pixelate("image1.pgm");
}