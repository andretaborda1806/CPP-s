#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename U>
void    iter(T *arr, const int len, U func){
    if (!arr)
        return;
    for (int i = 0; i < len; i++)
        func(arr[i]);
}

template <typename T>
void    print(T &a){
    std::cout << a << std::endl;
}

void    uppercase(std::string &str){
    for (int i = 0; i < static_cast<int>(str.length()); i++)
        str[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
}

template <typename T>
void    increment(T &a){
    a+=5;
}

#endif