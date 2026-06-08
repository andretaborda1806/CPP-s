#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &copy){
    (void)copy;
}

ScalarConverter::~ScalarConverter(){}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    (void)copy;
    return *this;
}

bool    ScalarConverter::ToInt(const std::string &literal){
    try{
        int i = 0;
        if (literal[i] == '+' || literal[i] == '-')
            i++;
        if (i == literal.length())
            throw std::runtime_error("Empty");
        while (i < literal.length()){
            if (!std::isdigit(literal[i])){
                throw std::runtime_error("It is not a digit!");
            }
            i++; 
        }
        long tmp = std::strtol(literal.c_str(), NULL, 10);
        if (tmp > INT_MAX || tmp < INT_MIN)
            throw std::runtime_error("Out of range!");
        return true;
    }
    catch (const std::exception &e){
        std::cout << "Int error: " << e.what() << std::endl;
        return false;
    }
}

bool     ScalarConverter::ToFloat(const std::string &literal){
    try{
        int i = 0;
        if (literal == "nanf" || literal == "+inff" || literal == "-inff")
            return true;
        if (literal[i] == '+' || literal[i] == '-')
            i++;
        if (i == literal.length())
            throw std::runtime_error("Empty");
        int comma = 0;
        while (i < (literal.length() - 1)){
            if (literal[i] == '.'){
                comma++;
                i++;
                if (comma > 1)
                    throw std::runtime_error("Too many commas");
            }
            if (!std::isdigit(literal[i])){
                throw std::runtime_error("It is not a digit!");
            }
            i++;
        }
        if (!comma || literal[i + 1] != 'f' || literal[i] == '.')
            throw std::runtime_error("Invalid digit");
        return true;
    }
    catch (const std::exception &e){
        std::cout << "Float error: " << e.what() << std::endl;
        return false;
    }
}

void     ScalarConverter::convert(const std::string &literal){
    if (literal.empty())
        std::cerr <<"Empty!" << std::endl;
    if (ToInt(literal))
        std::cout << "Int: " << literal << std::endl;
    if (ToFloat(literal)){

        std::cout << "Float: " << static_cast<float>
    }
    ToFloat(literal);
    ToDouble(literal);
    ToPseudo(literal);
}
