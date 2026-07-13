/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 08:10:03 by mcastrat          #+#    #+#             */
/*   Updated: 2026/07/03 16:23:56 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstring>

static int checkExt(char *str)
{
    int len = strlen(str);
    if (len < 4)
          return 1;
    return strcmp(str + len - 4, ".txt") != 0;
}

int main(int argc, char **argv){
    if (argc != 2 || checkExt(argv[1])){
        std::cerr << "Error: could not open file" << std::endl;
        return (1);
    }

    BitcoinExchange btc;
    try {
        btc.loadDatabase("data.csv");
        btc.processInput(argv[1]);
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
