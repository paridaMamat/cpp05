/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:48:37 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/23 12:13:12 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main()
{
    Bureaucrat test("Louis", 1);

	std::cout << test << std::endl;

	Bureaucrat test2("Laurent", 200);
	
	std::cout << test2 << std::endl;

	test2.downGrade();

	test2 = test;

	std::cout << test2 << std::endl;

	test2.downGrade();

	Bureaucrat test3(test2);

	std::cout << test3 << std::endl;

	std::cout << "###########################################" << std::endl;

	test3.upGrade();

	std::cout << test3 << std::endl;

	test3.downGrade();

	std::cout << test3 << std::endl;

	test3.upGrade();

	std::cout << test3 << std::endl;

	test3.upGrade();

	std::cout << test3 << std::endl;

	return (0);
}
