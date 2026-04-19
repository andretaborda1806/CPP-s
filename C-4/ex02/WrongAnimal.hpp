#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &copy);
        virtual ~WrongAnimal();
        WrongAnimal &operator=(const WrongAnimal &copy);
        virtual std::string getType()const;
        virtual void makeSound()const;
    private:
        std::string type;
};

#endif