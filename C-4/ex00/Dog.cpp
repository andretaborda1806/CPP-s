#include "Dog.hpp"

Dog::Dog():Animal(), type("DOG"){
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy): Animal(), type(copy.type){
    std::cout << "Copy Dog constructor called" << std::endl;
}

Dog::~Dog(){
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy){
    if (this != &copy){
        this->type = copy.type;
    }
    return (*this);
}

std::string Dog::getType()const{
    return type;
}

void    Dog::makeSound()const{
    std::cout << "ÃoÃoÃoÃo" << std::endl;
}

