/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:48:37 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/23 16:10:25 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/AForm.hpp"


int main()
{
	Bureaucrat a("a", 150);
	Bureaucrat b("b", 1);
	ShrubberyCreationForm c("c");
	RobotomyRequestForm d("d");
	PresidentialPardonForm e("e");

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << std::endl;

	a.signForm(c);
	a.signForm(d);
	a.signForm(e);
	std::cout << std::endl;

	b.signForm(c);
	b.signForm(d);
	b.signForm(e);	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << std::endl;

	a.executeForm(c);
	b.executeForm(c);
	std::cout << std::endl;
	a.executeForm(d);
	b.executeForm(d);
	std::cout << std::endl;
	a.executeForm(e);
	b.executeForm(e);
	return (0);
}
