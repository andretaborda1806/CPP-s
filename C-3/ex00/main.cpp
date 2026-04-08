#include "ClapTrap.hpp"

int main(){
    ClapTrap a("manel");
    a.attack("zé");
    a.takeDamage(10);
    a.attack("zézoca");
    a.beRepaired(2);
    a.attack("zé miguel");
    return 0;
}