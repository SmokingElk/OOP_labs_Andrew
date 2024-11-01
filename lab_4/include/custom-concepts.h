#pragma once
#include <concepts>
#include "rgb-24.h"

template <class T> 
concept Signable = std::is_arithmetic_v<T> && requires () { 
    requires (T(-1) < T(0)); 
};

template <class T>
concept Arithmetic = Signable<T> && !(std::is_same_v<T, char> || 
    std::is_same_v<T, bool> || 
    std::is_same_v<T, char16_t> || 
    std::is_same_v<T, char32_t>);

template <class T>
concept RealType = std::is_same_v<double, T> || std::is_same_v<float, T>;

template <class T>
concept PrintColor = requires (T a, RGB24 b) {
    { a << b } -> std::same_as<T>;
};