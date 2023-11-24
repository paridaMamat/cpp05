/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:48:37 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/24 11:40:57 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"


int main()
{
	Bureaucrat a("a", 150);
	Bureaucrat b("b", 1);
	Form c("c", 50, 50);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << std::endl;

	a.signForm(c);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << std::endl;

	b.signForm(c);
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << std::endl;	
	
	std::cout << "###########################################" << std::endl;
	std::cout << "###########################################" << std::endl;
	
	Bureaucrat test("Louis", -1); // HIGH LEVEL

	std::cout << test << std::endl;

	Bureaucrat test2("Laurent", 200); // LOW LEVEL
	
	std::cout << test2 << std::endl;

	test2.upGrade();

	std::cout << test2 << std::endl;

	test2.upGrade();

	Bureaucrat test3(test); // HIGH LEVEL

	std::cout << test3 << std::endl;

	std::cout << "###########################################" << std::endl;
	
	test3.downGrade();

	std::cout << test3 << std::endl;

	test3.upGrade();

	std::cout << test3 << std::endl;

	test3.downGrade();

	std::cout << test3 << std::endl;

	test3.downGrade();

	std::cout << test3 << std::endl;

	std::cout << "###########################################" << std::endl;
	
	Form form1("High Form", 1, 1);
	std::cout << form1 << std::endl;

	Form form2("Low Form", 150, 150);
	std::cout << form2 << std::endl;

	Form form3("Unvailable Form", 160, 0);
	std::cout << form3 << std::endl;

	std::cout << test2 <<std::endl;
	std::cout << test3 <<std::endl;
	std::cout << "###########################################" << std::endl;
	
	test2.signForm(form1); 
	std::cout << form1 << std::endl;

	std::cout << "###########################################" << std::endl;

	test3.signForm(form2); 
	std::cout << form2 << std::endl;

	std::cout << "###########################################" << std::endl;

	test2.signForm(form3);
	std::cout << form3 << std::endl;
	
	std::cout << "###########################################" << std::endl;

	test2.signForm(form2); // HIGH AND LOW , BUT SIGNED KO
	std::cout << form2 << std::endl;

	return (0);
}
