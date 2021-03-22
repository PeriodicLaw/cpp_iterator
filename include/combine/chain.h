#pragma once
#include "predefine.h"

template<typename Iter1, typename Iter2>
class Chain: public Iterator<typename Iter1::Item, Chain<Iter1, Iter2>> {
    static_assert(std::is_same_v<typename Iter1::Item, typename Iter2::Item>);
    using T = typename Iter1::Item;
public:
    Chain(Iter1 it1, Iter2 it2): it1(it1), it2(it2) {};
    
    Option<T> next() {
        if(auto x = it1.next())
            return std::move(x);
        else
            return it2.next();
    }

private:
    Iter1 it1;
    Iter2 it2;
};