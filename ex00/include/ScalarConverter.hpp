#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>  // Pour std::cout et std::endl
#include <string>    // Pour std::string
#include <cstdlib>   // Pour atoi, atof, strtol, strtod, strtof
#include <cctype>    // Pour isdigit, isprint, isspace
#include <limits>    // Pour std::numeric_limits (optionnel)

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4

class ScalarConverter {

	private:
		char _char;
		int _int;
		float _float;
		double _double;
		

	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		virtual ~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &src);

	//getter
	char getChar() const;

	//methode
	void convert(std::string str);


	// metode pour analyser les types en entrée



};

#endif