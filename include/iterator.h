#pragma once
#include "option.h"
#include "combine/predefine.h"

template<typename T, typename Derive>
class Iterator {
public:
    using Item = T;
    Iterator() {
        static_assert(std::is_same_v<Option<T>, decltype(derive_this()->next())>);
    }

    template<typename Iter>
    auto chain(Iter it) {
        return Chain<Derive, Iter>(*derive_this(), it);
    }

    auto enumerate() {
        return Enumerate<Derive>(*derive_this());
    }
    
    auto filter(std::function<bool(T)> pred) {
        return Filter<Derive>(*derive_this(), pred);
    }
    
    auto flatten() {
        return Flatten<Derive>(*derive_this());
    }

    template<typename F>
    auto flat_map(F f) {
        return map(f).flatten();
    }

    template<typename F>
    auto map(F f) {
        return Map<decltype(f(std::declval<T>())), Derive>(*derive_this(), f);
    }
    
    auto take(size_t n) {
        return Take<Derive>(*derive_this(), n);
    }
    
    auto take_while(std::function<bool(T)> pred) {
        return TakeWhile<Derive>(*derive_this(), pred);
    }
    
    auto skip(size_t n) {
        return Skip<Derive>(*derive_this(), n);
    }
    
    auto skip_while(std::function<bool(T)> pred) {
        return SkipWhile<Derive>(*derive_this(), pred);
    }

    template<typename Iter>
    auto zip(Iter it) {
        return Zip<Derive, Iter>(*derive_this(), it);
    }
    
    std::vector<T> collect() {
        std::vector<T> v;
        while(auto x = derive_this()->next())
            v.push_back(x.unwrap());
        return v;
    }

private:
    Derive *derive_this() {
        return static_cast<Derive*>(this);
    }
};

#include "combine/chain.h"
#include "combine/enumerate.h"
#include "combine/filter.h"
#include "combine/flatten.h"
#include "combine/map.h"
#include "combine/skip.h"
#include "combine/take.h"
#include "combine/zip.h"