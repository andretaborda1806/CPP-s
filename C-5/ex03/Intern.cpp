#include "Intern.hpp"

#include <memory>

Intern::Intern(){}

Intern::Intern(const Intern &copy){
    (void)copy;
}

Intern::~Intern(){}

Intern &Intern::operator=(const Intern &copy){
    (void)copy;
    return *this;
}

AForm* Intern::makeForm(std::string name, std::string target){
    std::auto_ptr<AForm> form;

    if (name == "shrubbery creation" || name == "shrubberycreation"){
        std::cout << "Intern creates " << name << std::endl;
        form.reset(new ShrubberyCreationForm(target));
        return form.release();
    }
    if (name == "robotomy request" || name == "robotomyrequest"){
        std::cout << "Intern creates " << name << std::endl;
        form.reset(new RobotomyRequestForm(target));
        return form.release();
    }
    if (name == "presidential pardon" || name == "presidentialpardon"){
        std::cout << "Intern creates " << name << std::endl;
        form.reset(new PresidentialPardonForm(target));
        return form.release();
    }
    std::cout << "I dont know what " << name << " even means, I think this is an" << std::endl;
    throw InvalidForm();
    return NULL;
}

const char* Intern::InvalidForm::what() const throw(){
    return ("Invalid form");
}