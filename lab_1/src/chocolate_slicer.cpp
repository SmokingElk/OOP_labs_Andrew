#include "../include/chocolate_slicer.h"

int slicesCount (int n, int m) {
    if (n <= 0 || m <= 0) return 0;
    return n * m - 1;
}