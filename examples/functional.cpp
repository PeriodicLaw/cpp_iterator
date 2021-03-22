#include <iostream>
#include "range.h"

template<typename Iter>
void print(Iter it) {
    while(auto x = it.next()) {
        std::cout << x.unwrap() << " ";
    }
    std::cout << std::endl;
}

int main() {
    auto it = make_range(5, 10);
    print(it);
    
    print(it.chain(make_range(0, 5)));
    print(it.enumerate());
    print(it.filter([](int x){
        return x%2 == 1;
    }));
    print(it.map([](int x){
        return x*x;
    }));
    print(it.flat_map([](int x){
        return make_range(0, x);
    }));
    print(it.zip(make_range(0, 5)));
    
    print(it.take(2));
    print(it.skip(2));
    print(it.take_while([](int x){
        return x<8;
    }));
    print(it.skip_while([](int x){
        return x<8;
    }));
}