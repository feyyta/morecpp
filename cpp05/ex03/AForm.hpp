/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:02:31 by mcastrat          #+#    #+#             */
/*   Updated: 2026/03/10 17:13:45 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <exception> 

class Bureaucrat;

class AForm{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradetosign;
		const int			_gradetoexec;

	public:
		AForm();
		virtual ~AForm();
		AForm(const std::string name, int gradetosign, int gradetoexec);
		AForm(const AForm &src);
		AForm&	operator=(const AForm &rhs);
		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;
		void		beSigned(const Bureaucrat &bureaucrat);
		void		execute(const Bureaucrat &executor) const;
		virtual void	executeAction() const = 0;

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
	class NotSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &out, const AForm &form);

#endif
