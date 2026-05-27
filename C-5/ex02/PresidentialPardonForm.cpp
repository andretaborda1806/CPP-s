/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:07:55 by antabord          #+#    #+#             */
/*   Updated: 2026/05/27 13:23:54 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("ShruberryCreationForm", 25, 5), _target("default"){}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("ShruberryCreationForm", 25, 5),_target(target){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy){
    if (this != &copy)
        _target = copy._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy){
    *this = copy;
}

void    PresidentialPardonForm::execute(const Bureaucrat &executor)const{
    if (!getSignStatus())
        throw AForm::AFormWasNotSignedYet();
    if (getSignGrade() != 25)
        throw AForm::InvalidSignGrade();
    if (getExecGrade() != 5)
        throw AForm::InvalidExecGrade();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}