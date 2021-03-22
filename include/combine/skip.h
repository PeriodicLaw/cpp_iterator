#pragma once
#include <functional>
#include "predefine.h"

template<typename Iter>
class Skip: public Iterator<typename Iter::Item, Skip<Iter>> {
    using T = typename Iter::Item;
public:
    Skip(Iter it, size_t n): it(it) {
        while(n--)
            this->it.next();
    }
    
    Option<T> next() {
        return it.next();
    }
private:
    Iter it;
};

template<typename Iter>
class SkipWhile: public Iterator<typename Iter::Item, SkipWhile<Iter>> {
    using T = typename Iter::Item;
public:
    SkipWhile(Iter it, std::function<bool(T)> pred): it(it), started(false), pred(pred) {}

    Option<T> next() {
        if(started)
            return it.next();
        else {
            started = false;
            while(auto x = it.next())
                if(!pred(x.unwrap()))
                    return x;
            return None<T>();
        }
    }
private:
    Iter it;
    bool started;
    std::function<bool(T)> pred;
};