/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:46:33 by mcastrat          #+#    #+#             */
/*   Updated: 2026/06/10 07:39:25 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(){
    Array<int> r;
	std::cout << "r=" << r.size() << std::endl;
	
	Array<int> a(10);//
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i + 1;
        
	Array<int> b(a);//cpy
	b[0] = 444;
	std::cout << "a[0]=" << a[9] << " b[0]=" << b[0] << std::endl;

	try{
		a[12] = 67;
		std::cout << "a[x]=" << a[7] << std::endl;
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	Array<std::string> s(2);
	s[0] = "briket";
	s[1] = "seksi";
	for (unsigned int i = 0; i < s.size(); i++)
		std::cout << s[i] << std::endl;
	return 0;
}
