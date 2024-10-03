#include <gtest/gtest.h>
#include <stdexcept>
#include "../include/Six.h"

TEST(default_constructor, default_constructor) {
    Six number(1, '0');
    Six numberDefault;
    
    bool result = number == numberDefault;    
    ASSERT_TRUE(result == true);
}

TEST(length_constructor, incorrect_digit) {
    EXPECT_THROW(Six number(1, '6'), std::invalid_argument);
    EXPECT_THROW(Six number(1, 'a'), std::invalid_argument);
}

TEST(length_constructor, incorrect_length) {
    EXPECT_THROW(Six number(0, '0'), std::invalid_argument);
}

TEST(length_constructor, leading_zeros) {
    Six numberMultiZeros(2, '0');
    Six numberZero;

    bool result = numberMultiZeros == numberZero;    
    ASSERT_TRUE(result == true);
}

TEST(init_list_constructor, init_list_constructor) {
    Six numberRef(3, '1');
    Six number{'1', '1', '1'};

    bool result = number == numberRef;    
    ASSERT_TRUE(result == true);
}

TEST(init_list_constructor, incorrect_digit) {
    std::initializer_list<unsigned char> num1List = {'6'};
    std::initializer_list<unsigned char> num2List = {'1', '2', '6', '0'};
    std::initializer_list<unsigned char> num3List = {'1', '2', '5', '0', '6'};

    EXPECT_THROW(Six number{num1List}, std::invalid_argument);
    EXPECT_THROW(Six number{num2List}, std::invalid_argument);
    EXPECT_THROW(Six number{num3List}, std::invalid_argument);
}

TEST(init_list_constructor, leading_zeros) {
    Six number1{'0', '0', '1', '2', '3', '0'};
    Six number2{'1', '2', '3', '0'};

    bool result = number1 == number2;    
    ASSERT_TRUE(result == true);
}

TEST(str_constructor, str_constructor) {
    Six numberRef{'1', '2', '3'};
    Six number("123");

    bool result = number == numberRef;
    ASSERT_TRUE(result == true);
}

TEST(str_constructor, incorrect_digit) {
    EXPECT_THROW(Six number("6"), std::invalid_argument);
    EXPECT_THROW(Six number("1260"), std::invalid_argument);
    EXPECT_THROW(Six number("12506"), std::invalid_argument);
}

TEST(str_constructor, leading_zeros) {
    Six number1("001230");
    Six number2("1230");

    bool result = number1 == number2;    
    ASSERT_TRUE(result == true);
}

TEST(copy_constructor, copy_constructor) {
    Six number1("1234");
    Six number2{number1};

    bool result = number1 == number2;
    ASSERT_TRUE(result == true);
}

TEST(move_constructor, move_constructor) {
    Six numberOriginal("1234");
    Six numberOriginalCopy{numberOriginal};
    Six number{std::move(numberOriginal)};

    bool result = numberOriginalCopy == numberOriginalCopy;
    ASSERT_TRUE(result == true);
}

TEST(assigment, common) {
    Six number1;
    Six number2("1234");

    number1 = number2;
    
    bool result = number1 == number2;
    ASSERT_TRUE(result == true);
}

TEST(assigment, self_assigment_error) {
    Six number;
    EXPECT_THROW(number = number, std::logic_error);
}

TEST(less, less) {
    Six number("20");

    Six numberLessLen("1");
    Six numberLess("15");
    Six numberEqual("20");
    Six numberMore("21");
    Six numberMoreLen("111");

    int resLessLen = numberLessLen < number;
    int resLess = numberLess < number;
    int resEqual = numberEqual < number;
    int resMore = numberMore < number;
    int resMoreLen = numberMoreLen < number;

    ASSERT_TRUE(resLessLen == true);
    ASSERT_TRUE(resLess == true);
    ASSERT_TRUE(resEqual == false);
    ASSERT_TRUE(resMore == false);
    ASSERT_TRUE(resMoreLen == false);
}

TEST(more, more) {
    Six number("20");

    Six numberLessLen("1");
    Six numberLess("15");
    Six numberEqual("20");
    Six numberMore("21");
    Six numberMoreLen("111");

    int resLessLen = numberLessLen > number;
    int resLess = numberLess > number;
    int resEqual = numberEqual > number;
    int resMore = numberMore > number;
    int resMoreLen = numberMoreLen > number;

    ASSERT_TRUE(resLessLen == false);
    ASSERT_TRUE(resLess == false);
    ASSERT_TRUE(resEqual == false);
    ASSERT_TRUE(resMore == true);
    ASSERT_TRUE(resMoreLen == true);
}

TEST(add, zero) {
    Six number1("1234");
    Six number1Copy{number1};
    Six numberZero;

    number1 += numberZero;

    int result = number1 == number1Copy;
    ASSERT_TRUE(result == true);
}

TEST(add, common) {
    Six number1("1023");
    Six number2("35");
    Six numberRes("1102");

    number1 += number2;

    int result = number1 == numberRes;
    ASSERT_TRUE(result == true);
}

TEST(add, extend) {
    Six number1("30001");
    Six number2("40013");
    Six numberRes("110014");

    number1 += number2;

    int result = number1 == numberRes;
    ASSERT_TRUE(result == true);
}

TEST(add, long_extend) {
    Six number1("55555");
    Six number2("1");
    Six numberRes("100000");

    number1 += number2;

    int result = number1 == numberRes;
    ASSERT_TRUE(result == true);
}

TEST(sub, zero) {
    Six number1("1234");
    Six number1Copy{number1};
    Six numberZero;

    number1 -= numberZero;

    int result = number1 == number1Copy;
    ASSERT_TRUE(result == true);
}

TEST(sub, common) {
    Six number1("1023");
    Six number2("14");
    Six numberRes("1005");

    number1 -= number2;

    int result = number1 == numberRes;
    ASSERT_TRUE(result == true);
}

TEST(sub, reduce) {
    Six number1("10001");
    Six number2("2");
    Six numberRes("5555");

    number1 -= number2;

    int result = number1 == numberRes;
    ASSERT_TRUE(result == true);
}

TEST(sub, long_reduce) {
    Six number1("100000");
    Six number2("55555");
    Six numberRes("1");

    number1 -= number2;

    int result = number1 == numberRes;
    ASSERT_TRUE(result == true);
}

TEST(sub, less_error) {
    Six number1("1");
    Six number2("1000");

    EXPECT_THROW(number1 -= number2, std::logic_error);
}

int main (int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}