/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:00:56 by antabord          #+#    #+#             */
/*   Updated: 2026/02/26 18:00:57 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Contacts::Contacts(){
}

Contacts::~Contacts(){
}

bool Contacts::updateContact(){
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string number;
    std::string darksecret;
    std::cout << "Firstname:" << std::endl;
    std::getline(std::cin, firstname);
    if (firstname == ""){
        std::cout << "Firstname cant be empty" << std::endl; 
        return false;
    }
    std::cout << "Lastname:" << std::endl;
    std::getline(std::cin, lastname);
    if (lastname == ""){
        std::cout << "Lastname cant be empty" << std::endl; 
        return false;
    }
    std::cout << "Nickname:" << std::endl;
    std::getline(std::cin, nickname);
    if (nickname == ""){
        std::cout << "Nickname cant be empty" << std::endl; 
        return false;
    }
    std::cout << "Number:" << std::endl;
    std::getline(std::cin, number);
    if (number == ""){
        std::cout << "Number cant be empty" << std::endl; 
        return false;
    }
    std::cout << "Darksecret:" << std::endl;
    std::getline(std::cin, darksecret);
    if (darksecret == ""){
        std::cout << "Darksecret cant be empty" << std::endl; 
        return false;
    }
    this->firstname = firstname;
    this->lastname = lastname;
    this->nickname = nickname;
    this->number = number;
    this->darksecret = darksecret;
    std::cout << "Contact created!" << std::endl;
    return true;
}

std::string Contacts::getfirstname(bool gen){
    if (this->firstname.length() > 9 && gen)
    {
        std::string sub;
        sub = this->firstname.substr(0, 9) + ".";
        return (sub);
    }
    else
        return (this->firstname);
}

std::string Contacts::getlastname(bool gen){
    if (this->lastname.length() > 9 && gen)
    {
        std::string sub;
        sub = this->lastname.substr(0, 9) + ".";
        return (sub);
    }
    else
        return (this->lastname);
}

std::string Contacts::getnickname(bool gen){
    if (this->nickname.length() > 9 && gen)
    {
        std::string sub;
        sub = this->nickname.substr(0, 9) + ".";
        return (sub);
    }
    else
        return (this->nickname);
}

std::string Contacts::getnumber(){
    return number;
}

std::string Contacts::getdarksecret(){
    return darksecret;
}