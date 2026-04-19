#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal{
    public:
        Dog();
        Dog(const Dog &copy);
        ~Dog();
        Dog &operator=(const Dog &copy);
        std::string getType()const;
        void makeSound();
        std::string *getIdeas()const;
        void setIdeas(std::string idea, int index);
    private:
        std::string type;
        Brain *ideas;
};

#endif