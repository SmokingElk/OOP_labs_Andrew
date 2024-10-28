#include <iostream>
#include <memory>

#include "include/custom-concepts.h"
#include "include/point.h"
#include "include/triangle.h"
#include "include/hexagon.h"
#include "include/octagon.h"
#include "include/array.h"

int main () {
    Array<std::unique_ptr<Figure<double>>> figures;

    figures.append(std::make_unique<Triangle<double>>());
    figures.append(std::make_unique<Hexagon<double>>());
    figures.append(std::make_unique<Octagon<double>>());

    for (std::size_t i = 0; i < figures.getSize(); i++) {
        std::cout << *figures[i] << std::endl;
        std::cout << "Figure rotation center: " << figures[i]->calcRotationCenter() << std::endl;
        std::cout << "Figure area: " << static_cast<double>(*figures[i]) << std::endl << std::endl;
    }

    return 0;
}
