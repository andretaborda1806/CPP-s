#include "Character.hpp"

Character::Character():_name(""), _inventory{}{}

Character::Character(std::string name): _name(name), _inventory{}{
    std::cout << _name << " foi criado" << std::endl;
}

Character::Character(const Character &copy): _name(copy.getName()), {}

Character::~Character(){}

Character &Character::operator=(const Character &copy){
    if (&copy != this)
        _name = copy.getName();
    return *this;
}

std::string const &Character::getName()const{
    return this->_name;
}

