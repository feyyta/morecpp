/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:09:22 by mcastrat          #+#    #+#             */
/*   Updated: 2026/05/04 11:40:58 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){
}

Serializer::Serializer(const Serializer &src){
	(void)src;
}

Serializer& Serializer::operator=(const Serializer &rhs){
	if (this != &rhs)
		(void)rhs;
	return *this;
}

Serializer::~Serializer(){
}

uintptr_t Serializer::serialize(Data *ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}
