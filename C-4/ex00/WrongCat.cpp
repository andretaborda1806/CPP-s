#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal(), type("WRONG CAT"){
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(), type(copy.type){
    std::cout << "Copy WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy){
    if (this != &copy){
        this->type = copy.type;
    }
    return (*this);
}

std::string WrongCat::getType()const{
    return type;
}

void    WrongCat::makeSound()const{
    std::cout << "Wrong MiauMiauMiau" << std::endl;
}