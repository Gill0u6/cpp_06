/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:33:07 by agilles           #+#    #+#             */
/*   Updated: 2025/06/04 17:16:37 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ScalarConvert
{
	private:
		std::string const	_input;
		char				_char;
		int					_int;
		float				_float;
		double				_double;

	public:
		ScalarConvert(std::string input);
		ScalarConvert(const ScalarConvert &cp);

		~ScalarConvert();

		void fromChar();
		void fromInt();
		void fromFloat();
		void fromDouble();

		std::string	getInput()const;
		double		getDouble();
		float		getFloat();
		char		getChar();
		int			getInt();
};
