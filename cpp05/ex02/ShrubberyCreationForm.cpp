/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:04:02 by mcastrat          #+#    #+#             */
/*   Updated: 2026/03/10 16:53:21 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137), _target("default"){
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("shrubbery creation", 145, 137), _target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target){ //AForm(src) appelle le copy constructor du parent
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs){
	if (this != &rhs){
		AForm::operator=(rhs); //gere la partie heritee (_signed)
		_target = rhs._target;
	}
	return *this;
}

void ShrubberyCreationForm::executeAction() const{
	std::ofstream file((_target + "_shrubbery").c_str()); //.c_str() converti string en char* pour ofstream
	file << "      *      " << std::endl;
	file << "     ***     " << std::endl;
	file << "    *****    " << std::endl;
	file << "   *******   " << std::endl;
	file << "  *********  " << std::endl;
	file << "      |      " << std::endl;
	file << "      |      " << std::endl;
}
