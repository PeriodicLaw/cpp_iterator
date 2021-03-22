#pragma once
#include "iterator.h"

template<typename T>
class RangeIterator: public Iterator<T, RangeIterator<T>> {
public:
    RangeIterator(T begin, T end, T step): cur(begin), end(end), step(step) {}
    
    Option<T> next() {
        if(cur == end)
            return None<T>();
        else{
            T ret = cur;
            cur += step;
            return Some(ret);
        }
    }

private:
    T cur, end, step;
};

template<typename T>
RangeIterator<T> make_range(T begin, T end) {
    return RangeIterator(begin, end, 1);
}

template<typename T>
RangeIterator<T> make_range(T begin, T end, T step) {
    return RangeIterator(begin, end, step);
}