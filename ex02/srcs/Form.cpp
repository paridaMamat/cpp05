/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:02:53 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/20 15:51:39 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() : _name("unamed"), _signGrade(160), _execGrade(160)
{
    _signed = false;
    std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(std::string const name,  int const signGrade,  const int execGrade) : _name(name), _signGrade(testGrade(signGrade)), _execGrade(testGrade(execGrade))
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
		return (0);
	}
	catch (GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}
	return (grade);
}

// void    Form::formChecker(Bureaucrat &bureaucrat)
// {
//     if (_signed == true)
//         throw (SignStatusException());
//     if (_signGrade == 0 || _execGrade == 0)
//         throw (GradeUnvailableException());
//     if (bureaucrat.getGrade() > _signGrade)
//         throw (Bureaucrat::GradeTooLowException());
// }
void    Form::beSigned(Bureaucrat &bureaucrat) const
{
    if (this->_signGrade >= bureaucrat.getGrade())
	{
		 _signed = true;
	}
    throw Bureaucrat::GradeTooLowException();
	
}

// void    Form::execChecker(const Bureaucrat &bureaucrat) const
// {
//     if (_signed == true)
//         throw (SignStatusException());
//     if (_signGrade == 0 || _execGrade == 0)
//         throw (GradeUnvailableException());
//     if (bureaucrat.getGrade() > _execGrade)
//         throw (Bureaucrat::GradeTooLowException());
// }

// void    Form::beExec(Bureaucrat &bureaucrat)
// {
//     try
//     {
//         execChecker(bureaucrat);
//     }
//     catch(Bureaucrat::GradeTooLowException &e)
//     {
//         std::cerr << bureaucrat.getName() << "couldn't execute " << getName() << " because ";
//         std::cerr << e.what() << '\n';
//         return ;
//     }
//     catch(GradeUnvailableException &e)
//     {
//         std::cerr << bureaucrat.getName() << "couldn't execute " << getName() << " because ";
//         std::cerr << e.what() << '\n';
//         return ;
//     }
//     catch(NoSignStatusException &e)
//     {
//         std::cerr << bureaucrat.getName() << "couldn't execute " << getName() << " because ";
//         std::cerr << e.what() << '\n';
//         return ;
//     }
// }

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is not correct ! He is too high !");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is not correct ! He is too low !"); 
}

// const char *Form::GradeUnvailableException::what() const throw()
// {
// 	return ("Form grade is unvailable and he can't be used or signed!"); 
// }

// const char *Form::SignStatusException::what() const throw()
// {
// 	return ("Form is already Sign ! Don't need another Sign !"); 
// }

// const char *Form::NoSignStatusException::what() const throw()
// {
// 	return ("Form is not sign ! Can't use Form if he's not Sign !"); 
// }

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
