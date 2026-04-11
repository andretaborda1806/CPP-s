#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>

class Contacts
{
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string darksecret;
        std::string number;
    public:
        Contacts();
        ~Contacts();
        bool updateContact();
        std::string getfirstname(bool gen);
        std::string getlastname(bool gen);
        std::string getnickname(bool gen);
        std::string getnumber();
        std::string getdarksecret();

};

#endif