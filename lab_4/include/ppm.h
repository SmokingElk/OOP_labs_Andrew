#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "rgb-24.h"

class PPM {
    private:
        std::ofstream fout;
        
        int pixelsWritten;
        int width;
        int height;

        void open (std::string savePath);

    public:
        PPM (std::string savePath, int imgWidth, int imgHeight);
        PPM (PPM &&other);
        ~PPM ();
        PPM& operator<< (RGB24 color);
};
