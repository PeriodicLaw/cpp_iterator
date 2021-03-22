#pragma once

template<typename T, typename Derive> class Iterator;

template<typename Iter1, typename Iter2> class Chain;

template<typename Iter> class Enumerate;

template<typename Iter> class Filter;

template<typename Iter> class Flatten;

template<typename U, typename Iter> class Map;

template<typename Iter> class Skip;
template<typename Iter> class SkipWhile;

template<typename Iter> class Take;
template<typename Iter> class TakeWhile;

template<typename Iter1, typename Iter2> class Zip;