#include <gtest/gtest.h>
#include "../include/chocolate_slicer.h"

TEST(test_01, basic_test_set) {
    int n = -1;
    int m = -1;
    int result = slicesCount(n, m);
    ASSERT_TRUE(result == 0);
}

TEST(test_02, basic_test_set) {
    int n = 0;
    int m = -1;
    int result = slicesCount(n, m);
    ASSERT_TRUE(result == 0);
}

TEST(test_03, basic_test_set) {
    int n = -1;
    int m = 0;
    int result = slicesCount(n, m);
    ASSERT_TRUE(result == 0);
}

TEST(test_04, basic_test_set) {
    int n = 0;
    int m = 0;
    int result = slicesCount(n, m);
    ASSERT_TRUE(result == 0);
}

TEST(test_05, basic_test_set) {
    int n = 1;
    int m = 0;
    int result = slicesCount(n, m);
    ASSERT_TRUE(result == 0);
}

TEST(test_06, basic_test_set) {
    int n = 0;
    int m = 1;
    int result = slicesCount(n, m);
    ASSERT_TRUE(result == 0);
}

TEST(test_07, basic_test_set) {
    int n = 1;
    int m = 1;
    int result = slicesCount(n, m);
    ASSERT_TRUE(result == 0);
}

TEST(test_08, basic_test_set) {
    int n = 1;
    int m = 2;
    int result = slicesCount(n, m);
    ASSERT_TRUE(result == 1);
}

TEST(test_09, basic_test_set) {
    int n = 2;
    int m = 1;
    int result = slicesCount(n, m);
    ASSERT_TRUE(result == 1);
}

TEST(test_10, basic_test_set) {
    int n = 3;
    int m = 1;
    int result = slicesCount(n, m);
    ASSERT_TRUE(result == 2);
}

TEST(test_11, basic_test_set) {
    int n = 4;
    int m = 5;
    int result = slicesCount(n, m);
    ASSERT_TRUE(result == 19);
}

int main (int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}