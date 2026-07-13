/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:44:52 by mcastrat          #+#    #+#             */
/*   Updated: 2026/04/28 16:44:58 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
}

Intern::~Intern(){
}

Intern::Intern(const Intern &src){
	(void)src; 
}

Intern& Intern::operator=(const Intern &rhs){
	(void)rhs; 
	return *this;
}

static AForm*	makeShrubbery(const std::string &t){
	return new ShrubberyCreationForm(t);
}

static AForm*	makeRobotomy(const std::string &t){
	return new RobotomyRequestForm(t);
}

static AForm*	makePardon(const std::string &t){
	return new PresidentialPardonForm(t);
}

AForm*	Intern::makeForm(const std::string &formName, const std::string &target) const{
	std::string		names[3];
	AForm*			(*ft[3])(const std::string &);

	names[0] = "shrubbery creation";
	names[1] = "robotomy request";
	names[2] = "presidential pardon";
	ft[0] = makeShrubbery; 
	ft[1] = makeRobotomy;
	ft[2] = makePardon;

	for (int i = 0; i < 3; i++){
		if (formName == names[i]){
			std::cout << "Intern creates " << formName << std::endl;
			return ft[i](target); //appelle la bonne fonctio  retourne un AForm* alloue avec new
		}
	}
	std::cout << "Intern: unknown form " << formName << std::endl;
	return NULL; //appelant doit verifier si NULL avant d utiliser
}
