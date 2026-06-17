#include "Data.hpp"

Data::Data(){}

Data::Data(std::string msg): _msg(msg){}

Data::Data(const Data &copy): _msg(copy._msg){}

Data::~Data(){}

Data &Data::operator=(const Data &copy){
    if (this != &copy)
        this->_msg = copy._msg;
    return *this;
}

std::string Data::getData(){
    return this->_msg;
}