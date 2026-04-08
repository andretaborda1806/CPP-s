#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){}

ClapTrap::ClapTrap(std::string name): name(name), HitPts(10), EnergyPts(10), AttackDmg(0){
    std::cout << "ClapTrap " << name << " was created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy): name(copy.name), HitPts(copy.HitPts), EnergyPts(copy.EnergyPts), AttackDmg(copy.AttackDmg){
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap " << name << " was destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &copy){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        name = copy.name;
        HitPts = copy.HitPts;
        EnergyPts = copy.EnergyPts;
        AttackDmg = copy.AttackDmg;
    }
    return *this;
}

void    ClapTrap::attack(const std::string & target){
    switch (checker())
    {
    case 0:
        std::cout << "ClapTrap " << getName() << " attacks " << target << " causing " << getAttackDmg() << " points of damage" << std::endl;
        EnergyPts--;
        break;
    case 1:
        std::cout << "ClapTrap" << getName() << " doesnt have enought energy to attack " << target << std::endl;
        break;
    case 2:
        std::cout << "ClapTrap" << getName() << " has died therefore is unable to attack " << target << std::endl;
        break;
    }
}

void    ClapTrap::takeDamage(unsigned int amount){
    std::cout << "ClapTrap " << getName() << " took " << amount << " of damage" << std::endl;
    HitPts -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount){
    switch (checker())
    {
    case 0:
        std::cout << "ClapTrap" << getName() << " repaired " << amount << " hit points" << std::endl;
        EnergyPts--;
        break;
    case 1:
        std::cout << "ClapTrap" << getName() << " doesnt have enought energy points to repair" << std::endl;
        break;
    case 2:
        std::cout << "ClapTrap" << getName() << " has died therefore is unable to repair" << std::endl;
    }
}

std::string ClapTrap::getName() const{
    return name;
}

int ClapTrap::getHitPts() const{
    return HitPts;
}

int ClapTrap::getEnergyPts() const{
    return EnergyPts;
}

int ClapTrap::getAttackDmg()const{
    return AttackDmg;
}

int ClapTrap::checker() const{
    if (getEnergyPts() && getHitPts())
        return 0;
    else if (getEnergyPts() <= 0 && getHitPts())
        return 1;
    else if (getHitPts() <= 0 && getEnergyPts())
        return 2;
    return 0;
}