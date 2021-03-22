#include <vector>
#include <iostream>
#include "container.h"
#include "utils.h"
#include "range.h"

int main() {
    std::vector<int> v{1, 2, 3};
    
    foreach(from_container(v), [](int x){
        std::cout << x << " ";
    });
    std::cout << std::endl;
    
    std::cout << "total: " << count(from_container(v)) << std::endl;
    for(int i=0; i<4; i++)
        std::cout << "the " << i << "th element is "
                  << get_nth(from_container(v), i) << std::endl;
    
    std::cout << "the sum is " <<
        fold(from_container(v),
            0,
            [](int x, int y){return x+y;}) << std::endl;

    std::vector<RangeIterator<int>> w{make_range(0, 2), make_range(0, 3)};
    foreach(from_container(w).flatten(), [](int x){
        std::cout << x << " ";
    });
}