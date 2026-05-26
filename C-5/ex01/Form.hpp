#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

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
        const std::string getName() const;
        const std::string getSignStatus() const;
        const int   getSignGrade() const;
        const int   getExecGrade() const;
        class GardeTooHighExeption: public std::exception{
            virtual const char* what() const throw();
        };
        class GardeTooLowExeption: public std::exception{
            virtual const char* what() const throw();
        };
        void    beSigned(Bureaucrat b);
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif