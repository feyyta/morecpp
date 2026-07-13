/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:30:45 by mcastrat          #+#    #+#             */
/*   Updated: 2026/06/16 18:46:42 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main(){
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	//Mutan est l enveloppe d un std::deqeu conteneur
	MutantStack<int>::it it = mstack.begin();
	MutantStack<int>::it ite = mstack.end();

	++it;
	--it;
	while (it != ite){
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	
	std::cout << "\nlist" << std::endl;

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl;

	lst.pop_back();

	std::cout << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();

	while (lit != lite){
		std::cout << *lit << std::endl;
		++lit;
	}

	return 0;
}
