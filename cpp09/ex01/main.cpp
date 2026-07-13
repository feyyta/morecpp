/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 08:20:48 by mcastrat          #+#    #+#             */
/*   Updated: 2026/07/03 16:26:49 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv){
    if (argc != 2){
        std::cerr << "Error" << std::endl;
        return (1);
    }
    RPN rpn;
    try {
        std::cout << rpn.eval(argv[1]) << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
