/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:04:02 by mcastrat          #+#    #+#             */
/*   Updated: 2026/03/10 17:13:09 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137), _target("default"){
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("shrubbery creation", 145, 137), _target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target){
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs){
	if (this != &rhs){
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return *this;
}

void ShrubberyCreationForm::executeAction() const{
	std::ofstream file((_target + "_shrubbery").c_str());
	file << "      *      " << std::endl;
	file << "     ***     " << std::endl;
	file << "    *****    " << std::endl;
	file << "   *******   " << std::endl;
	file << "  *********  " << std::endl;
	file << "      |      " << std::endl;
	file << "      |      " << std::endl;
}
