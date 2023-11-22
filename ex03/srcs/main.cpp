/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:48:37 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/22 14:15:54 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/Bureaucrat.hpp"
// #include "../includes/ShrubberyCreationForm.hpp"
// #include "../includes/RobotomyRequestForm.hpp"
// #include "../includes/PresidentialPardonForm.hpp"
// #include "../includes/AForm.hpp"
#include "../includes/Intern.hpp"


int    main(void)
{
    try
    {    
        Intern         someRandomIntern;
        Bureaucrat    bob("Bobo", 44);        
        AForm         *form = NULL;
        
        form = someRandomIntern.makeForm("Robotomy Request", "Bender1");
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    try
    {
        Intern         someRandomIntern;
        Bureaucrat    bob("Bibi", 72);
        AForm         *form;
        
        form = someRandomIntern.makeForm("Shrubbery Creation", "Bender2");
        bob.signForm(*form);    
        bob.executeForm(*form);
        delete form;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    try
    {
        Intern         someRandomIntern;
        Bureaucrat    bob("Bubu", 1);
        AForm         *form;
        
        form = someRandomIntern.makeForm("Presidential Pardon", "Bender3");
        bob.signForm(*form);    
        bob.executeForm(*form);
        delete form;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    try
    {
        Intern         someRandomIntern;
        Bureaucrat    bob("Bebe", 144);        
        AForm         *form;
        
        form = someRandomIntern.makeForm("Presidential Pardon", "Bender4");
        bob.signForm(*form);    
        bob.executeForm(*form);
        delete form;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
