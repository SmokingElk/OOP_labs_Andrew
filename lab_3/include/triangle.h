#pragma once
#include <iostream>
#include <fstream>
#include <math.h>
#include "utils.h"
#include "point.h"
#include "figure.h"

class Triangle : public Figure {
    private:
        Point a;
        Point b;
        Point c;

    public:
        Triangle ();
        Triangle (Point vertexA, Point vertexB, Point vertexC);
        Triangle (const Triangle &other);
        Triangle& operator= (const Triangle &other);

        float calcRotationCenter() override;
        operator double() override;
        std::ostream& print (std::ostream& os) const override;
        std::istream& input (std::istream& is) override;

        friend std::ostream& operator<< (std::ostream& os, const Triangle &triangle);
        friend std::istream& operator>> (std::istream& is, Triangle &triangle);
};

std::ostream& operator<< (std::ostream& os, const Triangle &triangle);
std::istream& operator>> (std::istream& is, Triangle &triangle);