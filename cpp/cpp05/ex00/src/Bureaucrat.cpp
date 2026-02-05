/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:03:41 by alpelliz          #+#    #+#             */
/*   Updated: 2024/07/26 13:25:07 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("Gino"), _grade(150)
{
    std::cout << "Bureaucrat default " << getName() <<  "created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << getName() << " Bureaucrat destroyed" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat " << _name <<  " created" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
    std::cout << getName() << " new grade is " << getGrade() << std::endl;
}

void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
    std::cout << getName() << " new grade is " << getGrade() << std::endl;
}



Bureaucrat::Bureaucrat(Bureaucrat &bureObj):_name(bureObj._name), _grade(bureObj._grade)
{
    std::cout << "Cloned Bureaucrat " << getName() <<  "created" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this == &other)
        return *this;
    _grade = other._grade;
    return *this;
}
std::ostream &operator <<(std::ostream &os, const Bureaucrat &obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}