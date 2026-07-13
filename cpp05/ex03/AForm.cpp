/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:02:39 by mcastrat          #+#    #+#             */
/*   Updated: 2026/02/18 16:54:18 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradetosign(150), _gradetoexec(150){
}

AForm::AForm(const std::string name, int gradetosign, int gradetoexec) : _name(name), _signed(false), _gradetosign(gradetosign), _gradetoexec(gradetoexec){
	if (gradetosign < 1 || gradetoexec < 1)
		throw GradeTooHighException();
	if (gradetosign > 150 || gradetoexec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &src) : _name(src._name), _signed(src._signed), _gradetosign(src._gradetosign), _gradetoexec(src._gradetoexec){
}

AForm::~AForm(){
}

AForm& AForm::operator=(const AForm &rhs){
	if (this != &rhs)
		_signed = rhs._signed;
	return *this;
}

std::string AForm::getName() const{
	return _name;
}

bool AForm::getSigned() const{
	return _signed;
}

int AForm::getGradeToSign() const{
	return _gradetosign;
}

int AForm::getGradeToExec() const{
	return _gradetoexec;
}

void AForm::beSigned(const Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() > _gradetosign)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::execute(const Bureaucrat &executor) const{
	if (!_signed)
		throw NotSignedException();
	if (executor.getGrade() > _gradetoexec)
		throw GradeTooLowException();
	executeAction();
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "grade too high";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "grade too low";
}

const char* AForm::NotSignedException::what() const throw(){
	return "form not signed";
}

std::ostream& operator<<(std::ostream &out, const AForm &form){
	out << "AForm " << form.getName() << ", signed: ";
	if (form.getSigned())
		out << "yes";
	else
		out << "no";
	out << ", grade to sign: " << form.getGradeToSign();
	out << ", grade to execute: " << form.getGradeToExec();
	return out;
}
