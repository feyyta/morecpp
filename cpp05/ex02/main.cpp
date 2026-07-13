/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:53:44 by mcastrat          #+#    #+#             */
/*   Updated: 2026/03/10 17:16:30 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
	try{
		Bureaucrat bob("bob", 137);
		ShrubberyCreationForm f1("garden");
		std::cout << f1 << std::endl;
		bob.signForm(f1);
		bob.executeForm(f1);
	}
	catch (std::exception &e){
		std::cout << "exception: " << e.what() << std::endl;
	}

	try{
		Bureaucrat alice("apou", 45);
		RobotomyRequestForm f2("bro");
		std::cout << f2 << std::endl;
		alice.signForm(f2);
		alice.executeForm(f2);
		alice.executeForm(f2);
	}
	catch (std::exception &e){
		std::cout << "exception: " << e.what() << std::endl;
	}

	try{
		Bureaucrat chief("chief", 5);
		PresidentialPardonForm f3("naps");
		std::cout << f3 << std::endl;
		chief.signForm(f3);
		chief.executeForm(f3);
	}
	catch (std::exception &e){
		std::cout << "exception: " << e.what() << std::endl;
	}

	try{
		Bureaucrat intern("intern", 150);
		ShrubberyCreationForm f4("lol");
		intern.signForm(f4);
		intern.executeForm(f4);
	}
	catch (std::exception &e){
		std::cout << "exception: " << e.what() << std::endl;
	}

	try{
		Bureaucrat bob2("bob2", 137);
		ShrubberyCreationForm f5("park");
		bob2.executeForm(f5);
	}
	catch (std::exception &e){
		std::cout << "exception: " << e.what() << std::endl;
	}
	return 0;
}
