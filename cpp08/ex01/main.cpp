/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:28:22 by mcastrat          #+#    #+#             */
/*   Updated: 2026/06/16 18:37:50 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;

int arr[] = {23, 1, 3, 4, 5};
Span sp2 = Span(5);
sp2.addRange(arr, arr + 5);
std::cout << sp2.shortestSpan() << std::endl;
std::cout << sp2.longestSpan() << std::endl;
return 0;
}
