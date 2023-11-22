/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:09:05 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/22 15:12:33 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern &obj)
{
    *this = obj;
}

Intern &Intern::operator=(const Intern &obj)
{
    (void)obj;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern Destructor Called" << std::endl;
}

AForm *Intern::makeForm(std::string const form, std::string const target)
{
    enum formID {PRESIDENTIAL, ROBOTOMY, SHRUBBERY};
    const std::string   name[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    int n = 0;
    for (; n < 4; n++)
    {
        if(n != 3 && name[n] == form)
            break;
    }
    switch(n)
    {
        // std::cout << "Intern creates " << name[n] << " form." << std::endl;
        case PRESIDENTIAL:
            std::cout << "Intern creates " << name[n] << " form." << std::endl;
            return (new ShrubberyCreationForm(target));
        case ROBOTOMY :
            std::cout << "Intern creates " << name[n] << " form." << std::endl;
            return (new RobotomyRequestForm(target));
        case SHRUBBERY :
            std::cout << "Intern creates " << name[n] << " form." << std::endl;
            return (new ShrubberyCreationForm(target));
        default :
            throw NoExistingForm ();
    }
}