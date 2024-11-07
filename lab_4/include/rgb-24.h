#pragma once
#include <iostream>
#include <fstream>

struct RGB24 {
    unsigned char r;
    unsigned char g;
    unsigned char b;

    RGB24 () : r{0}, g{0}, b{0} {}
    RGB24 (unsigned char gray) : r{gray}, g{gray}, b{gray} {}
    RGB24 (unsigned char red, unsigned char green, unsigned char blue) : r{red}, g{green}, b{blue} {}
};

std::ostream& operator<< (std::ostream& os, const RGB24 &color) {
    static const char gradient[] = " .:!r(lH@";
    static constexpr int gradientLength = sizeof(gradient) / sizeof(char) - 1;

    int pseudoColorIndex = (color.r + color.g + color.b) * gradientLength / 256 / 3;
    os << gradient[pseudoColorIndex < gradientLength ? pseudoColorIndex : gradientLength - 1] << " ";

    return os;
}