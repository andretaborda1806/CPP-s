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

bool    ScalarConverter::IsChar(const std::string& literal)
{
    return (
        literal.length() == 1 &&
        !std::isdigit(literal[0])
    );
}

bool    ScalarConverter::IsInt(const std::string &literal){
    int i = 0;
    if (literal[i] == '+' || literal[i] == '-')
            i++;
    if (i == literal.length())
        return false;
    while (i < literal.length()){
        if (!std::isdigit(literal[i])){
            return false;
        }
        i++; 
    }
    return true;
}

bool     ScalarConverter::IsFloat(const std::string &literal){
    int i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    if (i == literal.length())
        return false;
    while (i < (literal.length() - 1)){
        if (literal[i] == '.'){
            i++;
        }
        if (!std::isdigit(literal[i])){
            return false;
        }
        i++;
    }
    if (literal[literal.length()] != 'f' || literal[i] == '.')
        return false;
    return true;
}

void     ScalarConverter::convert(const std::string &literal){
    if (literal.empty())
        std::cerr <<"Empty!" << std::endl;
    if ((literal[0] == '+' || literal[0] == '-' || literal[0] == '.') && !literal[1])
        std::cerr << "Ivalid!" << std::endl;
    if (IsChar(literal)){
        std::stringstream stream(literal);
        int n = 0;
        stream >> n;
        std::cout << "Char: " << literal << std::endl;
        std::cout << "Int: " << n << std::endl;
        std::cout << "Float: " << n << ".0f" << std::endl;
        std::cout << "Double: " << n << ".0" << std::endl;
        std::cout << "Pseudo: " << "Impossible" << std::endl;
    }
    else if (IsInt(literal)){
        std::stringstream stream(literal);
        int n = 0;
        stream >> n;
        std::cout << "Char: " << static_cast<char>(n) << std::endl;
        std::cout << "Int: " << n << std::endl;
        std::cout << "Float: " << n << ".0f" << std::endl;
        std::cout << "Double: " << n << ".0" << std::endl;
        std::cout << "Pseudo: " << "Impossible" << std::endl;
    }
    else if (IsFloat(literal)){
        try{
            
        }
        std::stringstream stream(literal);
        int n = 0;
        stream >> n;

        std::cout << "Char: " << static_cast<float>
    }
    IsFloat(literal);
    IsDouble(literal);
    IsPseudo(literal);
}
