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
        std::cout << "  Use the following commands: ADD, SEARCH or EXIT" << std::endl;
        std::string line;
        getline(std::cin, line);
        if (line == "ADD")
            phone.addContact();
        if (line == "SEARCH")
        {
            std::string lineIndex;
            std::cout << "Index: ";
            long index;
            if (!std::getline(std::cin, lineIndex))
                break;
            char *end = NULL;
            index = strtol(lineIndex.c_str(), &end, 10);
            if (*end != '\0' || !phone.searchContact(index))
                    std::cout << "Error: This contact doesnt exist" << std::endl;
        }
        if (line == "EXIT")
            break;
    }
}