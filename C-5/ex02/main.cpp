#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main(void){
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

    std::cout << std::endl <<"--------------------------Test1: Not enough to sign---------------------" << std::endl;
    try{
        Bureaucrat a("Ze Manel", 10);
        ShrubberyCreationForm b("Zezoca");
        a.signAForm(b);
        std::cout << b << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl; 
    }
        std::cout << std::endl <<"--------------------------Test2: Buru too low for form---------------------" << std::endl;
    try{
        Bureaucrat c("Ze Maria", 151);
        AForm d("ola", 1, 40);
        c.signForm(d);
        std::cout << c << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl; 
    }
        std::cout << std::endl <<"--------------------------Test3: Form already signed---------------------" << std::endl;
    try{
        Bureaucrat f("Ze Maria", 10);
        AForm g("ola", 11, 40);
        f.signForm(g);
        std::cout << f << std::endl;
        f.signForm(g);
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl; 
    }
    std::cout << std::endl <<"--------------------------Test4: Form too low---------------------" << std::endl;
    try{
        Bureaucrat f("Ze Maria", 10);
        AForm g("ola", 151, 40);
        f.signForm(g);
        std::cout << f << std::endl;
        f.signForm(g);
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl; 
    }
    std::cout << std::endl;
        std::cout << std::endl <<"--------------------------Test4: Form too high---------------------" << std::endl;
    try{
        Bureaucrat f("Ze Maria", 10);
        AForm g("ola", 0, 40);
        f.signForm(g);
        std::cout << f << std::endl;
        f.signForm(g);
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl; 
    }
}