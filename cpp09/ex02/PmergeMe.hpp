/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:00:00 by mcastrat          #+#    #+#             */
/*   Updated: 2026/07/01 14:06:41 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <sys/time.h>

class PmergeMe{

    private:
        std::vector<int> _vec;
        std::deque<int> _deq;
        void sortVector(std::vector<int> &v);
        void sortDeque(std::deque<int> &d);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &rhs);
        ~PmergeMe();
        void parse(int argc, char **argv);
        void run();
};

#endif
