/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:00:00 by mcastrat          #+#    #+#             */
/*   Updated: 2026/07/03 14:32:39 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe &src){
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs){
    if (this != &rhs){
        _vec = rhs._vec;
        _deq = rhs._deq;
    }
    return (*this);
}

PmergeMe::~PmergeMe(){
}

static std::vector<size_t> jacobsthalOrder(size_t ssize){
    static const size_t ja[] = {3, 5, 11, 21, 43, 85, 171, 341, 683, 1365,
                                   2731, 5461, 10923, 21845, 43691, 87381,
                                   174763, 349525, 699051, 1398101, 2796203};
    static const size_t nja = sizeof(ja) / sizeof(ja[0]);
    
    std::vector<size_t> order;
    if (ssize == 0)
        return (order);
    order.push_back(0);
    size_t prev = 1;
    for (size_t g = 0; prev < ssize; ++g){
        size_t limit = ssize;
        if (g < nja && ja[g] < ssize)
            limit = ja[g];
        for (size_t i = limit; i > prev; --i)
            order.push_back(i - 1);
        prev = limit;
    }
    return (order);
}

template <typename T>
static void binaryInsert(T &sorted, int val){
    typename T::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), val);
    sorted.insert(pos, val);
}

template <typename T>
static void fordJohnson(T &c){
    if (c.size() < 2)
        return;
    T s;
    T b;
    size_t pairs = c.size() - (c.size() % 2);
    for (size_t i = 0; i < pairs; i += 2){//pairs
        if (c[i] < c[i + 1]){
            s.push_back(c[i]);
            b.push_back(c[i + 1]);
        }
        else{
            s.push_back(c[i + 1]);
            b.push_back(c[i]);
        }
    }
    int x = c.size() % 2;
    fordJohnson(b);//trie recur les big
    std::vector<size_t> order = jacobsthalOrder(s.size());//orde d insert des petit
    for (size_t i = 0; i < order.size(); ++i)//inseert
        binaryInsert(b, s[order[i]]);//dans l orde ja
    if (x)
        binaryInsert(b, c.back());
    c = b;
}

void PmergeMe::sortVector(std::vector<int> &v){
    fordJohnson(v);
}

void PmergeMe::sortDeque(std::deque<int> &d){
    fordJohnson(d);
}

static void printSeq(const std::string &input, const std::vector<int> &v){
    std::cout << input;
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << " " << v[i];
    std::cout << std::endl;
}

static double timeu(){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000.0 + tv.tv_usec);//micro
}

void PmergeMe::run(){
    printSeq("before:", _vec);
    double startVec = timeu();
    std::vector<int> v(_vec);//gestion des donnees : remplissage du conteneur de travail
    sortVector(v);
    double endVec = timeu();
    _vec = v;

    double startDeq = timeu();
    std::deque<int> d(_deq);//pareil pour la deque
    sortDeque(d);
    double endDeq = timeu();
    _deq = d;

    printSeq("after: ", _vec);
    double usVec = endVec - startVec;
    double usDeq = endDeq - startDeq;
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << usVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : " << usDeq << " us" << std::endl;
}

static int toPositiveInt(const std::string &v){
    if (v.empty())
        throw std::runtime_error("Error");
    for (size_t i = 0; i < v.size(); ++i){
        if (v[i] < '0' || v[i] > '9')
            throw std::runtime_error("Error");
    }
    long value = std::strtol(v.c_str(), NULL, 10);//overflow hdl
    if (value > INT_MAX)
        throw std::runtime_error("Error");
    return (static_cast<int>(value));
}

void PmergeMe::parse(int argc, char **argv){
    for (int i = 1; i < argc; ++i){
        std::istringstream flux(argv[i]);//lis mot par mot
        std::string word;
        while (flux >> word){
            int n = toPositiveInt(word);
            _vec.push_back(n);
            _deq.push_back(n);
        }
    }
    if (_vec.empty() || _deq.empty())
        throw std::runtime_error("Error");
}