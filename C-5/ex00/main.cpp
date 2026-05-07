#include "Bureaucrat.hpp"

int main(void){
    try{
        std::cout << "-------------Test1: Too low------------------" << std::endl;
        Bureaucrat a("Ze Maria", -1);
        std::cout << a << std::endl;
    }
    catch(std::exception &e){    
        std::cout << "Exeption: " << e.what() << std::endl;
    }
    try{
        std::cout << "-------------Test2: Too high------------------" << std::endl;
        Bureaucrat a("Paulo", 151);
        std::cout << a << std::endl;
    }
    catch(std::exception &e){    
        std::cout << "Exeption: " << e.what() << std::endl;
    }
    try{
        std::cout << "--------------Test3: Incrmenting too much-----------------" << std::endl;
        Bureaucrat a("Sho Vitor", 140);
        for (int i = 0; i < 11; i++){
            a.incrementGrade();
            std::cout << a << std::endl;
        }
    }
    catch(std::exception &e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
}