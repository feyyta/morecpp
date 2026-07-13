/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:53:51 by mcastrat          #+#    #+#             */
/*   Updated: 2026/03/10 15:51:24 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){
	try{
		Bureaucrat bob("naps", 2);
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;

	}
	catch (std::exception &e){
		std::cout << "exception: " << e.what() << std::endl;
	}
	
	try{
		Bureaucrat alice("jul", 151);
	}
	catch (std::exception &e){
		std::cout << "exception: " << e.what() << std::endl;
	}

	try{
		Bureaucrat charlie("yeye", 149);
		std::cout << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << charlie << std::endl;
		charlie.decrementGrade();
	}
	catch (std::exception &e){
		std::cout << "exception: " << e.what() << std::endl;
	}
	return 0;
}
