/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:53:51 by mcastrat          #+#    #+#             */
/*   Updated: 2026/02/18 15:23:03 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	try{
		Form f1("tax", 50, 25);
		std::cout << f1 << std::endl;
		Form f2("contract", 0, 25);
		std::cout << f2 << std::endl;
	}
	catch (std::exception &e){
		std::cout << "exception: " << e.what() << std::endl;
	}

	try{
		Form f3("permit", 50, 151);
		std::cout << f3 << std::endl;
	}
	catch (std::exception &e){
		std::cout << "exception: " << e.what() << std::endl;
	}

	try{
		Bureaucrat bob("bob", 30);
		Form f4("request", 50, 40);
		std::cout << f4 << std::endl;
		bob.signForm(f4);
		std::cout << f4 << std::endl;
	}
	catch (std::exception &e){
		std::cout << "exception: " << e.what() << std::endl;
	}

	try{
		Bureaucrat alice("bro", 100);
		Form f5("classified", 50, 25);
		std::cout << f5 << std::endl;
		alice.signForm(f5);
		std::cout << f5 << std::endl;
	}
	catch (std::exception &e){
		std::cout << "exception: " << e.what() << std::endl;
	}

	try{
		Bureaucrat chief("chief", 1);
		Form f6("top secret", 1, 1);
		std::cout << f6 << std::endl;
		chief.signForm(f6);
		std::cout << f6 << std::endl;
	}
	catch (std::exception &e){
		std::cout << "exception: " << e.what() << std::endl;
	}

	return 0;
}
