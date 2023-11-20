/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:12:26 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/20 14:58:42 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private :

    std::string   _name;
    bool          _signed;
    int    _signGrade;
    int    _execGrade;
    Form();

    public :
    
    Form(std::string const name, int const signGrade, int const execGrade);
    Form(Form const &obj);
    Form &operator=(Form const &boj);
    ~Form();

    std::string getName();
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