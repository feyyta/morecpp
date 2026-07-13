/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:30:47 by mcastrat          #+#    #+#             */
/*   Updated: 2026/06/16 18:55:57 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

/*
  class stack {
  protected:
        Container c;         
  public:
        void push(const T& x){ c.push_back(x); }
        void pop(){ c.pop_back(); }
        T& top(){ return c.back(); }
        size_t size() const{ return c.size(); }
  };
*/

template <typename T>
class MutantStack : public std::stack<T>{
public:
	MutantStack(){
	}

	MutantStack(const MutantStack &src) : std::stack<T>(src){
	}

	MutantStack& operator=(const MutantStack &rhs){
		if (this != &rhs)
			std::stack<T>::operator=(rhs);
		return *this;
	}

	~MutantStack(){
	}
	//type
	typedef typename std::stack<T>::container_type::iterator it;//expose dequeu ctn donc it
	
	it begin(){
		return this->c.begin();
	}
	it end(){
		return this->c.end();
	}
};

#endif
