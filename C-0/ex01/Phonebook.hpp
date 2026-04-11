/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:01:16 by antabord          #+#    #+#             */
/*   Updated: 2026/02/26 18:01:17 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contacts.hpp"

class Phonebook
{
    private:
        Contacts contacts[8];
        int max;
        int count;
    public:
        Phonebook();
        ~Phonebook();
        void addContact();
        bool searchContact(long index);
};

#endif
