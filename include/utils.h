#pragma once
#include <functional>
#include "iterator.h"

template<typename Iter>
void foreach(Iter it, std::function<void(typename Iter::Item)> f) {
    while(auto x = it.next())
        f(x.unwrap());
}

template<typename Iter>
size_t count(Iter it) {
    size_t cnt = 0;
    while(it.next().is_some())
        cnt++;
    return cnt;
}

template<typename Iter>
Option<typename Iter::Item> get_nth(Iter it, size_t n) {
    while(n--)
        it.next();
    return it.next();
}

template<typename T, typename F, typename Iter>
T fold(Iter it, T init, F acc) {
    T ans = init;
    while(auto x = it.next())
        ans = acc(ans, x.unwrap());
    return ans;
}