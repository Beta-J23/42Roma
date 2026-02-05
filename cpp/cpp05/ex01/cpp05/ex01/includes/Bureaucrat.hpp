/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:03:24 by alpelliz          #+#    #+#             */
/*   Updated: 2024/07/24 17:23:31 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat {
	private:
		const std::string   _name;
        int          		_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade );
        ~Bureaucrat();
		Bureaucrat (Bureaucrat &bureObj);			// Copy costructor
		Bureaucrat &operator=(const Bureaucrat &other); //operator overload
		
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form &f);

	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Grade is too high!";
			}
	};
	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Grade is too low!";
			}
	};

};

std::ostream &operator <<(std::ostream &os, const Bureaucrat &obj);

#endif