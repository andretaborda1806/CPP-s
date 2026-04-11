/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:01:07 by antabord          #+#    #+#             */
/*   Updated: 2026/04/10 14:42:00 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(): contacts(), max(8) , count(0)
{
    std::cout << "Phonebook construido" << std::endl;
}

Phonebook::~Phonebook(){
    std::cout << "Phonebook destruido" << std::endl;
}

void Phonebook::addContact(void){
    static int maxedout = 0;
    if (count == max)
    {
        if (this->contacts[maxedout].updateContact()){
            maxedout++;
            if (maxedout == 8)
                maxedout = 0;
        }
    }
    else
    {
        if (this->contacts[count].updateContact())
            count++;
    }
}


bool Phonebook::searchContact(long index){
    if (index >= 1 && index <= count)
    {
        long i = index - 1;
        std::cout << "FirstName: " << contacts[i].getfirstname(false) << std::endl;
        std::cout << "LastName: " << contacts[i].getlastname(false) << std::endl;
        std::cout << "NickName: " << contacts[i].getnickname(false) << std::endl;
        std::cout << "Number: " << contacts[i].getnumber() << std::endl;
        std::cout << "Darksecret: " << contacts[i].getdarksecret() << std::endl;
        return true;

    }
    else if (index == 0){
        long i = 0;
        while (i < count){
        std::cout << std::setw(10) << (i + 1) << "|";
        std::cout << std::setw(10) << contacts[i].getfirstname(true) << "|";
        std::cout << std::setw(10) << contacts[i].getlastname(true) << "|";
        std::cout << std::setw(10) << contacts[i].getnickname(true) << "|" << std::endl;
        i++;
        }
        return true;
    }
    return false;
}

