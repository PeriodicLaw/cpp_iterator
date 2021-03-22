#pragma once
#include "iterator.h"

template<typename T, typename Inner>
class ContainerIterator: public Iterator<T, ContainerIterator<T, Inner>> {
public:
    ContainerIterator(Inner begin, Inner end): inner(begin), end(end) {}
    
    Option<T> next() {
        if(inner == end)
            return None<T>();
        else{
            T data = *inner;
            ++inner;
            return Some(data);
        }
    }

private:
    Inner inner, end;
};

template<
    typename Container,
    typename Inner = decltype(std::begin(std::declval<Container>())),
    typename T = std::decay_t<decltype(*std::declval<Inner>())>>
ContainerIterator<T, Inner> from_container(Container container) {
    return ContainerIterator<T, Inner>(std::begin(container), std::end(container));
}