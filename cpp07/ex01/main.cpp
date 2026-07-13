/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:23:42 by mcastrat          #+#    #+#             */
/*   Updated: 2026/06/09 14:53:15 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(T const &x){
	std::cout << x << std::endl;
}

int main(){
	int tab[] = {1, 2, 3, 4, 5};
	std::string w[] = {"seksi", "briket", "gang"};

	std::cout << "print int" << std::endl;
	::iter(tab, 5, print<int>);

	std::cout << "print string" << std::endl;
	::iter(w, 3, print<std::string>);

	std::cout << "const array" << std::endl;
	const int ctab[] = {5238, 21, 39};
	::iter(ctab, 3, print<int>);

	return 0;
}
