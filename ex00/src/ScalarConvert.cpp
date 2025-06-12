/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:34:27 by agilles           #+#    #+#             */
/*   Updated: 2025/06/12 17:05:30 by agilles          ###   ########.fr       */
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
	this->_double = atof(this->getInput().c_str());
	this->ConvertInput();
	this->printOutput();
}

ScalarConvert::ScalarConvert(const ScalarConvert &cp)
{
	std::cout << "ScalarConvert copy constructor called" << std::endl;
	*this = cp;
	this->printOutput();
}

ScalarConvert::~ScalarConvert()
{
	std::cout << "ScalarConvert deconstructor called" << std::endl;
}

void	ScalarConvert::printOutput()
{
	if (this->getType() == ERROR)
		throw ScalarConvert::ErrorException();
	else
	{
		if (this->getType() != NAN_INF && this->getDouble() <= 255 && this->getDouble() >= 0)
		{
			if (isprint(this->getChar()))
				std::cout << "char: '" << this->getChar() << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;

		if (this->getType() != NAN_INF && this->getDouble() >= std::numeric_limits<int>::min() && this->getDouble() <= std::numeric_limits<int>::max())
			std::cout << "int: " << this->getInt() << std::endl;
		else
			std::cout << "int: impossible" << std::endl;

		if (this->getType() != NAN_INF)
		{
			std::cout << "float: " << this->getFloat();
			if (this->getFloat() - this->getInt() == 0)
				std::cout << ".0f" << std::endl;
			else
				std::cout << "f" << std::endl;
		}
		else
		{
			if (this->getInput() == "nan" || this->getInput() == "nanf")
				std::cout << "float: nanf" << std::endl;
			else if (this->getInput()[0] == '+')
				std::cout << "float: +inff" << std::endl;
			else
				std::cout << "float: -inff" << std::endl;
		}

		if (this->getType() != NAN_INF)
		{
			std::cout << "double: " << this->getDouble();
			if (this->getDouble() < std::numeric_limits<int>::min() || this->getDouble() > std::numeric_limits<int>::max() ||
					this->getDouble() - this->getInt() == 0)
				std::cout << ".0" << std::endl;
			else
				std::cout << std::endl;
		}
		else
		{
			if (this->getInput() == "nan" || this->getInput() == "nanf")
				std::cout << "double: nan" << std::endl;
			else if (this->getInput()[0] == '+')
				std::cout << "double: +inf" << std::endl;
			else
				std::cout << "double: -inf" << std::endl;
		}
	}
}

int		ScalarConvert::getType()const
{
	return (this->_type);
}

char	ScalarConvert::getChar()const
{
	return (this->_char);
}

int		ScalarConvert::getInt()const
{
	return (this->_int);
}

float	ScalarConvert::getFloat()const
{
	return (this->_float);
}

double	ScalarConvert::getDouble()const
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
	this->_float = static_cast<float>(this->getDouble());
	this->_int = static_cast<int>(this->getFloat());
	this->_char = static_cast<char>(this->getFloat());
}

void ScalarConvert::fromDouble(void)
{
	this->_char = static_cast<char>(this->getDouble());
	this->_int = static_cast<int>(this->getDouble());
	this->_float = static_cast<float>(this->getDouble());
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
				isdigit(this->getInput()[this->getInput().find_first_of(".") + 1]) == 0 ||
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

	for (int i = 0; i < 4; i++)
	{
		if (types[i] == this->_type)
		{
			(this->*fromPTRS[i])();
			break;
		}
	}
}

const char *ScalarConvert::ErrorException::what(void) const throw()
{
	return ("Error: Impossible to convert");
}

ScalarConvert &ScalarConvert::operator=(const ScalarConvert &cp)
{
	std::cout << "ScalarConvert assignation operator called" << std::endl;
	if (this == &cp)
		return (*this);

	this->_int = cp.getInt();
	this->_char = cp.getChar();
	this->_double = cp.getDouble();
	this->_float = cp.getFloat();
	this->_type = cp.getType();

	return (*this);

}

