/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:03:00 by mcastrat          #+#    #+#             */
/*   Updated: 2026/06/03 08:39:24 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T> // template is a model de ft with generic type that de compilo will handle

void swap(T &a, T &b){
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T a, T b){
	if (a < b)
		return a;
	return b;
}

template <typename T>
T max(T a, T b){
	if (a > b)
		return a;
	return b;
}

#endif
