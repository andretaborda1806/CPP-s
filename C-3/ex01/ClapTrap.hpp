#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
    protected:
        std::string name;
        int     HitPts;
        int     EnergyPts;
        int     AttackDmg;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &copy);
        ClapTrap &operator=( ClapTrap const &copy );
        ~ClapTrap();
        std::string     getName()const;
        virtual void    attack(const std::string& target);
        int     getHitPts()const;
        int     getEnergyPts() const;
        int     getAttackDmg() const;
        int     checker() const;
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};


#endif