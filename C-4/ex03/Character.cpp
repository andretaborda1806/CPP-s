#include "Character.hpp"

Character::Character(): _name(""){
    for (int i = 0; i < 4; ++i) _inventory[i] = NULL;
    for (int i = 0; i < 100; ++i) _onThefloor[i] = NULL;
}

Character::Character(std::string name): _name(name){
    for (int i = 0; i < 4; ++i) _inventory[i] = NULL;
    for (int i = 0; i < 100; ++i) _onThefloor[i] = NULL;
    std::cout << _name << " foi criado" << std::endl;
}

Character::Character(const Character &copy): _name(copy.getName()){
    for (int i = 0; i < 4; ++i) _inventory[i] = NULL;
    for (int i = 0; i < 100; ++i) _onThefloor[i] = NULL;
    for (int i = 0; i < 4; ++i){
        if (copy._inventory[i])
            _inventory[i] = copy._inventory[i]->clone();
    }
    for (int i = 0; i < 100; ++i){
        if (copy._onThefloor[i])
            _onThefloor[i] = copy._onThefloor[i]->clone();
    }
}

Character::~Character(){
    for (int i = 0; i < 4; ++i){
        if (_inventory[i]){
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    }
    for (int i = 0; i < 100; ++i){
        if (_onThefloor[i]){
            delete _onThefloor[i];
            _onThefloor[i] = NULL;
        }
    }
}

Character &Character::operator=(const Character &copy){
    if (&copy != this){
        _name = copy.getName();
        for (int i = 0; i < 4; ++i){
            if (_inventory[i]){
                delete _inventory[i];
                _inventory[i] = NULL;
            }
        }
        for (int i = 0; i < 4; ++i){
            if (copy._inventory[i])
                _inventory[i] = copy._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
        for (int i = 0; i < 100; ++i){
            if (_onThefloor[i]){
                delete _onThefloor[i];
                _onThefloor[i] = NULL;
            }
        }
        for (int i = 0; i < 100; ++i){
            if (copy._onThefloor[i])
                _onThefloor[i] = copy._onThefloor[i]->clone();
            else
                _onThefloor[i] = NULL;
        }
    }
    return *this;
}

std::string const &Character::getName()const{
    return this->_name;
}

void Character::equip(AMateria *m){
    if (!m)
        return;
    for (int i = 0; i < 4; ++i){
        if (!_inventory[i]){
            _inventory[i] = m;
            std::cout << this->getName() << " equiped " << m->getType() << std::endl;
            return;
        }
    }
}

void Character::unequip(int idx){
    if (idx < 0 || idx >= 4)
        return;
    if (!_inventory[idx])
        return;
    for (int i = 0; i < 100; ++i){
        if (!_onThefloor[i]){
            _onThefloor[i] = _inventory[idx];
            std::cout << this->getName() << " droped " << _inventory[idx]->getType() << " on the floor" << std::endl;
            _inventory[idx] = NULL;
            return;
        }
    }
}

void Character::use(int idx, ICharacter &target){
    if (idx < 0 || idx >= 4)
        return;
    if (!_inventory[idx])
        return;
    _inventory[idx]->use(target);
}
