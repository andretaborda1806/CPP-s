#include "Cat.hpp"

Cat::Cat():Animal(), type("CAT"){
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy): Animal(), type(copy.type){
    std::cout << "Copy Cat constructor called" << std::endl;
}

Cat::~Cat(){
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy){
    if (this != &copy){
        this->type = copy.type;
    }
    return (*this);
}

std::string Cat::getType()const{
    return type;
}

void    Cat::makeSound()const{
    std::cout << "MiauMiauMiau" << std::endl;
}

