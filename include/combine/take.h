#pragma once
#include <functional>
#include "predefine.h"

template<typename Iter>
class Take: public Iterator<typename Iter::Item, Take<Iter>> {
    using T = typename Iter::Item;
public:
    Take(Iter it, size_t n): it(it), cnt(n) {}

    Option<T> next() {
        if(cnt) {
            cnt--;
            return it.next();
        } else
            return None<T>();
    }
private:
    Iter it;
    size_t cnt;
};

template<typename Iter>
class TakeWhile: public Iterator<typename Iter::Item, TakeWhile<Iter>> {
    using T = typename Iter::Item;
public:
    TakeWhile(Iter it, std::function<bool(T)> pred): it(it), pred(pred), ended(false) {}

    Option<T> next() {
        if(ended)
            return None<T>();
        else {
            auto x = it.next();
            if(x && pred(x.unwrap()))
                return x;
            else {
                ended = true;
                return None<T>();
            }
        }
    }
private:
    Iter it;
    std::function<bool(T)> pred;
    bool ended;
};