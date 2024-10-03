#include <stdexcept>
#include "../include/Six.h"

unsigned char validateDigit (unsigned char digit);

void Six::allocBuffer (size_t bufSize) {
    size = bufSize;
    digits = new(std::nothrow) unsigned char[size];
    if (!digits) throw std::runtime_error("Allocation failed");
}

void Six::rmZeros () {
    int firstDigit = 0;

    for (int i = 0; i < size; i++) {
        if (digits[i] != '0') firstDigit = i;
    }

    unsigned char *newDigits = new unsigned char[firstDigit + 1];
    
    for (int i = 0; i < firstDigit + 1; i++) {
        newDigits[i] = digits[i];
    }

    delete [] digits;

    size = firstDigit + 1;
    digits = newDigits;
}

Six::Six () {
    allocBuffer(1);
    digits[0] = '0';
}

Six::Six (const size_t &length, unsigned char digit) {
    validateDigit(digit);

    if (length <= 0) throw std::invalid_argument("Length must be positive");

    allocBuffer(length);
    for (int i = 0; i < size; i++) digits[i] = digit;

    rmZeros();
}

Six::Six (const std::initializer_list<unsigned char> &list) {
    allocBuffer(list.size());

    int bufferPos = size - 1;
    for (const unsigned char &digit : list) {
        digits[bufferPos--] = validateDigit(digit);
    } 

    rmZeros();
}

Six::Six (const std::string &str) {
    allocBuffer(str.length());

    for (int i = 0; i < size; i++) {
        digits[size - 1 - i] = validateDigit(str[i]);
    } 

    rmZeros();
}

Six::Six (const Six& other) {
    delete [] digits;
    allocBuffer(other.size);

    for (int i = 0; i < size; i++) {
        digits[i] = other.digits[i];
    }
}

Six::Six (Six&& other) noexcept {
    size = other.size;
    digits = other.digits;
    other.size = 0;
    other.digits = nullptr;
}

Six::~Six() noexcept {
    delete [] digits;
}

bool Six::operator== (const Six &other) const {
    if (size != other.size) return false;

    for (int i = 0; i < size; i++) {
        if (digits[i] != other.digits[i]) return false;
    }

    return true;
}

bool Six::operator< (const Six &other) const {
    if (size < other.size) return true;
    if (size > other.size) return false;

    for (int i = size - 1; i >= 0; i--) {
        if (digits[i] - '0' < other.digits[i] - '0') return true;
        if (digits[i] - '0' > other.digits[i] - '0') return false;
    }

    return false;
}

bool Six::operator> (const Six &other) const {
    if (size > other.size) return true;
    if (size < other.size) return false;

    for (int i = size - 1; i >= 0; i--) {
        if (digits[i] - '0' > other.digits[i] - '0') return true;
        if (digits[i] - '0' < other.digits[i] - '0') return false;
    }

    return false;
}

Six& Six::operator= (const Six &other) {
    if (this == &other) {
        throw std::logic_error("Self asigment");
    }

    if (digits) delete [] digits;
    allocBuffer(other.size);

    for (int i = 0; i < size; i++) {
        digits[i] = other.digits[i];
    }

    return *this;
}

Six& Six::operator+= (const Six &other) {
    int maxSize = size > other.size ? size : other.size;
    unsigned char *newDigits = new(std::nothrow) unsigned char[maxSize + 1];
    if (!newDigits) throw std::runtime_error("Allocation failed");

    int carry = 0;

    for (int i = 0; i < maxSize; i++) {
        int digitA = i < size ? digits[i] - '0' : 0;
        int digitB = i < other.size ? other.digits[i] - '0' : 0;

        int sum = digitA + digitB + carry;
        newDigits[i] = '0' + sum % 6;
        carry = sum >= 6 ? 1 : 0;
    }

    if (carry > 0) newDigits[maxSize] = '1';

    delete [] digits;
    size = carry > 0 ? maxSize + 1 : maxSize;
    digits = newDigits;

    return *this;
}

Six& Six::operator-= (const Six &other) {
    if (*this < other) {
        throw std::logic_error("Reduced is less than the subtracted");
    }

    // не нужна проверка, A не может быть меньше
    unsigned char *newDigits = new(std::nothrow) unsigned char[size];
    if (!newDigits) throw std::runtime_error("Allocation failed");

    int carry = 0;

    for (int i = 0; i < size; i++) {
        // не нужна проверка, A не может быть меньше
        int digitA = digits[i] - '0';
        int digitB = i < other.size ? other.digits[i] - '0' : 0;

        int diff = digitA - digitB - carry;
        newDigits[i] = '0' + (diff < 0 ? diff + 6 : diff);
        carry = diff < 0 ? 1 : 0;
    }

    delete [] digits;
    digits = newDigits;
    
    rmZeros();

    return *this;
}

std::ostream& operator<< (std::ostream& os, const Six &number) {
    os << "0s";
    for (int i = number.size - 1; i >= 0; i--) os << number.digits[i];
    return os;
};

unsigned char validateDigit (unsigned char digit) {
    if (digit < '0' || digit > '5') throw std::invalid_argument("Invalid digit");
    return digit;
}