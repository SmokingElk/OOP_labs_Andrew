#include "../include/utils.h"

double Utils::cmpDouble (double a, double b) {
    return abs(a - b) < EPS;
}

double Utils::STriangle (double a, double b, double c) {
    double p = (AB + BC + AC) / 2.0;
    return sqrt(p * (p - AB) * (p - BC) * (p - AC));
}

