#include "Character.hpp"

Character::Character():_name(""), _inventory{}, _onThefloor{}{}

Character::Character(std::string name): _name(name), _inventory{}, _onThefloor{}{
    std::cout << _name << " foi criado" << std::endl;
}

Character::Character(const Character &copy): _name(copy.getName()), _inventory{}, _onThefloor{}{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i]){
            delete (_inventory[i]);
            _inventory[i] = NULL;
        }
        _inventory[i] = copy._inventory[i]->clone();
    }
}

Character::~Character(){
    for (int i = 0; i < 4;i++){
        if (_inventory[i])
            delete(_inventory[i]);
    }
}

Character &Character::operator=(const Character &copy){
    if (&copy != this)
    {
        _name = copy.getName();
        for (int i = 0; i < 4; i++){
            if (_inventory[i]){
                delete (_inventory[i]);
                _inventory[i] = NULL;
            }

        }
        for (int i = 0; i < 4; i++)
            _inventory[i] = copy._inventory[i]->clone();
        for (int i = 0; i < 100; i++){
            if (_onThefloor[i]){
                delete _onThefloor[i];
                _onThefloor[i] = NULL;
            }
        }
    }
    return *this;
}

std::string const &Character::getName()const{
    return this->_name;
}

void Character::equip(AMateria *m){
    for (int i = 0; i < 4; i++){
        if (!_inventory[i]){
            _inventory[i] = m;
            return;
        }
    }
    std::cout << "Cant equip " << m->getType() << " beacause the inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx > 4)
        std::cout << "My pockets aint that deep fam" << std::endl;
    if (!_inventory[idx])
        std::cout << "inventory slot is already empty" << std::endl;
    else{
        std::cout << this->getName() << " droped " << this->_inventory[idx]->getType() << " on the floor" << std::endl;
        for (int i = 0; i < 100; i++)
        {
            if (_onThefloor[i]){
                _onThefloor[i] = _inventory[i];
                _inventory[i] = NULL;
            }
        }
    }
}

void    Character::use(int idx, ICharacter &target){
    /*tomorrow*/
}
