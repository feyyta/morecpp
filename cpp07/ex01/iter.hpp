/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:24:11 by mcastrat          #+#    #+#             */
/*   Updated: 2026/05/25 14:42:53 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename F>
void iter(T *arr, size_t len, F f){
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

#endif
