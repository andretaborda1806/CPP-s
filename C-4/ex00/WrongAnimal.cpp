#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy): type(copy.type){
    std::cout << "Copy WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy){
    if (this != &copy){
        this->type = copy.type;
    }
    return (*this);
}

std::string WrongAnimal::getType()const{
    return type;
}

void    WrongAnimal::makeSound()const{
    std::cout << "***WrongAnimal sounds***" << std::endl;
}