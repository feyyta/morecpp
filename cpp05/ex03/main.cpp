/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:03:29 by mcastrat          #+#    #+#             */
/*   Updated: 2026/04/28 16:29:11 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp" 

int main(){
	Intern intern;

	try{
		AForm *f1 = intern.makeForm("shrubbery creation", "garden");
		Bureaucrat bob("bob", 137);
		bob.signForm(*f1);
		bob.executeForm(*f1);
		delete f1;
	}
	catch (std::exception &e){
		std::cout << "exception: " << e.what() << std::endl;
	}

	try{
		AForm *f2 = intern.makeForm("robotomy request", "bro");
		Bureaucrat alice("apou", 45);
		alice.signForm(*f2);
		alice.executeForm(*f2);
		delete f2;
	}
	catch (std::exception &e){
		std::cout << "exception: " << e.what() << std::endl;
	}

	try{
		AForm *f3 = intern.makeForm("presidential pardon", "naps");
		Bureaucrat chief("chief", 5);
		chief.signForm(*f3);
		chief.executeForm(*f3);
		delete f3;
	}
	catch (std::exception &e){
		std::cout << "exception: " << e.what() << std::endl;
	}

	try{
		AForm *f4 = intern.makeForm("unknown form", "target");
		if (f4)
			delete f4;
	}
	catch (std::exception &e){
		std::cout << "exception: " << e.what() << std::endl;
	}
	return 0;
}
