#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data{
    private:
        std::string msg;
    public:
        Data();
        Data(const Data &copy);
        ~Data();
        Data &operator=(const Data &copy);
};

#endif