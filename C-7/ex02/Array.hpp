#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
class Array{
    private:
        T *_array;
        int _len;
    public:

        class InvalidSize: public std::exception{
            public:
                virtual const char * what() const throw(){
                    return ("Invalid size!");
                }
        };

        Array(): _array(NULL), _len(0){}
        
        Array(int len): _len(len){
            this->_array = new T[this->_len];
        }

        Array(const Array &copy): _len(copy._len){
            this->_array = new T[this->_len];
            for (int i = 0; i < _len; i++)
                this->_array[i] = copy._array[i];
        }

        ~Array(){delete[] this->_array;}

        Array &operator=(const Array &copy){
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

        T   &operator[](int index){
            if (index < 0 || index >= _len)
                throw InvalidSize();
            return _array[index];
        }

        T   &operator[](int index)const{
            if (index < 0 || index >= _len)
                throw InvalidSize();
            return _array[index];
        }

        int    size(){
            return _len;
        }
};

#endif