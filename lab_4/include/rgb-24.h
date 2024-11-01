#pragma once

struct RGB24 {
    unsigned char r;
    unsigned char g;
    unsigned char b;

    RGB24 () : r{0}, g{0}, b{0} {}
    RGB24 (unsigned char gray) : r{gray}, g{gray}, b{gray} {}
    RGB24 (unsigned char red, unsigned char green, unsigned char blue) : r{red}, g{green}, b{blue} {}
};