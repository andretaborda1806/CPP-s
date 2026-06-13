#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serialize{
    private:
        Serialize();
        Serialize(const Serialize &copy);
        ~Serialize();
        Serialize &operator=(const Serialize &copy);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};

#endif