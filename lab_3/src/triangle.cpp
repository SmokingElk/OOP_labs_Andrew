#include "../include/triangle.h"

Triangle::Triangle () {
    a = Point(cos(0), sin(0));
    b = Point(cos(M_PI / 3.0 * 2.0), sin(M_PI / 3.0 * 2.0));
    c = Point(cos(M_PI / 3.0 * 4.0), sin(M_PI / 3.0 * 4.0));
}

Triangle::Triangle (Point vertexA, Point vertexB, Point vertexC) {
    a = vertexA;
    b = vertexB;
    c = vertexC;
}

Triangle::Triangle (const Triangle &other) {
    a = other.a;
    b = other.b;
    c = other.c;
}

Triangle& Triangle::operator= (const Triangle &other) {
    if (this == &other) return *this;
    a = other.a;
    b = other.b;
    c = other.c;
    return *this;
}

Point Triangle::calcRotationCenter() override {
    Point mid = (a + b + c) * (1.0 / 3.0);
    return mid;
}

Triangle::operator double() override {
    double AB = (a - b).mag();
    double BC = (b - c).mag();
    double AC = (a - c).mag();
    return Utils::STriangle(AB, BC, AC);
}

std::ostream& Triangle::print (std::ostream& os) const override {
    os << "Triangle (" << std::endl;
    os << "\tA = " << a << std::endl;
    os << "\tB = " << b << std::endl;
    os << "\tC = " << c << std::endl;
    os << ")";
    return os;
}

std::istream& Triangle::input (std::istream& is) override {
    std::cout << "Input Triangle (" << std::endl;

    std::cout << "Input point A = ";
    Point pA;
    is >> pA;

    std::cout << "Input point B = ";
    Point pB;
    is >> pB;

    std::cout << "Input point C = ";
    Point pC;
    is >> pC;

    std::cout << ")" << std::endl;

    a = pA;
    b = pB;
    c = pC;

    return is;
}

std::ostream& operator<< (std::ostream& os, const Triangle &triangle) {
    return triangle.print(os);
}

std::istream& operator>> (std::istream& is, Triangle &triangle) {
    return triangle.input(os);
}
