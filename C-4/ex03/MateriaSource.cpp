#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    for (int i = 0; i < 4; i++) _inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy){
    for (int i = 0; i < 4; i++) _inventory[i] = NULL;
    *this = copy;
}

MateriaSource::~MateriaSource(){
        for (int i = 0; i < 4; ++i){
        if (_inventory[i]){
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy){
    if (this != &copy){
        for (int i = 0; i < 4; i++){
            if (_inventory[i]){
                delete (_inventory[i]);
                _inventory[i] = NULL;
            }
        }
        for (int i = 0; i < 4; i++){
            if (copy._inventory[i])
                _inventory[i] = copy._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    return *this;
}


void    MateriaSource::learnMateria(AMateria* materia){
    if (!materia){
        std::cout << "Useless ass materia" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++){
        if (!_inventory[i]){
            _inventory[i] = materia->clone();
            delete materia;
            return;
        }
    }
    delete materia;
    std::cout << "Cant learn more! I am tired boss" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type){
    for (int i = 0; i < 4; i++){
        if (_inventory[i] && _inventory[i]->getType() == type)
            return _inventory[i]->clone();
    }
    std::cout << "Dont know what you talking about" << std::endl;
    return NULL;
}