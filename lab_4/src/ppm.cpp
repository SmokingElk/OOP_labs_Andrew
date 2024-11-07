#include "../include/ppm.h"

void PPM::open (std::string savePath) {
    if (fout.is_open()) return;
    fout.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    fout.open(savePath);

    fout << "P6 " << std::to_string(width) << " " << std::to_string(height) << " 255 "; 
}

PPM::PPM (std::string savePath, int imgWidth, int imgHeight) : width{imgWidth}, height{imgHeight}, pixelsWritten{0} {
    open(savePath);
}

PPM::PPM (PPM &&other) : width{other.width}, height{other.height}, pixelsWritten{0} {
    fout = std::move(other.fout);
}

PPM::~PPM () {
    if (!fout.is_open()) return;

    while (pixelsWritten < width * height) *this << RGB24();
    fout.close();
}

PPM& PPM::operator<< (RGB24 color) {
    fout << color.r << color.g << color.b;
    if (++pixelsWritten > width * height) throw std::logic_error("PPM buffer overflow.");
    return *this;
}