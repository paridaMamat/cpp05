/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:12:26 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/21 09:51:55 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define ANSI_COLOR_GREEN "\033[1;32m"
#define ANSI_COLOR_ORANGE "\033[1;33m"
#define ANSI_COLOR_RESET "\033[0m"

class Bureaucrat;

class AForm
{
    private :

    const std::string   _name;
    bool          _signed;
    const int    _signGrade;
    const int    _execGrade;
    AForm();

    public :
    
    AForm(std::string const name, int const signGrade, int const execGrade);
    AForm(AForm const &obj);
    AForm &operator=(AForm const &boj);
    virtual ~AForm();

    std::string getName() const;
    int     getSignGrade() const;
    int     getExecGrade() const;
    bool    getSigned() const;
    void    beSigned(Bureaucrat &bureaucrat);
    int     testGrade(unsigned int grade) const;
   
   virtual void execute(const Bureaucrat &b) const = 0;
   void checkExec(const Bureaucrat &b) const;
   void setName(std::string name);
   void setSigned(bool b);
    
    class ThisIsNotSignedException : public std::exception
    {
        public :
       virtual const char *what() const throw();
    };

    class GradeTooHighException : public std::exception
    {
        public :
        const char *what() const throw();
    };

     class GradeTooLowException : public std::exception
    {
        public :
        const char *what() const throw();
    };

    class SignStatusException : public std::exception
	{
		public:
			const char *what() const throw();
	};

};

std::ostream &operator<<(std::ostream &out, AForm  &rhs);
#endif