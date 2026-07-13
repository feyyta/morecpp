/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 15:08:48 by mcastrat          #+#    #+#             */
/*   Updated: 2026/05/04 15:00:27 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.hpp"

int main(){
  srand(time(0));
	Base* p = generate();
	identify(p);
	identify(*p);
	delete p;
	return 0;
}
