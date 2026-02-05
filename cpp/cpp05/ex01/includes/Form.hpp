/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:22:42 by alpelliz          #+#    #+#             */
/*   Updated: 2024/07/24 17:15:51 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
#define Form_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form{
    private:
        std::string const _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;
        
    public:
        Form();
        Form(std::string const name, const int gradeToSign, const int gradeToExecute);
        ~Form();
        Form(Form &formObj); //Copy constructor
        Form &operator=(const Form &other);
        
        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        
        void beSigned(const Bureaucrat &b);
       
        
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

std::ostream &operator <<(std::ostream &os, Form &obj);

#endif