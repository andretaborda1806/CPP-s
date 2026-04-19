#ifndef WRONGCat_HPP
#define WRONGCat_HPP

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat: public WrongAnimal{
    public:
        WrongCat();
        WrongCat(const WrongCat &copy);
        ~WrongCat();
        WrongCat &operator=(const WrongCat &copy);
        std::string getType()const;
        void makeSound()const;
        std::string *getIdeas()const;
        void setIdeas(std::string idea, int index);
    private:
        std::string type;
        Brain *ideas;
};

#endif