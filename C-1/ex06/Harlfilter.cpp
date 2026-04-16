#include "Harlfilter.hpp"

Harlfilter::Harlfilter(){}

Harlfilter::~Harlfilter(){}

void    Harlfilter::complain(std::string level){
    std::string options[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int opt = 0;
    while (opt < 6){
        if (level == options[opt])
            break;
        opt++;
    }
    switch(opt){
        case (0):
            debug();
            info();
            warning();
            error();
            break;
        case(1):
            info();
            warning();
            error();
            break;
        case(2):
            warning();
            error();
            break;
        case(3):
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }


}

void    Harlfilter::debug(void){std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
    std::cout << std::endl;
}

void    Harlfilter::info(void){std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    std::cout << std::endl;
}

void    Harlfilter::error(void){std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now" << std::endl;
}

void    Harlfilter::warning(void){std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
    std::cout << std::endl;
}

