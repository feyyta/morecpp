/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:03:10 by mcastrat          #+#    #+#             */
/*   Updated: 2026/03/10 17:12:40 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP 

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm &rhs);
		void	executeAction() const;
};

#endif
