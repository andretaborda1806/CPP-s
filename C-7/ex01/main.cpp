#include "Iter.hpp"

int main(void){
    
    std::cout << "==========INT=========="<< std::endl;
    
    int arr[5] = {1, 5, 2, -2, 4};
    std::cout << "Original: "<< std::endl;
    ::iter(arr, 5, print<int>);
    std::cout << std::endl;
    ::iter(arr, 5, increment<int>);
    std::cout << "incrmented: "<< std::endl;
    ::iter(arr, 5, print<int>);
    std::cout << std::endl;


    
    std::cout << "==========const INT=========="<< std::endl;
    
    const int const_arr[5] = {9, 4, 2, -2, 4};
    std::cout << "Original: "<< std::endl;
    ::iter(const_arr, 5, print<const int>);
    std::cout << std::endl;

    
    std::cout << "==========STRING=========="<< std::endl;
    
    std::string str[3] = {"ola", "tudo", "bem?"};
    std::cout << "Original: " << std::endl;
    ::iter(str, 3, print<std::string>);
    std::cout << std::endl;
    ::iter(str, 3, uppercase);
    std::cout << "Upper: "<< std::endl;
    ::iter(str, 3, print<std::string>);
    std::cout << std::endl;

    
    std::cout << "==========CHARS=========="<< std::endl;
    
    char    c[7] = {'f', '7', 's', 'I', 'z', ')', '?'};
    std::cout << "Original: " << std::endl;
    ::iter(c, 7, print<char>);
    ::iter(c, 7, increment<char>);
    std::cout << std::endl;
    std::cout << "incrmented: "<< std::endl;
    ::iter(c, 7, print<char>);
    std::cout << std::endl;
    return 0;

}