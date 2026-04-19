#include "Animal.hpp"

Animal::Animal(){
    //std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy): type(copy.type){
    //std::cout << "Copy Animal constructor called" << std::endl;
}

Animal::~Animal(){
    //std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy){
    if (this != &copy){
        this->type = copy.type;
    }
    return (*this);
}

std::string Animal::getType()const{
    return type;
}

void    Animal::makeSound()const{
    std::cout << "***Animal sounds***" << std::endl;
}

void    Animal::setIdeas(std::string ideas, int index){
    (void)ideas;
    (void)index;
}

std::string *Animal::getIdeas()const{
    return NULL;
}

