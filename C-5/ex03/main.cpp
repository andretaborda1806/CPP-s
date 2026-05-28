#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
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
        Bureaucrat a("Ze Manel", 150);
        Intern rando;
        std::auto_ptr<AForm> b(rando.makeForm(std::string("shrubbery creation"), "arvore"));
        a.signForm(*b);
        a.executeForm(*b);
        std::cout << *b << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
        std::cout << std::endl <<"--------------------------Test2: Roboto OK---------------------" << std::endl;
    try{
        Bureaucrat a("Ze Manel", 10);
        Intern rando;
        std::auto_ptr<AForm> b(rando.makeForm(std::string("robotomy request"), "robo"));
        a.signForm(*b);
        a.executeForm(*b);
        std::cout << *b << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl; 
    }
        std::cout << std::endl <<"--------------------------Test3: President OK---------------------" << std::endl;
    try{
        Bureaucrat a("Ze Manel", 10);
        Intern rando;
        std::auto_ptr<AForm> b(rando.makeForm(std::string("presidential pardon"), "pardon"));
        a.signForm(*b);
        a.executeForm(*b);
        std::cout << *b << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl; 
    }
        std::cout << std::endl <<"--------------------------Test4: Form aleady signed---------------------" << std::endl;
    try{
        Bureaucrat a("Ze Manel", 150);
        Intern rando;
        std::auto_ptr<AForm> b(rando.makeForm(std::string("shrubbery creation"), "arvore"));
        a.signForm(*b);
        a.executeForm(*b);
        a.signForm(*b);
        std::cout << *b << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
            std::cout << std::endl <<"--------------------------Test4: Unknown form---------------------" << std::endl;
    try{
        Bureaucrat a("Ze Manel", 10);
        Intern rando;
        std::auto_ptr<AForm> b(rando.makeForm(std::string("olarilolé"), "pardon"));
        a.signForm(*b);
        a.executeForm(*b);
        std::cout << *b << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl; 
    }
}