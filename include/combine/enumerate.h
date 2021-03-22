#pragma once
#include "predefine.h"
#include "pair.h"

template<typename Iter>
class Enumerate: public Iterator<Pair<size_t, typename Iter::Item>, Enumerate<Iter>> {
    using T = typename Iter::Item;
public:
    Enumerate(Iter it): it(it), cnt(0) {}
    
    auto next() {
        if(auto x = it.next())
            return Some(Pair(cnt++, x.unwrap()));
        else
            return None<Pair<size_t, T>>();
    }

private:
    Iter it;
    size_t cnt;
};