/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:53:59 by antabord          #+#    #+#             */
/*   Updated: 2026/05/26 15:38:51 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name(""), _signed(false), _gradeSign(1), _gradeExec(1){}

Form::Form(const std::string name, const int gradeSign, const int gradeExec): _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false){
    if (gradeSign > 150 || gradeExec > 150)
        throw GardeTooLowExeption();
    if (gradeExec < 1 || gradeExec < 1)
        throw GardeTooHighExeption();
}

Form::Form(const Form &copy): _name(copy._name), _signed(false), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec){
    if (copy.getSignGrade() > 150 || copy.getExecGrade() > 150)
        throw GardeTooLowExeption();
    if (copy.getSignGrade() < 0 || copy.getExecGrade() < 0)
        throw GardeTooHighExeption();
}

Form    &Form::operator=(Form const &copy){
    if (&copy != this){
        _signed = copy._signed;   
    }
    return *this;
}

Form::~Form(){}

const std::string   Form::getName()const{
    return (this->_name);
}

const int   Form::getSignGrade()const{
    return (this->_gradeSign);
}

const int   Form::getExecGrade()const{
    return (this->_gradeExec);
}

const std::string Form::getSignStatus()const{
    switch (this->_signed)
    {
    case true:
        return ("true");
    default:
        return ("false");
    }
}

const char* Form::GardeTooHighExeption::what() const throw(){
    return ("Grade is too high");
}

const char* Form::GardeTooLowExeption::what() const throw(){
    return ("Grade is too low");
}

void    Form::beSigned(Bureaucrat b){
    if (b.getGrade() < this->getSignGrade()){
        this->_signed = true;
        std::cout << b.getName() << " signed form " << this->getName() << "." <<std::endl;
    }
    if (b.getGrade() > this->getSignGrade()){
        std::cout << b.getName() << " couldn't sign " << this->getName() << " beacause ";
        throw GardeTooLowExeption();
    }
}

std::ostream &operator<<(std::ostream &out, const Form &form){
    out << form.getName() << ", grade to sign " << form.getSignGrade() << ", grade to execute " << form.getExecGrade() << " and its signed status is " << form.getSignStatus() << ".";
    return (out);
}

