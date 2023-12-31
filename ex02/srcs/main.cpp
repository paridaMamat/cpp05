/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:48:37 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/24 12:21:16 by pmaimait         ###   ########.fr       */
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
	
	Bureaucrat f("f", 5);
	f.signForm(c);
	std::cout << std::endl;
	
	a.executeForm(c);
	std::cout << std::endl;
	b.executeForm(c);
	std::cout << std::endl;
	a.executeForm(d);
	std::cout << std::endl;
	b.executeForm(d);
	std::cout << std::endl;
	a.executeForm(e);
	std::cout << std::endl;
	b.executeForm(e);
	
	std::cout << "###########################################" << std::endl;
	ShrubberyCreationForm g("g");
	f.executeForm(g);
	return (0);
}
