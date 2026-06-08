#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <climits>
#include <cfloat>

class ScalarConverter{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &copy);
        ~ScalarConverter();
        ScalarConverter &operator=(ScalarConverter const &copy);

        static bool     ToInt(const std::string &value);
        static bool     ToFloat(const std::string &value);
        static bool     ToDouble(const std::string &value);
        static bool     ToPseudo(const std::string &value);
    public:
        static void     convert(const std::string &literal);
};

#endif