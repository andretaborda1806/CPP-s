#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat{
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        ~Bureaucrat();
        Bureaucrat          &operator=(Bureaucrat const &copy);
        class GradeTooHighException: public std::exception{
                public:
                virtual const char* what() const throw();
            };
        class GradeTooLowException: public std::exception{
            virtual const char* what() const throw();
        };
        const std::string   getName() const;
        int                 getGrade() const;
        void                incrementGrade();
        void                decrementGrade();
    private:
        const std::string   _name;
        int                 _grade;
};

std::ostream &operator<<( std::ostream &out, const Bureaucrat &bureaucrat );

#endif