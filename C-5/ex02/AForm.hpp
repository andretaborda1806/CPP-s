#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm{
    private:
        const std::string _name;
        bool _signed;
        const int   _gradeSign;
        const int   _gradeExec;
    public:
        AForm();
        AForm(const std::string name, const int gradeSign, const int gradeExec);
        AForm(const AForm &copy);
        ~AForm();
        AForm           &operator=(AForm const &copy);
        std::string     getName() const;
        bool            getSignStatus() const;
        int             getSignGrade() const;
        int             getExecGrade() const;
        class GardeTooHighExeption: public std::exception{
            virtual const char* what() const throw();
        };
        class GardeTooLowExeption: public std::exception{
            virtual const char* what() const throw();
        };
        class AFormWasAlreadySigned: public std::exception{
            virtual const char* what() const throw();
        };
        class AFormWasNotSignedYet: public std::exception{
            virtual const char* what() const throw();
        };
        class InvalidSignGrade: public std::exception{
            virtual const char* what() const throw();
        };
        class InvalidExecGrade: public std::exception{
            virtual const char* what() const throw();
        };
        virtual void    beSigned(Bureaucrat &b);
        virtual void    execute(const Bureaucrat &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#include "Bureaucrat.hpp"

#endif