#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cctype>

//##################################################################
//                   Constructor && Destructor                     #
//##################################################################
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
    (void)rhs;
    return *this;
}

//##################################################################
//                          Methodes                               #
//##################################################################

static int detectType(const std::string& literal) {
    // Types possibles
    enum Type {
        CHAR = 1,
        INT,
        FLOAT,
        DOUBLE,
        SPECIAL,  // pour nan, inf, etc.
        ERROR
    };

    // Vérification des cas spéciaux
    if (literal == "nan" || literal == "nanf" || 
        literal == "+inf" || literal == "+inff" || 
        literal == "-inf" || literal == "-inff") {
        return SPECIAL;
    }

    // Vérification char
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        return CHAR;
    }

    // Vérification nombre
    bool hasDigit = false;
    bool hasDecimal = false;
    bool hasF = false;
    size_t start = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;

    for (size_t i = start; i < literal.length(); i++) {
        if (isdigit(literal[i])) {
            hasDigit = true;
        }
        else if (literal[i] == '.') {
            if (hasDecimal) return ERROR;
            hasDecimal = true;
        }
        else if (literal[i] == 'f' && i == literal.length() - 1) {
            hasF = true;
        }
        else return ERROR;
    }

    if (!hasDigit) return ERROR;
    if (hasF) return FLOAT;
    if (hasDecimal) return DOUBLE;
    return INT;
}

void ScalarConverter::convert(const std::string& literal) {
    int type = detectType(literal);
    char c;
    int i;
    float f;
    double d;

    switch (type) {
        case 1: // CHAR
            c = literal[1];
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
            break;

        case 2: // INT
            i = atoi(literal.c_str());
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
            break;

        case 3: // FLOAT
            f = atof(literal.c_str());
            i = static_cast<int>(f);
            c = static_cast<char>(f);
            d = static_cast<double>(f);
            break;

        case 4: // DOUBLE
            d = atof(literal.c_str());
            i = static_cast<int>(d);
            c = static_cast<char>(d);
            f = static_cast<float>(d);
            break;

        case 5: // SPECIAL
            if (literal == "nan" || literal == "nanf") {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: nanf" << std::endl;
                std::cout << "double: nan" << std::endl;
            } else {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << (literal[0] == '-' ? "-" : "+") << "inff" << std::endl;
                std::cout << "double: " << (literal[0] == '-' ? "-" : "+") << "inf" << std::endl;
            }
            return;

        default: // ERROR
            std::cout << "Invalid input" << std::endl;
            return;
    }

    // Affichage des résultats
    if (i >= 32 && i <= 126)
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    std::cout << "float: " << f;
    if (f == static_cast<int>(f)) std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << d;
    if (d == static_cast<int>(d)) std::cout << ".0";
    std::cout << std::endl;
}