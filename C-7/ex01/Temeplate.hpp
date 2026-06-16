#ifndef tEMEPLATE_HPP
#define TEMEPLATE_HPP

#include <iostream>

template <typename T>
void    iter(T *arr, int len, void (*func)(T &)){
    for (int i = 0; i < len; i++)
        func(&arr[i]);
}

template <typename T>
void    print(T a){
    std::cout << a << std::endl;
}


template <typename T>
void    increment(T a){
    std::cout << a << std::endl;
}

#endif