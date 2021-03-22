#pragma once
#include <functional>
#include "predefine.h"

template<typename U, typename Iter>
class Map: public Iterator<U, Map<U, Iter>> {
    using T = typename Iter::Item;
public:
    template<typename F> Map(Iter it, F f): it(it), f(f) {}
    
    Option<U> next() {
        if(auto x = it.next())
            return Some(f(x.unwrap()));
        else
            return None<U>();
    }

private:
    Iter it;
    std::function<U(T)> f;
};