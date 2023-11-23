/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:59:15 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/23 15:22:27 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target,  72, 45){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj): AForm(obj){
    *this = obj; 
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    setSigned(obj.getSigned());
    setName(obj.getName());
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void    RobotomyRequestForm::execute(const Bureaucrat &b) const
{
    checkExec(b);
    int tmp = (rand() % 2);
    
    std::cout << ANSI_COLOR_ORANGE;
    std::cout << "drrrrrrrrrrrr...! drrrrrrrrrrrr...! drrrrrrrrrrrr...! drrrrrrrrrrrr...! "<< std::endl;
	std::cout << "drrrrrrrrrrrr...!  drrrrrrrrrrrr...! drrrrrrrrrrrr...! drrrrrrrrrrrr...!" << std::endl;
	std::cout << "drrrrrrrrrrrr...! drrrrrrrrrrrr...! drrrrrrrrrrrr...!  drrrrrrrrrrrr...! "<< std::endl;
    std::cout << this->getName() << " has been robotomised...";
    std::cout << (tmp ? "" : ", the robotomy failed!") << std::endl;
    std::cout << ANSI_COLOR_RESET;
}