#pragma once
#include "predefine.h"
#include "pair.h"

template<typename Iter1, typename Iter2>
class Zip: public Iterator<Pair<typename Iter1::Item, typename Iter2::Item>, Zip<Iter1, Iter2>> {
    using T1 = typename Iter1::Item;
    using T2 = typename Iter2::Item;
public:
    Zip(Iter1 it1, Iter2 it2): it1(it1), it2(it2) {}

    Option<Pair<T1, T2>> next() {
        auto x = it1.next();
        auto y = it2.next();
        if(x && y)
            return Some(Pair(x.unwrap(), y.unwrap()));
        else
            return None<Pair<T1, T2>>();
    }

private:
    Iter1 it1;
    Iter2 it2;
};