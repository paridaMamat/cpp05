/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:59:11 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/23 15:21:00 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target,  25, 5){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj): AForm(obj){
    *this = obj; 
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
    setSigned(obj.getSigned());
    setName(obj.getName());
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void    PresidentialPardonForm::execute(const Bureaucrat &b) const{
    checkExec(b);
    std::cout << ANSI_COLOR_ORANGE << getName() << " has been pardoned by Zaphod Beeblebrox" << ANSI_COLOR_RESET << std::endl;
}