#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout << "FraTrap default constructor called" << std::endl;
    HitPts = 100;
    EnergyPts = 100;
    AttackDmg = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
    std::cout << "FragTrap " << getName() << " was created" << std::endl;
    HitPts = 100;
    EnergyPts = 100;
    AttackDmg = 30;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy){
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap" << getName() << " was destroyed" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy){
    std::cout << "FragTrap copy assignment operator was called" << std::endl;
    if (this != &copy)
    {
        name = copy.name;
        HitPts = copy.HitPts;
        EnergyPts = copy.EnergyPts;
        AttackDmg = copy.AttackDmg;
    }
    return (*this);
}

void    FragTrap::highFivesGuys(){
    std::cout << "FragTrap" << getName() <<" high fived some guys" << std::endl;
}