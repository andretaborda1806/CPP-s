#include "Base.hpp"
#include "Fun.hpp"

int main(void){
	srand(time(NULL));

	Base *type = generate();
	std::cout << "Using pointer: ";
	identify(type);
	std::cout << "Using reference: ";
	identify(*type);
	delete type;

	Base *other = generate();
	std::cout << "Using pointer: ";
	identify(other);
	std::cout << "Using reference: ";
	identify(*other);
	delete other;

	Base *p = generate();
	std::cout << "Using pointer: ";
	identify(p);
	std::cout << "Using reference: ";
	identify(*p);
	delete p;
	
	return (0);
}