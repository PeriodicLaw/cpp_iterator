#pragma once
#include <functional>
#include "predefine.h"

template<typename Iter>
class Filter: public Iterator<typename Iter::Item, Filter<Iter>> {
    using T = typename Iter::Item;
public:
    Filter(Iter it, std::function<bool(T)> pred): it(it), pred(pred) {}
    
    Option<T> next() {
        while(auto x = it.next()) {
            if(pred(x.unwrap()))
                return x;
        }
        return None<T>();
    }

private:
    Iter it;
    std::function<bool(T)> pred;
};