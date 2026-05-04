#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed b( a );
    Fixed c;
    Fixed d;
    d.setFixedValue(10);
    c = b;
    a = d;
    std::cout << a.getFixedValue() << std::endl;
    std::cout << b.getFixedValue() << std::endl;
    std::cout << c.getFixedValue() << std::endl;
    std::cout << d.getFixedValue() << std::endl;
    return 0;
}