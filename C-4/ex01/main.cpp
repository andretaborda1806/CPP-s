#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal *animals[10];
    Animal animal;
    animal.makeSound();
    std::string dogBrain[100];
    std::string catBrain[100];

    for (int i = 0; i < 10; i++)
    {
        if (i < 5){
            animals[i] = new Dog();
            for (int j = 0; j < 100; j++)
                animals[i]->setIdeas("osso", j);
            std::cout << "im a " << animals[i]->getType() << " and i make: ";
            animals[i]->makeSound();
            std::cout << std::endl;
            /*std::cout << "I´m thinking about: " << std::endl;
            for (int j = 0; j < 100; j++)
                std::cout << animals[i]->getIdeas()[j] << std::endl;*/
        }
        else{
            animals[i] = new Cat();
            for (int j = 0; j < 100; j++)
                animals[i]->setIdeas("peixe", j);
                        std::cout << "im a " << animals[i]->getType() << " and i make: ";
            animals[i]->makeSound();
            std::cout << std::endl;
            /*std::cout << "I´m thinking about: " << std::endl;
            for (int j = 0; j < 100; j++)
                std::cout << animals[i]->getIdeas()[j] << std::endl;*/
        }
    }
    for (int i = 0; i < 10; i++)
        delete animals[i];
    return 0;
}