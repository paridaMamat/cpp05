/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:02:53 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/23 17:42:29 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() : _name("unamed"), _signGrade(150), _execGrade(150)
{
    _signed = false;
    std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(std::string const name,  int const signGrade,  const int execGrade) : _name(name), _signGrade(testGrade(signGrade)), _execGrade(testGrade(execGrade))
{
    _signed = false;
    std::cout << "Form overload Constructor called" << std::endl;
}

Form::Form(Form const &obj) : _name(obj._name), _signGrade(obj._signGrade), _execGrade(obj._execGrade)
{
    std::cout << "Form copy Constructor called" << std::endl;
    *this = obj;
}
Form &Form::operator=(const Form &obj) 
{
    std::cout << "Form copy assignment operator called" << std::endl;
    _signed = obj._signed;
    return *this;
}

Form::~Form()
{
    std::cout << "Form Destructor called" << std::endl;
}

std::string Form::getName() const
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
		return (1);
	}
	catch (GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
		return (150);
	}
	return (grade);
}

void    Form::beSigned(Bureaucrat &bureaucrat) 
{
    if (this->_signGrade <= bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	 _signed = true;
}


const char *Form::GradeTooHighException::what() const throw()
{
	return ("grade is not correct ! He is too high !");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("grade is not correct ! He is too low !"); 
}

std::ostream &operator<<(std::ostream &out, Form &f)
{
    out << ANSI_COLOR_GREEN << "Form " << f.getName() << " signGrade is " << f.getSignGrade();
    out << ", executeGrade is " << f.getExecGrade() << " and sign status is ";

    if (f.getSigned() == false)
        out << "unsigned!";
    else
        out << "signed!";

    out << ANSI_COLOR_RESET; // Reset color after printing

    return out;
}
