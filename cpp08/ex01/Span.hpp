/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:28:28 by mcastrat          #+#    #+#             */
/*   Updated: 2026/06/16 18:37:01 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <climits>

class Span{
private:
	unsigned int		_max;
	std::vector<int>	_v;
public:
	Span();
	Span(unsigned int n);
	Span(const Span &src);
	Span& operator=(const Span &rhs);
	~Span();

	void	addNumber(int n);
	int		shortestSpan() const;
	int		longestSpan() const;

	template <typename it>
	void addRange(it begin, it end){
		if (std::distance(begin, end) + _v.size() > _max)
			throw std::exception();
		_v.insert(_v.end(), begin, end);
	}
};

#endif
