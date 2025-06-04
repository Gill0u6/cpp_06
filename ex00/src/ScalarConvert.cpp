/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:34:27 by agilles           #+#    #+#             */
/*   Updated: 2025/06/04 17:18:41 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConvert.hpp"

ScalarConvert::ScalarConvert(std::string input): _input(input)
{
	std::cout << "ScalarConvert input constructor called for " << input << std::endl;
}

ScalarConvert::ScalarConvert(const ScalarConvert &cp)
{
	std::cout << "ScalarConvert copy constructor called" << std::endl;
}

ScalarConvert::~ScalarConvert()
{
	std::cout << "ScalarConvert deconstructor called" << std::endl;
}

char	ScalarConvert::getChar()
{
	return (this->_char);
}

int		ScalarConvert::getInt()
{
	return (this->_int);
}

float	ScalarConvert::getFloat()
{
	return (this->_float);
}

double	ScalarConvert::getDouble()
{
	return (this->_double);
}

std::string	ScalarConvert::getInput()const
{
	return (this->_input);
}

void ScalarConvert::fromChar(void)
{
	this->_char = static_cast<unsigned char>(this->getInput()[0]);
	this->_int = static_cast<int>(this->getChar());
	this->_float = static_cast<float>(this->getChar());
	this->_double = static_cast<double>(this->getChar());
}

void ScalarConvert::fromInt(void)
{
	this->_int = static_cast<int>(this->getDouble());
	this->_char = static_cast<unsigned char>(this->getInt());
	this->_float = static_cast<float>(this->getDouble());
}

void ScalarConvert::fromFloat(void)
{

}

void ScalarConvert::fromDouble(void)
{

}

