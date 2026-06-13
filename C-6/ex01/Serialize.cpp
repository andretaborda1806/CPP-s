#include "Serialize.hpp"

Serialize::Serialize(){}

Serialize::Serialize(const Serialize &copy){
    (void)copy;
}

Serialize::~Serialize(){}

Serialize &Serialize::operator=(const Serialize &copy){
    if (this != &copy)
        (void)copy;
    return (*this);
}


uintptr_t   Serialize::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data*        Serialize::deserialize(uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
}
