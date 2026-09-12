#include "Themeplate.hpp"

int main( void ) {
int a = 2;
int b = 3;
std::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << std::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << std::max( a, b ) << std::endl;

std::string c = "chaine1";
std::string d = "chaine2";

std::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << std::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << std::max( c, d ) << std::endl;
return 0;
}