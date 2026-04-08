#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
    std::cout << "DiamondTrap deafult constructor called" << std::endl;
    HitPts = 100;
    EnergyPts = 50;
    AttackDmg = 30;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + " ClapTrap"), name(name){
    std::cout << "DiamondTrap " << name << " was created" << std::endl;
    HitPts = 100;
    EnergyPts = 50;
    AttackDmg = 30;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap " << this->getName() << " was destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
  : ClapTrap(copy.ClapTrap::getName()),
    ScavTrap(copy),
    FragTrap(copy), 
    name(copy.name){
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    name = copy.name;
    HitPts = copy.HitPts;
    EnergyPts = copy.EnergyPts;
    AttackDmg = copy.AttackDmg;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy){
    if(this != &copy)
    {
        ClapTrap::name = copy.name;
        name = copy.name;
        HitPts = copy.HitPts;
        EnergyPts = copy.EnergyPts;
        AttackDmg = copy.AttackDmg;
    }
    return *this;
}

std::string    DiamondTrap::getName(){
    return name;
}

void    DiamondTrap::whoAmI(){
    std::cout << "DiamondTrap " << this->getName() << std::endl;
    std::cout << "CLapTrap " << ClapTrap::getName() << std::endl;
}