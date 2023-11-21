/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:59:15 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/21 15:13:03 by pmaimait         ###   ########.fr       */
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
    srand(time(0));
    int tmp = (rand() % 2);
    
    std::cout << "Bzrrr Bzrrrr Bzrrrrrr Bzrr Bzrrr ";
	std::cout << "Bzrrr Bzrr Bzrrr Bzrrr Bzrrrrr" << std::endl;
	std::cout << "Bzrrrr Bzrrrrr Bzrrr Bzrr Bzrrrr ";
    std::cout << this->getName() << " is became a robot";
    std::cout << (tmp ? "" : ", such a loser!") << std::endl;
}