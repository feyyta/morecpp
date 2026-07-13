/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:14:12 by mcastrat          #+#    #+#             */
/*   Updated: 2026/05/04 15:03:52 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &src){
	(void)src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &rhs){
	
	if (this != &rhs)
		(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter(){
}

static int isCharLiteral(const std::string &s){
	return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
}

static int isPseudoFloat(const std::string &s){
	return (s == "-inff" || s == "+inff" || s == "nanf");
}

static int isPseudoDouble(const std::string &s){
	return (s == "-inf" || s == "+inf" || s == "nan");
}

static int isFloat(const std::string &s){
	
	size_t len = s.length();
	char *end;

	if (len < 2 || s[len - 1] != 'f')
		return 0;
	std::string sub = s.substr(0, len - 1);
	if (sub.find('.') == std::string::npos)
		return 0;
	strtod(sub.c_str(), &end);
	return *end == '\0';
}

static int isDouble(const std::string &s){
	char *end;
	
	if (s.find('.') == std::string::npos)
		return 0;
	strtod(s.c_str(), &end);
	return *end == '\0';
}

static int isInt(const std::string &s){
	char *end;

	if (s.empty())
		return 0;
	long val = strtol(s.c_str(), &end, 10);
	return (*end == '\0' && val >= INT_MIN && val <= INT_MAX);
}

static void printChar(double val){
	if (val != val || val < 0 || val > 127)
		std::cout << "char: impopo" << std::endl;
	else if (val < 32 || val >= 127)
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
}

static void printInt(double val){
	if (val != val || val < static_cast<double>(INT_MIN) || val > static_cast<double>(INT_MAX))
		std::cout << "int: impopo" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;
}

static void printFloat(float val){
	if (val != val)
		std::cout << "float: nanf" << std::endl;//not a numb 'float
	else if (val > FLT_MAX)
		std::cout << "float: +inff" << std::endl;//+infiniii
	else if (val < -FLT_MAX)
		std::cout << "float: -inff" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << val << "f" << std::endl;// fixed et set pour nota decimal et eviter tt arrondi nn voulu
}

static void printDouble(double val){
	if (val != val)
		std::cout << "double: nan" << std::endl;
	else if (val > DBL_MAX)
		std::cout << "double: +inf" << std::endl;
	else if (val < -DBL_MAX)
		std::cout << "double: -inf" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << val << std::endl;
}

static void convertAll(double d){

	printChar(d);
	printInt(d);
	printFloat(static_cast<float>(d));
	printDouble(d);

}

static void impopoMessage(void){
	std::cout << "char: impopo" << std::endl;
	std::cout << "int: impopo" << std::endl;
}

static void printDbflt(double d){
	impopoMessage();
	printFloat(static_cast<float>(d));
	printDouble(d);
}

void ScalarConverter::convert(const std::string &literal){
	
	if (isCharLiteral(literal)){
		convertAll(static_cast<double>(literal[1]));

	} else if (literal.length() == 1 && literal[0] >= 32 && literal[0] <= 126){
		convertAll(static_cast<double>(literal[0]));

	} else if (isPseudoFloat(literal)){
		std::string base = literal.substr(0, literal.length() - 1);// for strtod
		double d = strtod(base.c_str(), NULL);//c..tr prcq strtod cannot read std string
		printDbflt(d);

	} else if (isPseudoDouble(literal)){
		double d = strtod(literal.c_str(), NULL);
		printDbflt(d);

	} else if (isFloat(literal)){
		std::string sub = literal.substr(0, literal.length() - 1);
		convertAll(static_cast<float>(strtod(sub.c_str(), NULL)));

	} else if (isDouble(literal)){
		convertAll(strtod(literal.c_str(), NULL));

	} else if (isInt(literal)){
		convertAll(static_cast<int>(strtol(literal.c_str(), NULL, 10)));//base decimal

	} else {
		impopoMessage();
		std::cout << "float: impopo" << std::endl;
		std::cout << "double: impopo" << std::endl;
	}
}
