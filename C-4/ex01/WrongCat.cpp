#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal(), type("WrongCat"){
    this->ideas = new Brain();
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(){
    this->type = copy.type;
    this->ideas = new Brain();
    this->ideas->setBrain(copy.ideas->getBrain());
    std::cout << "Copy WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat destructor called" << std::endl;
    delete ideas;
}

WrongCat &WrongCat::operator=(const WrongCat &copy){
    if (this != &copy){
        this->type = copy.type;
        this->ideas = new Brain();
        this->ideas->setBrain(copy.ideas->getBrain());
    }
    return (*this);
}

std::string WrongCat::getType()const{
    return type;
}

void    WrongCat::makeSound()const{
    std::cout << "MiauMiauMiau" << std::endl;
}

std::string *WrongCat::getIdeas()const{
    return this->ideas->getBrain();
}

void WrongCat::setIdeas(std::string idea, int index){
    ideas->setIdea(idea, index);
}


