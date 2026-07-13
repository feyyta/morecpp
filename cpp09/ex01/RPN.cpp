/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 08:20:58 by mcastrat          #+#    #+#             */
/*   Updated: 2026/07/03 18:54:10 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPN::RPN(){
}

RPN::RPN(const RPN &src){
    *this = src;
}

RPN& RPN::operator=(const RPN &rhs){
    if (this != &rhs)
        _stack = rhs._stack;
    return (*this);
}

RPN::~RPN(){
}

static int isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::applyOperator(char op){
    if (_stack.size() < 2)
        throw std::runtime_error("Error");
        
    long b = _stack.top();
    _stack.pop();//retire
    long a = _stack.top();
    _stack.pop();

    switch (op){
        case '+': _stack.push(a + b);
            break;
        case '-': _stack.push(a - b);
            break;
        case '*': _stack.push(a * b); 
            break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error");
            _stack.push(a / b);
            break;
    }
}

long RPN::eval(const std::string &input){
    std::istringstream flux(input);
    std::string token;

    while (flux >> token){
        if (token.size() == 1 && isdigit(token[0]))
            _stack.push(token[0] - '0'); // tk < 10
        else if (token.size() == 1 && isOperator(token[0]))
            applyOperator(token[0]);
        else
            throw std::runtime_error("Error");
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error");
    return (_stack.top());
}
