/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:13:58 by mcastrat          #+#    #+#             */
/*   Updated: 2026/04/26 16:04:23 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av){
	
	if (ac != 2){
		std::cerr << "Usage exemple: ./converter 32" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}
