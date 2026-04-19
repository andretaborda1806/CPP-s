#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{
    public:
        Cat();
        Cat(const Cat &copy);
        ~Cat();
        Cat &operator=(const Cat &copy);
        std::string getType()const;
        void makeSound();
        std::string *getIdeas()const;
        void setIdeas(std::string idea, int index);
    private:
        std::string type;
        Brain *ideas;
};

#endif