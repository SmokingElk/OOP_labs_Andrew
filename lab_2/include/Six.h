#pragma once
#include <iostream>
#include <fstream>

class Six {
private:
    unsigned char *digits = nullptr;
    size_t size;

    void allocBuffer (size_t bufSize);
    void rmZeros ();

public:
    Six ();
    Six (const size_t &length, unsigned char digit = '0');
    Six (const std::initializer_list<unsigned char> &list);
    Six (const std::string &str);
    Six (const Six& other);
    Six (Six&& other) noexcept;
    virtual ~Six() noexcept;

    bool operator== (const Six &other) const;
    bool operator< (const Six &other) const;
    bool operator> (const Six &other) const;
    Six& operator= (const Six &other);
    Six& operator+= (const Six &other);
    Six& operator-= (const Six &other);

    friend std::ostream& operator<< (std::ostream& os, const Six &number);
};

std::ostream& operator<< (std::ostream& os, const Six &number);