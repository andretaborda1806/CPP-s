#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>


class Animal{
    public:
        Animal();
        Animal(const Animal &copy);
        virtual ~Animal();
        Animal &operator=(const Animal &copy);
        virtual std::string getType()const;
        virtual void makeSound()const;
        virtual void setIdeas(std::string idea, int index);
        virtual std::string *getIdeas()const;
    private:
        std::string type;
};

#endif