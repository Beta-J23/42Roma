/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:04:12 by alpelliz          #+#    #+#             */
/*   Updated: 2024/07/26 13:18:44 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/Intern.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat signer("Ugo the signer", 45);
        Bureaucrat executor("Gianni l'esecutore", 50);
        Intern Pino;

        // Test creating forms using the Intern
        AForm* shrubberyForm = Pino.makeForm("shrubbery creation", "home");
        AForm* robotomyForm = Pino.makeForm("robotomy request", "target");
        AForm* presidentialForm = Pino.makeForm("presidential pardon", "pres");

        // Test signing forms
        signer.signForm(*shrubberyForm);
        signer.signForm(*robotomyForm);
        signer.signForm(*presidentialForm);

        // Test executing forms
        executor.executeForm(*shrubberyForm);
        executor.executeForm(*robotomyForm);
        executor.executeForm(*presidentialForm);

        // Don't forget to delete the forms when you're done
        delete shrubberyForm;
        delete robotomyForm;
        delete presidentialForm;
    }
    catch (AForm::GradeTooHighException &e) {
        std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
    }
    catch (AForm::GradeTooLowException &e) {
        std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
    }
    return(0);
}