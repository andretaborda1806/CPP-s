#include "Fixed.hpp"

Fixed::Fixed(void): _fixedpointvalue(0){
    std::cout<< "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy): _fixedpointvalue(copy._fixedpointvalue){
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->setFixedValue(copy.getFixedValue());
    return (*this);
}

void    Fixed::setFixedValue(const int rawbits){
    std::cout << "FixedValue set" << std::endl;
    this->_fixedpointvalue = rawbits;
}

int     Fixed::getFixedValue() const {
    std::cout << "getFixedValue member function called" << std::endl;
    return (this->_fixedpointvalue);
}