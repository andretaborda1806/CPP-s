#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter{
    private:
        std::string _name;
        AMateria* _inventory[4];
        AMateria* _onThefloor[100];
    public:
        Character();
        Character(std::string name);
        Character(const Character &copy);
        ~Character();
        Character &operator=(const Character &copy);
        std::string const &getName()const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};

#endif