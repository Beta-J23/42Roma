/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:04:12 by alpelliz          #+#    #+#             */
/*   Updated: 2024/07/26 11:08:44 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat signer("Ugo the signer", 150);
        Bureaucrat executor("Gianni l'esecutore", 1);

        ShrubberyCreationForm shrubberyForm("home");
        RobotomyRequestForm robotomyForm("target");
        PresidentialPardonForm presidentialForm("pres");

        // Test signing forms
        signer.signForm(shrubberyForm);
        signer.signForm(robotomyForm);
        signer.signForm(presidentialForm);

        // Test executing forms
        executor.executeForm(shrubberyForm);
        executor.executeForm(robotomyForm);
        executor.executeForm(presidentialForm);
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

    return 0;
}


// int main()
// {
//    	try {
// 		Bureaucrat signer("Gino", 5);
// 		ShrubberyCreationForm shru("tree");
// 		RobotomyRequestForm robo("Brain");
// 		PresidentialPardonForm zap("Tizio");
// 		signer.signForm(tree);
// 		signer.signForm(robo);
// 		signer.signForm(zap);
// 		signer.executeForm(tree);
// 		signer.executeForm(robo);
// 		signer.executeForm(zap);
// 		signer.signForm(tree);
// 		Bureaucrat executor("Gigi", 150);
// 		robo.execute(executor);
// 	}
// 	catch (AForm::GradeTooHighException &e) {
// 		std::cout << e.what() << std::endl;
// 	}
// 	catch (AForm::GradeTooLowException &e) {
// 		std::cout << e.what() << std::endl;
// 	}
// }