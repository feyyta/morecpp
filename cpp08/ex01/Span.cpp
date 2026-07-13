/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:28:24 by mcastrat          #+#    #+#             */
/*   Updated: 2026/06/16 18:36:39 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _max(0){
}

Span::Span(unsigned int n) : _max(n){
}

Span::Span(const Span &src) : _max(src._max), _v(src._v){
}

Span& Span::operator=(const Span &rhs){
	if (this != &rhs){
		_max = rhs._max;
		_v = rhs._v;
	}
	return *this;
}

Span::~Span(){
}

void Span::addNumber(int n){
	if (_v.size() >= _max)
		throw std::exception();
	_v.push_back(n);
}

int Span::shortestSpan() const{
	int shortest = INT_MAX;
	
	if (_v.size() < 2)
		throw std::exception();
	std::vector<int> tmp(_v);
	std::sort(tmp.begin(), tmp.end());
	//int shortest = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size(); i++){
		if (tmp[i] - tmp[i - 1] < shortest)
			shortest = tmp[i] - tmp[i - 1];
	}
	return shortest;
}

int Span::longestSpan() const{
	if (_v.size() < 2)
		throw std::exception();
	std::vector<int> tmp(_v);
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];//-1 bc size chope elem
}

