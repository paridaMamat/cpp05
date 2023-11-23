/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:12:26 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/23 17:36:08 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define ANSI_COLOR_GREEN "\033[1;32m"
#define ANSI_COLOR_ORANGE "\033[1;33m"
#define ANSI_COLOR_RESET "\033[0m"

class Bureaucrat;

class Form
{
    private :

    const std::string   _name;
    bool          _signed;
    const int    _signGrade;
    const int    _execGrade;
    Form();

    public :
    
    Form(std::string const name, int const signGrade, int const execGrade);
    Form(Form const &obj);
    Form &operator=(Form const &boj);
    ~Form();

    std::string getName() const;
    int     getSignGrade() const;
    int     getExecGrade() const;
    bool    getSigned() const;

    void    beSigned(Bureaucrat &bureaucrat);
    
    int     testGrade(unsigned int grade) const;
    
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
};

std::ostream &operator<<(std::ostream &out, Form  &rhs);
#endif