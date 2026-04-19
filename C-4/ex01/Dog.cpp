#include "Dog.hpp"

Dog::Dog():Animal(), type("Dog"){
    this->ideas = new Brain();
    //std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy): Animal(){
    this->type = copy.type;
    this->ideas = new Brain();
    this->ideas->setBrain(copy.ideas->getBrain());
    //std::cout << "Copy Dog constructor called" << std::endl;
}

Dog::~Dog(){
    //std::cout << "Dog destructor called" << std::endl;
    delete ideas;
}

Dog &Dog::operator=(const Dog &copy){
    if (this != &copy){
        this->type = copy.type;
        this->ideas = new Brain();
        this->ideas->setBrain(copy.ideas->getBrain());
    }
    return (*this);
}

std::string Dog::getType()const{
    return type;
}

void    Dog::makeSound()const{
    std::cout << "Ãoãoãoãoãoãoãoão" << std::endl;
}

std::string *Dog::getIdeas()const{
    return this->ideas->getBrain();
}

void Dog::setIdeas(std::string idea, int index){
    ideas->setIdea(idea, index);
}




