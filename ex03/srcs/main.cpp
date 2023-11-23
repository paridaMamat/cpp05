/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:48:37 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/23 16:49:31 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"


int    main(void)
{
    try
    {
        Intern  someRandomIntern;
        AForm*   rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        delete rrf;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    std::cout << "###########################################" << std::endl;
    try 
    {
        Intern  hferjani;
        AForm*  FCR;
        
        FCR = hferjani.makeForm("shrubbery creation", "home");
        std::cout << *FCR << std::endl;
        delete FCR;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    std::cout << "###########################################" << std::endl;
    try
    {
        Intern bestIntern;
        AForm*  UB40;
        
        UB40 = bestIntern.makeForm("presidential pardon", "white house");
        std::cout << *UB40 << std::endl;
        delete UB40;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    std::cout << "###########################################" << std::endl;
    try
    {
        Intern badIntern;
        AForm*  badForm;

        badForm = badIntern.makeForm("bad form", "bad target");
        std::cout << "we display something here but he can't , because it already catch something";
        std::cout << *badForm << std::endl;
        delete badForm;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}
