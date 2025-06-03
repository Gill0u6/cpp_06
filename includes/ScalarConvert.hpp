/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:33:07 by agilles           #+#    #+#             */
/*   Updated: 2025/06/03 17:35:50 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

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

};
