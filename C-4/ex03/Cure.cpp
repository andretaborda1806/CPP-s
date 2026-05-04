#include "Cure.hpp"

Cure::Cure(): AMateria("cure"){}

Cure::Cure(const Cure &copy): AMateria(copy.getType()){}

Cure::~Cure(){}

Cure &Cure::operator=(const Cure &copy){
    if (this != &copy)
        AMateria::operator=(copy);
    return (*this);
}

Cure *Cure::clone()const{
    std::cout << "Clone " << _type << std::endl;
    return (new Cure());
}

void Cure::use(ICharacter &target){
    std::cout << "Cure: * heals  " << target.getName() << "'s wounds *" << std::endl;
}