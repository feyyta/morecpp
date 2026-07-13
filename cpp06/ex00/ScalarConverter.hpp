/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:13:20 by mcastrat          #+#    #+#             */
/*   Updated: 2026/04/26 16:09:02 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <iomanip>//


class ScalarConverter{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter& operator=(const ScalarConverter &rhs);
		~ScalarConverter();
	public:
		static void convert(const std::string &literal);
};

#endif
