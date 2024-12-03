#include "../include/rgb-24.h"

std::ostream& operator<< (std::ostream& os, const RGB24 &color) {
    static const char gradient[] = " .:!r(lH@";
    static constexpr int gradientLength = sizeof(gradient) / sizeof(char) - 1;

    int pseudoColorIndex = (color.r + color.g + color.b) * gradientLength / 256 / 3;
    os << gradient[pseudoColorIndex < gradientLength ? pseudoColorIndex : gradientLength - 1] << " ";

    return os;
}