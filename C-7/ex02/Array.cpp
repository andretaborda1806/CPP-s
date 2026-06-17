#include "Array.hpp"

Array::Array(): _array(NULL), _len(0){}

Array::Array(unsigned int len): _len(len){
    for (int i = 0; i < len; i++)
        _array[i] = " ";
}

Array::Array(const Array &copy): _len(copy._len){
    for (int i = 0; i < _len; i++)
        this->_array[i] = copy._array[i];
}

Array::~Array(){}

Array &Array::operator=(const Array &copy){
    if (this != &copy){
        _len = copy._len;
        delete[] this->_array;
        if (this->_len == 0)
            this->_array = NULL;
        else{
            this->array = new T[this->_len]();
            for (int i = 0; i < _len; i++){
                _array[i] = copy._array[i];
            }
        }
    }
    return *this;
}

T   &Array::operator[](unsigned int index){
    if (index < this->_len)
        return _array[index];
    else
        return NULL;
}