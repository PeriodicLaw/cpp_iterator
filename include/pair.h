#pragma once
#include <iostream>

template<typename T1, typename T2>
class Pair {
public:
    Pair(T1 x, T2 y): x(x), y(y) {}

    T1 x;
    T2 y;
};

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, Pair<T1, T2> p) {
    return os << "(" << p.x << ", " << p.y << ")";
}