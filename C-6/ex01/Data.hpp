#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data{
    private:
        std::string _msg;
    public:
        Data();
        Data(std::string msg);
        Data(const Data &copy);
        std::string getData();
        ~Data();
        Data &operator=(const Data &copy);
};

#endif