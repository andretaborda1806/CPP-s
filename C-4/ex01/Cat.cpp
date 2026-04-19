#include "Cat.hpp"

Cat::Cat():Animal(), type("CAT"){
    this->ideas = new Brain();
    //std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy): Animal(){
    this->type = copy.type;
    this->ideas = new Brain();
    this->ideas->setBrain(copy.ideas->getBrain());
    //std::cout << "Copy Cat constructor called" << std::endl;
}

Cat::~Cat(){
    //std::cout << "Cat destructor called" << std::endl;
    delete ideas;
}

Cat &Cat::operator=(const Cat &copy){
    if (this != &copy){
        this->type = copy.type;
        delete this->ideas;
        this->ideas = new Brain();
        this->ideas->setBrain(copy.ideas->getBrain());
    }
    return (*this);
}

std::string Cat::getType()const{
    return type;
}

void    Cat::makeSound()const{
    std::cout << "MiauMiauMiau" << std::endl;
}

std::string *Cat::getIdeas()const{
    return this->ideas->getBrain();
}

void Cat::setIdeas(std::string idea, int index){
    ideas->setIdea(idea, index);
}


