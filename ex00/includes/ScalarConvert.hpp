/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:33:07 by agilles           #+#    #+#             */
/*   Updated: 2025/06/10 17:38:16 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <limits>
#include <stdlib.h>

#define NAN_INF 1
#define ERROR 2
#define CHAR 3
#define INT 4
#define FLOAT 5
#define DOUBLE 6

class ScalarConvert
{
	private:
		std::string const	_input;
		int					_type;

		char				_char;
		int					_int;
		float				_float;
		double				_double;

		ScalarConvert();

		void fromChar();
		void fromInt();
		void fromFloat();
		void fromDouble();

		std::string	getInput()const;
		double		getDouble()const;
		float		getFloat()const;
		char		getChar()const;
		int			getInt()const;
		int			getType()const;

		void	ConvertInput();
		int		checkInput();

		void	printOutput();

	public:
		ScalarConvert(std::string input);
		ScalarConvert(const ScalarConvert &cp);

		~ScalarConvert();

		ScalarConvert &operator=(const ScalarConvert &cp);

		class ErrorException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
