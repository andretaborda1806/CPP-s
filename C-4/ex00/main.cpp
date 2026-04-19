#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const WrongAnimal *wrong = new WrongAnimal();
    const WrongAnimal *wrongcat = new WrongCat();
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "/*/*/*/*/*/* Types /*/*/*/*/*/*/" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << wrongcat->getType() << " " << std::endl;
    std::cout << "/*/*/*/*/*/* Sounds /*/*/*/*/*/*/" << std::endl;
    i->makeSound();
    j->makeSound();
    wrongcat->makeSound();
    wrong->makeSound();
    meta->makeSound();
    std::cout << std::endl;
    delete j;
    delete i;
    delete meta;
    delete wrongcat;
    delete wrong;
    return 0;
}