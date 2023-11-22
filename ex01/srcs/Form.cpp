/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:02:53 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/22 15:24:42 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() : _name("unamed"), _signGrade(160), _execGrade(160)
{
    _signed = false;
    std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(std::string const name,  int const signGrade,  const int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
    _signed = false;
    std::cout << "Form overload Constructor called" << std::endl;
}

Form::Form(Form const &obj)
{
    std::cout << "Form copy Constructor called" << std::endl;
    *this = obj;
}
Form &Form::operator=(const Form &obj)
{
    std::cout << "Form copy assignment operator called" << std::endl;
    _name = obj._name;
    _signGrade = obj._signGrade;
    _execGrade = obj._execGrade;
    _signed = false;
    return *this;
}

Form::~Form()
{
    std::cout << "Form Destructor called" << std::endl;
}

std::string Form::getName()
{
    return (_name);
}
int Form::getSignGrade() const
{
	return (_signGrade);
}

int Form::getExecGrade() const
{
	return (_execGrade);
}

bool Form::getSigned() const
{
	return (_signed);
}

int	Form::testGrade(unsigned int grade) const
{

	try
	{
		if (grade < 1)
		{
			throw (GradeTooHighException());
		}
		if (grade > 150)
		{
			throw (GradeTooLowException());
		}
	}
	catch (GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}
	catch (GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}
	return (grade);
}

void    Form::beSigned(Bureaucrat &bureaucrat)
{
    if (this->_signGrade >= bureaucrat.getGrade())
	{
		 _signed = true;
	}
    throw Bureaucrat::GradeTooLowException();
	
}


const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is not correct ! He is too high !");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is not correct ! He is too low !"); 
}

std::ostream &operator<<(std::ostream &out, Form &f)
{
	out << "Form name " << f.getName() << " can be sign with grade " << f.getSignGrade();
	out << ", execute with grade " << f.getExecGrade() << " and sign status is ";
	if (f.getSigned() == false)
		out << "unsigned!";
	else
		out << "signed!";
	return out;
}
