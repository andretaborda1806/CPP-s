#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    std::cout << "ScavTrap default constructor called" << std::endl;
    HitPts = 100;
    EnergyPts = 50;
    AttackDmg = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
    std::cout << "ScavTrap " << name << " was created" << std::endl;
    HitPts = 100;
    EnergyPts = 50;
    AttackDmg = 20;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap " << getName() << " was destroyed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy){
    std::cout << "ScavTrap copy constructor called" << std::endl;

}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy){
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        name = copy.name;
        HitPts = copy.HitPts;
        AttackDmg = copy.AttackDmg;
        EnergyPts = copy.EnergyPts;
    }
    return *this;
}

void    ScavTrap::attack(const std::string &target){
    switch (checker())
    {
    case 0:
        std::cout << "ScavTrap " << getName() << " attacks " << target << " causing " << getAttackDmg() << " points of damage" << std::endl;
        EnergyPts--;
        break;
    case 1:
        std::cout << "ScavTrap " << getName() << " doesnt have enought energy to attack " << target << std::endl;
        break;
    case 2:
        std::cout << "ScavTrap " << getName() << " has died therefore is unable to attack " << target << std::endl;
        break;
    }
}

void    ScavTrap::guardGate(){
    std::cout << "ScavTrap " << getName() << " is guading the gate" <<std::endl;
}