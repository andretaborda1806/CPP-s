#include <iostream>

int main(void){
    std::string str = "HI THIS IS BRAIN";
    std::string &stringREF = str;
    std::string *stringPTR = &str;
    std::cout << "string address " << &str << std::endl;
    std::cout << "reference address " << &stringREF << std::endl;
    std::cout << "pointer address " << &stringPTR << std::endl;
    std::cout << "string content " << str << std::endl;
    std::cout << "reference content " << stringREF << std::endl;
    std::cout << "pointer conteent " << stringPTR << std::endl;
    return 0;
}