/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 15:08:45 by mcastrat          #+#    #+#             */
/*   Updated: 2026/04/26 15:44:06 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

#include <iostream>
#include <exception>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*   generate(void);
void    identify(Base *p);
void    identify(Base &p);

#endif
