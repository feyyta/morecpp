/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:53:45 by mcastrat          #+#    #+#             */
/*   Updated: 2026/03/10 16:49:26 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150){
	//std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name){
	//std::cout << "Bureaucrat parametric constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade){
	//std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(){
	//std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs){
	//std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this != &rhs){
		_grade = rhs._grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const{
	return _grade;
}

void Bureaucrat::incrementGrade(){
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade(){
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat){
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}
