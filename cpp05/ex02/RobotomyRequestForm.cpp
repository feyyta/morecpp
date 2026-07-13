/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:03:21 by mcastrat          #+#    #+#             */
/*   Updated: 2026/03/10 17:09:36 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45), _target("default"){
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("robotomy request", 72, 45), _target(target){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target){
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs){
	if (this != &rhs){
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return *this;
}

void RobotomyRequestForm::executeAction() const{
	std::cout << "BZZZZZZZT DRRRRRR VRRRRRRR" << std::endl;
	if (std::rand() % 2) //50  0 ou 1
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomy failed" << std::endl;
}
