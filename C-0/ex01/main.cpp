/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:01:02 by antabord          #+#    #+#             */
/*   Updated: 2026/04/10 14:41:32 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
    Phonebook phone;
    while (42)
    {
        std::string line;
        getline(std::cin, line);
        if (line == "ADD")
            phone.addContact();
        if (line == "SEARCH")
            phone.searchContact();
        if (line == "EXIT")
            break;
    }
}