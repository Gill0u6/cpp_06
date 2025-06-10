/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:47:07 by agilles           #+#    #+#             */
/*   Updated: 2025/06/10 17:39:40 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ScalarConvert.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Argument count need to be 2" << std::endl;
		return (1);
	}
	try
	{
		ScalarConvert ScalarConvert(av[1]);
	}
	catch (ScalarConvert::ErrorException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
