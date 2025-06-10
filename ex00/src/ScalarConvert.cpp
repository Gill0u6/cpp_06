/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:34:27 by agilles           #+#    #+#             */
/*   Updated: 2025/06/10 16:17:24 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConvert.hpp"

ScalarConvert::ScalarConvert()
{
	std::cout << "ScalarConvert Default constructor called" << std::endl;
}

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

int	ScalarConvert::checkInput()
{
	if (this->getInput().compare("nan") == 0 || this->getInput().compare("+inf") == 0 ||
			this->getInput().compare("-inf")  == 0 || this->getInput().compare("+inff") == 0 || this->getInput().compare("-inff") == 0)
		return (NAN_INF);
	else if (this->getInput().length() == 1 &&
				(this->getInput()[0] == '+' || this->getInput()[0] == '-' ||
				this->getInput()[0] == 'f' || this->getInput()[0] == '.'))
		return (CHAR);
	else if (this->getInput().find_first_of("+-") != this->getInput().find_last_of("+-"))
		return (ERROR);
	else if (this->getInput().find_first_not_of("+-0123456789") == std::string::npos)
		return (INT);
	else if (this->getInput().find_first_not_of("+-0123456789.") == std::string::npos)
	{
		if (this->getInput().find_first_of(".") != this->getInput().find_last_of(".") ||
				isdigit(this->getInput()[this->getInput().find_first_of(".") + 1]) != 0 ||
				this->getInput().find_first_of(".") == 0
				)
			return (ERROR);
		return (DOUBLE);
	}
	else if (this->getInput().find_first_not_of("+-0123456789.f") == std::string::npos)
	{
		if (this->getInput().find_first_of(".") != this->getInput().find_last_of(".") ||
				this->getInput().find_first_of("f") != this->getInput().find_last_of("f") ||
				this->getInput().find_first_of("f") - this->getInput().find_first_of(".") == 1 ||
				this->getInput().find_first_of(".") == 0 ||
				this->getInput()[this->getInput().find_first_of("f") + 1] != '\0'
				)
			return (ERROR);
		return (FLOAT);
	}
	else if ((this->getInput().length() == 1 && isalpha(this->getInput()[0])) ||
				(this->getInput().length() == 1 && isprint(this->getInput()[0])))
		return (CHAR);
	return (ERROR);
}

void ScalarConvert::ConvertInput()
{
	void	(ScalarConvert::*fromPTRS[])(void) = {
				&ScalarConvert::fromChar,
				&ScalarConvert::fromInt,
				&ScalarConvert::fromFloat,
				&ScalarConvert::fromDouble
			};
	int		types[] = {CHAR, INT, FLOAT, DOUBLE};

	this->_type = checkInput();

	if (this->_type == NAN_INF)
		return ;

	for (int i = 0; i++; i < 4)
	{
		if (types[i] == this->_type)
		{
			(this->*fromPTRS[i])();
			break;
		}
	}
}

