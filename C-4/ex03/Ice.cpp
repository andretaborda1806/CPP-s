#include "Ice.hpp"

Ice::Ice(): AMateria("ice"){}

Ice::Ice(const Ice &copy): AMateria(copy.getType()){}

Ice::~Ice(){}

Ice &Ice::operator=(const Ice &copy){
    if (this != &copy)
        AMateria::operator=(copy);
    return (*this);
}

Ice *Ice::clone()const{
    std::cout << "Clone " << _type << std::endl;
    return (new Ice());
}

void Ice::use(ICharacter &target){
    std::cout << "Ice: * shoots an ice bolt at *" << target.getName() << std::endl;
}