/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:56:15 by mcastrat          #+#    #+#             */
/*   Updated: 2026/04/28 16:00:42 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _signed(false), _gradetosign(150), _gradetoexec(150){
}

Form::Form(const std::string name, int gradetosign, int gradetoexec) : _name(name), _signed(false), _gradetosign(gradetosign), _gradetoexec(gradetoexec){
	if (gradetosign < 1 || gradetoexec < 1)
		throw GradeTooHighException();
	if (gradetosign > 150 || gradetoexec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &src) : _name(src._name), _signed(src._signed), _gradetosign(src._gradetosign), _gradetoexec(src._gradetoexec){
}

Form::~Form(){
}

Form& Form::operator=(const Form &rhs){
	if (this != &rhs){
		_signed = rhs._signed;
	}
	return *this; 
}

std::string Form::getName() const{
	return _name;
}

bool Form::getSigned() const{
	return _signed;
}

int Form::getGradeToSign() const{
	return _gradetosign;
}

int Form::getGradeToExec() const{
	return _gradetoexec;
}

void Form::beSigned(const Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() > _gradetosign)
		throw GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream &out, const Form &form){
	out << "Form " << form.getName() << ", signed: ";
	if (form.getSigned())
		out << "yes";
	else
		out << "no";
	out << ", grade to sign: " << form.getGradeToSign();
	out << ", grade to execute: " << form.getGradeToExec();
	return out;
}
