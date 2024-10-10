#include <iostream>

#include "include/point.h"
#include "include/figure.h"
#include "include/triangle.h"
#include "include/hexagon.h"
#include "include/octagon.h"

int main () {
    Triangle triangle;

    std::cin >> triangle;

    std::cout << triangle << std::endl;

    std::cout << "Center: " << triangle.calcRotationCenter() << std::endl;
    std::cout << "S: " (double)(triangle) << std::endl;
    return 0;
}
