/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:47:01 by mcastrat          #+#    #+#             */
/*   Updated: 2026/05/26 12:01:00 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array{
    private:
	    T   *_arr;
	    unsigned int    _size;
    public:
    
	    Array() : _arr(NULL), _size(0){
	    }

	    Array(unsigned int n) : _arr(new T[n]()), _size(n){
	    }
    
	    Array(const Array &src) : _arr(NULL), _size(0){
		    *this = src;
	    }

	    Array& operator=(const Array &rhs){
		    if (this != &rhs){
			    delete[] _arr;
			    _arr = new T[rhs._size];
			    _size = rhs._size;
			    for (unsigned int i = 0; i < _size; i++)
				    _arr[i] = rhs._arr[i];
		    }
		    return *this;
	    }

	    ~Array(){
		    delete[] _arr;
	    }

	    T& operator[](unsigned int i){
		    if (i >= _size)
			    throw std::exception();
		    return _arr[i];
	    }

	    const T& operator[](unsigned int i) const{
		    if (i >= _size)
			    throw std::exception();
		    return _arr[i];
	    }

	    unsigned int size() const{
		    return _size;
	    }
};

#endif
