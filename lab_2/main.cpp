#include <iostream>
#include <string>
#include "include/Six.h"

int main () {
    std::string numberAStr, numberBStr;

    std::cout << "Input number a: ";
    std::cin >> numberAStr;
    std::cout << "Input number b: ";
    std::cin >> numberBStr;

    try {
        Six numberA(numberAStr);
        Six numberB(numberBStr);

        std::cout << "a = " << numberA << std::endl;
        std::cout << "b = " << numberB << std::endl;

        Six numberSum{numberA};
        numberSum += numberB;

        std::cout << "a + b = " << numberSum << std::endl;
        
        if (numberA > numberB || numberA == numberB) {
            Six numberDiff{numberA};
            numberDiff -= numberB;

            std::cout << "a - b = " << numberDiff << std::endl;
        } else {
            Six numberDiff{numberB};
            numberDiff -= numberA;

            std::cout << "b - a = " << numberDiff << std::endl;
        }
    } catch (const std::exception &err) {
        std::cout << err.what() << std::endl;
    }

    return 0;
}
