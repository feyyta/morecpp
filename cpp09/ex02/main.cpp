/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:00:00 by mcastrat          #+#    #+#             */
/*   Updated: 2026/06/30 17:00:00 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv){
    PmergeMe sorter;
    try {
        sorter.parse(argc, argv);
        sorter.run();
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
