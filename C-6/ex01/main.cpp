#include "Data.hpp"
#include "Serialize.hpp"

int main(void)
{
    Data data("ola");
    std::cout << "Object:                " << data.getData() << std::endl;
    std::cout << "Object address:        " << &data << std::endl;

    uintptr_t raw = Serialize::serialize(&data);
    std::cout << "Serialized:            " << raw << std::endl;

    Data *ptr = Serialize::deserialize(raw);
    std::cout << "Desserialized address: " << ptr << std::endl;
    std::cout << "Object:                " << ptr->getData() << std::endl;


    if (&data == ptr)
        std::cout << "OK: same pointer" << std::endl;
    else
        std::cout << "ERROR: different pointer" << std::endl;
    return 0;
}