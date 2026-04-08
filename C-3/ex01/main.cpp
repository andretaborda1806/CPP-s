#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
    ClapTrap a("manel");
    a.attack("zé");
    a.takeDamage(10);
    a.attack("zézoca");
    a.beRepaired(2);
    a.attack("zé miguel");
    ScavTrap b("robot manel");
    b.attack("orlando");
    b.guardGate();
    b.takeDamage(200);
    b.beRepaired(3);
    b.attack("ola");
    b.attack("maria");
    return 0;
}