#pragma once
#include <functional>
#include <memory>

template<typename T> class Option;
template<typename T> Option<T> Some(T);
template<typename T> Option<T> None();

class UnwrapException: std::exception {};

template<typename T> class Option {
public:
    Option() = delete;
    
    Option(const Option& x) {
        if(x.inner) {
            inner = new T(*x.inner);
        } else {
            inner = nullptr;
        }
    }
    
    Option& operator=(const Option& x) {
        if(x.inner != inner) {
            if (x.inner) {
                inner = new T(*x.inner);
            } else {
                inner = nullptr;
            }
        }
        return *this;
    }
    
    ~Option() {
        delete inner;
    }
    
    bool is_some() const {
        return inner;
    }
    
    T unwrap() const {
        if(inner)
            return *inner;
        else
            throw UnwrapException();
    }

    T& unwrap_ref() {
        if(inner)
            return *inner;
        else
            throw UnwrapException();
    }
    
    operator bool() const {
        return is_some();
    }

    template<typename U> friend Option<U> Some(U);
    template<typename U> friend Option<U> None();
    
private:
    explicit Option(T* inner): inner(inner) {}
    T *inner;
};

template<typename T>
Option<T> Some(T data) {
    return Option<T>(new T(data));
}

template<typename T>
Option<T> None() {
    return Option<T>(nullptr);
}

template<typename U>
std::ostream& operator<<(std::ostream& os, Option<U> x) {
    if(x.is_some())
        return os << "Some(" << x.unwrap() << ")";
    else
        return os << "None";
}
