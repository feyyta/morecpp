/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 15:08:43 by mcastrat          #+#    #+#             */
/*   Updated: 2026/05/05 17:16:26 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.hpp"

Base* generate(void){
	int r = rand() % 3;
	
	if (r == 0)
		return new A();
	if (r == 1)
		return new B();
	return new C();
}

void identify(Base *p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p){
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception&){}

	try{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception&){
		//std::cerr << e.what() << std::endl; 
	}
	
	try{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception&){}
	
	std::cout << "C" << std::endl;
}
