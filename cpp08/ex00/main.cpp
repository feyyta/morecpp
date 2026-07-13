/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:26:12 by mcastrat          #+#    #+#             */
/*   Updated: 2026/06/16 18:13:30 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"


int main(){
	std::vector<int> v;//dyna tab
	v.push_back(1);
	v.push_back(42);
	v.push_back(7);

	try{
		std::vector<int>::iterator it = easyfind(v, 42);
		std::cout << "found: " << *it << std::endl;
	}
	catch (std::exception &e){
		std::cerr << "not found" << std::endl;
	}

	try{
		easyfind(v, 100);
	}
	catch (std::exception &e){
		std::cerr << "not found" << std::endl;
	}

	std::list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);

	try{
		std::list<int>::iterator it = easyfind(l, 20);
		std::cout << "found: " << *it << std::endl;
	}
	catch (std::exception &e){
		std::cerr << "not found" << std::endl;
	}
	return 0;
}
