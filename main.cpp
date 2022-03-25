#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include "imageio.h"
#include "funcs.h"

int main(){

    //task A invert colors
    std::string imageFile = "image1.pgm"; 
    std::string taskA_outfile = "taskA.pgm";
    invertColors(imageFile, taskA_outfile); // on mac--> open taskA.pgm OR qlmanage -p taskA.pgm

    //task B invert right half only
    std::string taskB_outfile = "taskB.pgm";
    invertColors2(imageFile, taskB_outfile);

    //task C add a white box
    std::string taskC_outfile = "taskC.pgm";
    whiteBox(imageFile, taskC_outfile);

    //task D add a white frame
    std::string taskD_outfile = "taskD.pgm";
    addFrame(imageFile, taskD_outfile);

    //task E scale by 200%
    //std::string taskE_outfile = "taskE.pgm";
    //scaleBy200(imageFile, taskE_outfile);

    //task F pixelate the image file
    std::string taskF_outfile = "taskF.pgm";
    pixelate(imageFile, taskF_outfile);

    return 0;
}