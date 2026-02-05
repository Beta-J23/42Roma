/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:22:42 by alpelliz          #+#    #+#             */
/*   Updated: 2024/07/26 10:03:37 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
        std::string const _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;
        
    public:
        AForm();
        AForm(std::string const name, const int gradeToSign, const int gradeToExecute);
        virtual ~AForm();
        AForm(const AForm &formObj); //Copy constructor
        AForm &operator=(const AForm &other);
        
        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat &b);
        
         virtual void execute(Bureaucrat const & executor) const = 0;
        
        class GradeTooHighException: public std::exception
        {
            private:
                std::string _message;
            public:
            	GradeTooHighException(const std::string &msg) : _message(msg) {}
				~GradeTooHighException() throw() {}
				virtual const char* what() const throw() {
					return (_message.c_str());
				}
        };
        class GradeTooLowException: public std::exception
        {
            private:
                std::string _message;
            public:
                GradeTooLowException();
            	GradeTooLowException(const std::string &msg) : _message(msg) {}
				~GradeTooLowException() throw() {}
				virtual const char* what() const throw() {
					return (_message.c_str());
				}
        };    
};

std::ostream &operator <<(std::ostream &os, AForm &obj);

#endif