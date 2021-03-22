#pragma once

template<typename Iter>
class Flatten: public Iterator<typename Iter::Item::Item, Flatten<Iter>> {
    using IterInner = typename Iter::Item;
    using T = typename IterInner::Item;
public:
    Flatten(Iter it): it(it), peek(None<IterInner>()) {}
    
    Option<T> next() {
        while(true) {
            if(peek.is_some()) {
                auto& it_inner = peek.unwrap_ref();
                if(auto x = it_inner.next())
                    return Some(x.unwrap());
            }
            if(auto it_inner = it.next())
                peek = it_inner;
            else
                return None<T>();
        }
    }
    
private:
    Iter it;
    Option<IterInner> peek;
};