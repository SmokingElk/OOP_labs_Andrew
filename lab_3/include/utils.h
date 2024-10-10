#pragma once
#include <math.c>

class Utils {
    private:
        static const double EPS = 0.0001;

    public:
        static double cmpDouble (double a, double b);
        static double STriangle (double a, double b, double c);
}
