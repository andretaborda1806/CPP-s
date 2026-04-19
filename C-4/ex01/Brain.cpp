#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain default construtor callled" << std::endl;
}

Brain::Brain(const Brain &copy): ideas(copy.ideas){
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain(){
    std::cout << "Brain default destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy){
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &copy)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = copy.ideas[i];
    }
    return *this;
}

std::string *Brain::getBrain(){
    return ideas;
}

void Brain::setBrain(std::string *newIdeas){
    for (int i = 0; i < 100; i++)
        ideas[i] = newIdeas[i];
}

void Brain::setIdea(std::string newIdea, int index){
    ideas[index] = newIdea;
}
