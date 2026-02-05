/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:28:53 by alpelliz          #+#    #+#             */
/*   Updated: 2024/07/24 18:05:58 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

// Form::Form()
// {
//     std::cout << "Default Form created" << std::endl;
    
// }

Form::Form() : _name("tasse"), _gradeToSign(50), _gradeToExecute(75)
{
	_signed = false;
	std::cout << getName() << " has been created." << std::endl;
}

Form::Form(std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
//alternative constructor assegnation
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException("Highest grade to sign " + getName() + " is 1");
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException("Lowest grade to sign " + getName() + " is 150");
    if (gradeToSign > 150)
        throw GradeTooLowException("Lowest grade to sign " + getName() + " is 150");
    if (gradeToExecute > 150)
        throw GradeTooLowException("Lowest grade to execute " + getName() + " is 150");
    _signed = false;
    std::cout << "Form " << _name << " created" << std::endl;
}

Form::~Form()
{
    std::cout << "Form " << getName() << " Destroyed" << std::endl;
}

Form::Form(Form &FormObj):_name(FormObj._name), _gradeToSign(FormObj._gradeToSign), _gradeToExecute(FormObj._gradeToExecute)
{
    std::cout << "Cloned Form " << _name << " created" << std::endl;    
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->_signed = other._signed;
    return *this;
}

std::string Form::getName() const
{
    return (_name);
}

bool Form::getSigned() const
{
    return (_signed);
}

int Form::getGradeToSign() const
{
    return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException(b.getName());
    else
        _signed = true;
}
std::ostream &operator <<(std::ostream &os, Form &obj)
{
    os << "Form " << obj.getName() << " is signed: " << obj.getSigned() << ", and requires grade " << obj.getGradeToSign() << " to sign, and " << obj.getGradeToExecute() << " to execute.";
    return os;
}