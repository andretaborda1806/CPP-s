#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <memory>


int main(void){
    std::srand(std::time(NULL)); 
/*     std::cout << "-------------Test1: Too high------------------" << std::endl;
    try{
        Bureaucrat a("Ze Maria", -1);
        std::cout << a << std::endl;
    }
    catch(std::exception &e){    
        std::cout << "Exeption: " << e.what() << std::endl;
    }
    std::cout << "-------------Test2: Too low------------------" << std::endl;
    try{
        Bureaucrat a("Paulo", 151);
        std::cout << a << std::endl;
    }
    catch(std::exception &e){    
        std::cout << "Exeption: " << e.what() << std::endl;
    }
    std::cout << "--------------Test3: Incrmenting too much-----------------" << std::endl;
    try{
        Bureaucrat a("Sho Vitor", 140);
        for (int i = 0; i < 11; i++){
            a.incrementGrade();
            std::cout << a << std::endl;
        }
    }
    catch(std::exception &e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "-------------Test1: OK grade------------------" << std::endl;
    try{
        Bureaucrat a("Ze Mario", 10);
        std::cout << a << std::endl;
    }
    catch(std::exception &e){    
        std::cout << "Exeption: " << e.what() << std::endl;
    } */

    std::cout << std::endl <<"--------------------------Test1: Shruberry OK---------------------" << std::endl;
    try{
        Bureaucrat a("Ze Manel", 10);
        std::auto_ptr<AForm> b(new ShrubberyCreationForm("arvore"));
        a.signForm(*b);
        a.executeForm(*b);
        std::cout << *b << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
        std::cout << std::endl <<"--------------------------Test2: Roboto OK---------------------" << std::endl;
    try{
        Bureaucrat c("Ze Maria", 10);
        std::auto_ptr<AForm> b(new RobotomyRequestForm("robot"));
        c.signForm(*b);
        c.executeForm(*b);
        std::cout <<*b << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl; 
    }
        std::cout << std::endl <<"--------------------------Test3: President OK---------------------" << std::endl;
    try{
        Bureaucrat f("Ze Maria", 2);
        std::auto_ptr<AForm> b(new PresidentialPardonForm("presidential"));
        f.signForm(*b);
        f.executeForm(*b);
        std::cout << *b << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl; 
    }
        std::cout << std::endl <<"--------------------------Test4: Shruberry not enough---------------------" << std::endl;
    try{
        Bureaucrat a("Ze Manel", 150);
        std::auto_ptr<AForm> b(new ShrubberyCreationForm("arvore"));
        a.signForm(*b);
        a.executeForm(*b);
        std::cout << *b << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
            std::cout << std::endl <<"--------------------------Test4: President alreadysigned---------------------" << std::endl;
    try{
        Bureaucrat f("Ze Maria", 2);
        std::auto_ptr<AForm> b(new PresidentialPardonForm("presidential"));
        f.signForm(*b);
        f.executeForm(*b);
        f.signForm(*b);
        std::cout << *b << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl; 
    }
}