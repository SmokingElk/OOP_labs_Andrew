#include <gtest/gtest.h>
#include <stdexcept>

#include "../include/point.h"
#include "../include/figure.h"
#include "../include/triangle.h"
#include "../include/hexagon.h"
#include "../include/octagon.h"

int main (int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}