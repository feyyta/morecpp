/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:03:00 by mcastrat          #+#    #+#             */
/*   Updated: 2026/02/18 16:53:34 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 25, 5), _target("default"){
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("presidential pardon", 25, 5), _target(target){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target){
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs){
	if (this != &rhs){
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return *this;
}

void PresidentialPardonForm::executeAction() const{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
