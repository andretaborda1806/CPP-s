#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array{
    private:
        T *_array;
        int _len;
    public:
        Array();
        Array(unsigned int a);
        Array(const Array &copy);
        ~Array();
        Array &operator=(const Array &copy);
        T     &operator[](unsigned int index);
        T     &operator[](unsigned int index)const;
        size()const;
}

#endif