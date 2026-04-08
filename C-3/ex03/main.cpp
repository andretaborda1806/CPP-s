#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(){
    DiamondTrap d("Diamantino");
    d.whoAmI();
    d.attack("adeus");
    d.highFivesGuys();
    d.takeDamage(1000);
    d.beRepaired(3);

    FragTrap c("Francisco");
    c.attack("sho vitor");
    c.beRepaired(1);
    c.takeDamage(1000);
    c.attack("carolina");
    c.beRepaired(5);

    ScavTrap b("robot manel");
    b.attack("orlando");
    b.guardGate();
    b.takeDamage(200);
    b.beRepaired(3);
    b.attack("ola");
    b.attack("maria");
    
    ClapTrap a("manel");
    a.attack("zé");
    a.takeDamage(10);
    a.attack("zézoca");
    a.beRepaired(2);
    a.attack("zé miguel");
    return 0;
}