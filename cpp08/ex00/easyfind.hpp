/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:26:09 by mcastrat          #+#    #+#             */
/*   Updated: 2026/06/16 17:17:10 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <list>

template <typename T>
typename T::iterator easyfind(T &ctn, int v){
	typename T::iterator it = std::find(ctn.begin(), ctn.end(), v);
	if (it == ctn.end())
		throw std::exception();
	return it;
}

#endif
