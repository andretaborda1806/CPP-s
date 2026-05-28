#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern{
    public:
        Intern();
        Intern(const Intern &copy);
        ~Intern();
        Intern &operator=(const Intern &copy);
        AForm* makeForm(std::string name, std::string target);
        class InvalidForm: public std::exception{
            virtual const char* what() const throw();
        };
};

#endif