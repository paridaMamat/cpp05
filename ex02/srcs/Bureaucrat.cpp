/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:15:31 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/24 12:14:59 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("unamed"), _grade(150)
{
    std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Bureaucrat overload Constructor called" << std::endl;
    _grade = checkGrade(grade);
    return;    
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj): _name(obj._name)
{
    std::cout << "Bureaucrat copy Constructor called" << std::endl;
    *this = obj;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &obj)
{
    std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
    _grade = obj._grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor called" << std::endl;
}
int Bureaucrat::checkGrade(int grade) const
{
    try
    {
        if (grade < 1)
            throw (GradeTooHightException());
        if (grade > 150)
            throw (GradeTooLowException());   
    }
    catch(const GradeTooHightException& e)
    {
        std::cerr << e.what() << '\n';
         return (1);
    }
    catch (const GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
         return 150;
    }
    return grade;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

void    Bureaucrat::upGrade()
{
    _grade = checkGrade(_grade - 1);
    return ;
}

void    Bureaucrat::downGrade()
{
    _grade = checkGrade(_grade + 1);
    return ;
}

const char *Bureaucrat::GradeTooHightException::what() const throw()
{
    return ("Bureaucrat can't be higher then 1 !");
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return ("Bureaucrat can't be lower then 150 !");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return out;
}


void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << "." <<std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << this->getName() << " couldn’t sign " << form.getName() << " because ";
		std::cerr << e.what() << std::endl;
		return ;
	}
    catch (AForm::SignStatusException &e)
	{
		std::cerr << this->getName() << " couldn’t sign " << form.getName() << " because ";
		std::cerr << e.what() << std::endl;
		return ;
	}
	return ;
}

void    Bureaucrat::executeForm(const AForm &form)
{
    try
    {
        form.execute(*this);
        std::cout << ANSI_COLOR_ORANGE << this->getName() << " executed " << form.getName() << ANSI_COLOR_RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << ANSI_COLOR_ORANGE << this->getName() << " can not excute " << form.getName() << " because " << ANSI_COLOR_RESET;
        std::cerr << e.what() << '\n';
    }
    
}