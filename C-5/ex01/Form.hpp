#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;
class Form{
    private:
        const std::string _name;
        bool _signed;
        const int   _gradeSign;
        const int   _gradeExec;
    public:
        Form();
        Form(const std::string name, const int gradeSign, const int gradeExec);
        Form(const Form &copy);
        ~Form();
        Form    &operator=(Form const &copy);
        std::string getName() const;
        std::string getSignStatus() const;
        int   getSignGrade() const;
        int   getExecGrade() const;
        class GardeTooHighExeption: public std::exception{
            virtual const char* what() const throw();
        };
        class GardeTooLowExeption: public std::exception{
            virtual const char* what() const throw();
        };
        class FormWasAlreadySigned: public std::exception{
            virtual const char* what() const throw();
        };
        void    beSigned(Bureaucrat &b);
};

#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif