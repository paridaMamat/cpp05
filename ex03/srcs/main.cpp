/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:48:37 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/22 15:13:06 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        
        form = someRandomIntern.makeForm("shrubbery creation", "Bender2");
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
        
        form = someRandomIntern.makeForm("presidential pardon", "Bender3");
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
        
        form = someRandomIntern.makeForm("presidential pardon", "Bender4");
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
