/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:22:37 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/24 09:56:48 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>

class Bureaucrat 
{
    private :
    const std::string _name;
    int _grade;
    Bureaucrat();

    public:
    Bureaucrat(std::string const name, int grade);
    Bureaucrat(Bureaucrat const &obj);
    ~Bureaucrat();
    Bureaucrat &operator=(Bureaucrat const &obj);

    std::string getName(void) const;
    int getGrade(void) const;
    int checkGrade(int grade) const;
    void    upGrade();
    void    downGrade();

    class GradeTooHightException : public std::exception
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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif