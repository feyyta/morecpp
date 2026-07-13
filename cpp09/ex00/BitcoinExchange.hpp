/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 08:10:01 by mcastrat          #+#    #+#             */
/*   Updated: 2026/07/03 18:25:48 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include<map>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdexcept>
#include <cstdlib>
#include <cctype>

class BitcoinExchange{
        
    private:
        std::map<std::string, float> _data;//first second
        float getRate(const std::string &date) const;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
        ~BitcoinExchange();
        void loadDatabase(const std::string &filename);
        void processInput(const std::string &filename);
        void processLine(const std::string &date, double value) const;
};

#endif