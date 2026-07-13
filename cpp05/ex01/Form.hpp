/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:55:17 by mcastrat          #+#    #+#             */
/*   Updated: 2026/03/10 17:14:57 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception> 

class Bureaucrat;

class Form{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradetosign;
		const int			_gradetoexec;
	public:
		Form();
		~Form();
		Form(const std::string name, int gradetosign, int gradetoexec);
		Form(const Form &src);
		Form& operator=(const Form &rhs);
		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;
		void		beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &out, const Form &form);

#endif
