/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:09:25 by mcastrat          #+#    #+#             */
/*   Updated: 2026/04/26 16:03:44 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"
#include "iostream"	

class Serializer{
    private:
	    Serializer();
	    Serializer(const Serializer &src);
	    Serializer& operator=(const Serializer &rhs);
	    ~Serializer();
    public:
	    static uintptr_t    serialize(Data *ptr);
	    static Data*        deserialize(uintptr_t raw);
};

#endif
