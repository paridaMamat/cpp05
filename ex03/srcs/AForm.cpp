/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:02:53 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/21 09:40:28 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm() : _name("unamed"), _signGrade(160), _execGrade(160)
{
    _signed = false;
    std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::AForm(std::string const name,  int const signGrade,  const int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
    _signed = false;
    std::cout << "AForm overload Constructor called" << std::endl;
}

AForm::AForm(AForm const &obj)
{
    std::cout << "AForm copy Constructor called" << std::endl;
    *this = obj;
}
AForm &AForm::operator=(const AForm &obj)
{
    std::cout << "AForm copy assignment operator called" << std::endl;
    _name = obj._name;
    _signGrade = obj._signGrade;
    _execGrade = obj._execGrade;
    _signed = false;
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm Destructor called" << std::endl;
}

std::string AForm::getName() const
{
    return (_name);
}
int AForm::getSignGrade() const
{
	return (_signGrade);
}

int AForm::getExecGrade() const
{
	return (_execGrade);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int	AForm::testGrade(unsigned int grade) const
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


void    AForm::beSigned(Bureaucrat &bureaucrat) 
{
    if (this->_signGrade>= bureaucrat.getGrade())
	{
		 _signed = true;
	}
    throw Bureaucrat::GradeTooLowException();
	
}

/* void    AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= getSignGrade())
        setSigned(1);
    else
    {
        throw AForm::GradeTooLowException();
    }
} */

void AForm::checkExec(const Bureaucrat &b) const
{
	(_signed == false) ? throw ThisIsNotSignedException() : (void)0;
    (_execGrade < b.getGrade()) ? throw GradeTooLowException() : (void)0;
}

void 	AForm::setName(std::string name)
{
	_name = name;
}

void	AForm::setSigned(bool b)
{
	_signed = b;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade is not correct ! He is too high !");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade is not correct ! He is too low !"); 
}
const char *AForm::ThisIsNotSignedException::what() const throw(){
	return ("this is not signed, so we can't do this anymore....");
}

std::ostream &operator<<(std::ostream &out, AForm &f)
{
	out << "AForm name " << f.getName() << " can be sign with grade " << f.getSignGrade();
	out << ", execute with grade " << f.getExecGrade() << " and sign status is ";
	if (f.getSigned() == false)
		out << "unsigned!";
	else
		out << "signed!";
	return out;
}
