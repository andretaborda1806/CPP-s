#include "AMateria.hpp"

AMateria::AMateria(): _type(" "){}

AMateria::AMateria(const AMateria &copy): _type(copy._type){}

AMateria::AMateria(std::string const &type): _type(type){}

AMateria::~AMateria(){}

AMateria &AMateria::operator=(const AMateria &copy){
    if (&copy != this)
        this->_type = copy._type;
    return (*this);
}

std::string const &AMateria::getType()const{
    return (this->_type);
}

void AMateria::use(ICharacter &target){}