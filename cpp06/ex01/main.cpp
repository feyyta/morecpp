/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:09:17 by mcastrat          #+#    #+#             */
/*   Updated: 2026/05/04 13:32:34 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(){
	
	Data data;
	data.value = 42;
	data.name = "booba";

	uintptr_t raw = Serializer::serialize(&data);//reintrepret les bit brut voi ptr en data(nbr) et inversm depuis l addrs
	Data* ptr = Serializer::deserialize(raw);

	std::cout << "data = " << &data << std::endl;
	std::cout << "serialiezd = " << raw << std::endl;
	std::cout << "deserialized " << ptr << std::endl;
	if (ptr == &data)
		std::cout << "same ?  yes bro" << std::endl;
	else
		std::cout << "same ? no bro" << std::endl;
	std::cout << "ptr val = " << ptr->value << std::endl;
	std::cout << "ptr name = " << ptr->name << std::endl;
	return 0;
}
