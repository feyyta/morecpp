/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:53:45 by mcastrat          #+#    #+#             */
/*   Updated: 2026/03/10 16:51:20 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150){
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name){
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade){
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs){
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

void Bureaucrat::signForm(AForm &form){
	try{
		form.beSigned(*this); //*this = le bureaucrat lui meme
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e){ //si grade insuffisant beSigned lance une exception
		std::cout << _name << " couldn't sign " << form.getName();
		std::cout << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form) const{
	try{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e){ //pas signe ou grade insuffisant
		std::cout << _name << " couldn't execute " << form.getName();
		std::cout << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat){
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}
