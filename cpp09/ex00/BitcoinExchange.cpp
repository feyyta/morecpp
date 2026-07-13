/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 08:09:58 by mcastrat          #+#    #+#             */
/*   Updated: 2026/07/03 14:32:20 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src){
    *this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs){
    if (this != &rhs)
        _data = rhs._data;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(){
}


static std::string trim(const std::string &s){//retire tab et espace debut fin de string
    size_t start = s.find_first_not_of(" \t");
    if (start == std::string::npos)
        return ("");
    size_t end = s.find_last_not_of(" \t");
    return (s.substr(start, end - start + 1));
}

static int isValidDate(const std::string &date){// check placement de string pour date valable
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return (0);
    for (size_t i = 0; i < 10; i++){
        if (i == 4 || i == 7){
            if (date[i] != '-')
                return (0);
        }
        else{
            if (!isdigit(date[i]))
                return (0);
        }
    }
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    return (month >= 1 && month <= 12 && day >= 1 && day <= 31);
}

static int parseValue(const std::string &valueStr, double &value){
    char *end;
    value = strtod(valueStr.c_str(), &end);
    return (*end == '\0' && end != valueStr.c_str());//all string parsed 
}

static int validateValue(double value){
    return (value >= 0 && value <= 1000);
}

static int parseLine(const std::string &line, std::string &date, double &value){
    if (line.empty())
        return (0);
    size_t pos = line.find('|');
    if (pos == std::string::npos){
        std::cout << "Error: bad input => " << line << std::endl;
        return (0);
    }
    date = trim(line.substr(0, pos));
    std::string valueStr = trim(line.substr(pos + 1));

    if (!isValidDate(date)){
        std::cout << "Error: bad input => " << date << std::endl;
        return (0);
    }
    if (!parseValue(valueStr, value)){
        std::cout << "Error: bad input => " << valueStr << std::endl;
        return (0);
    }
    if (!validateValue(value)){
        if (value < 0)
            std::cout << "Error: not a positive number." << std::endl;
        else
            std::cout << "Error: too large a number." << std::endl;
        return (0);
    }
    return (1);
}


float BitcoinExchange::getRate(const std::string &date) const{
    std::map<std::string, float>::const_iterator it = _data.find(date);
    if (it != _data.end())
        return it->second;

    for (std::map<std::string, float>::const_reverse_iterator rit = _data.rbegin();
         rit != _data.rend(); ++rit) {
        if (rit->first < date)
            return rit->second;
    }
    throw std::runtime_error("Error: no data before this date.");
}

void BitcoinExchange::processLine(const std::string &date, double value) const{
    try {
        float rate = getRate(date);
        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
}

void BitcoinExchange::processInput(const std::string &filename){
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)){
        std::string date;
        double value = 0;
        if (parseLine(line, date, value))
            processLine(date, value);
    }
}

void BitcoinExchange::loadDatabase(const std::string &filename){
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
        
    std::string line;
    std::getline(file, line); //jump date,exchange_rate
    while (std::getline(file, line)){
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue;
        std::string date = line.substr(0, pos);
        float rate = (float)strtod(line.substr(pos + 1).c_str(), NULL);
        _data[date] = rate;
    }
}