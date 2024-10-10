#include "../include/point.h"

Point::Point () : x{0.0}, y{0.0} {}
Point::Point (double xValue, double yValue) : x{xValue}, y{yValue} {}
Point::Point (double value) : Point(value, value) {}
Point::Point (const Point &other) : Point(other.x, other.y) {}

Point& Point::operator= (const Point &other) {
    if (this == &other) return *this;
    x = other.x;
    y = other.y;
    return *this; 
}

Point Point::operator+ (const Point &other) {
    return Point(x + other.x, y + other.y);
}

Point Point::operator- (const Point &other) {
    return Point(x - other.x, y - other.y);
}

Point Point::operator* (double number) {
    return Point(number * x, number * y);
}

double Point::abs () {
    return sqrt(x * x + y * y);
}

double Point::getX () {
    return x;
}

double Point::getY () {
    return y;
}

std::ostream& operator<< (std::ostream& os, const Point &point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

std::istream& operator>> (std::istream& is, Point &point) {
    double x, y;

    std::cout << "(" << std::endl << "\tInput x for point: ";
    is >> x;
    std::cout << "\tInput y for point: ";
    is >> y;
    std::cout << ")" << std::endl;

    point.x = x;
    point.y = y;

    return is;
}
