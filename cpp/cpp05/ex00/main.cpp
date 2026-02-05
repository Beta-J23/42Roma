/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:04:12 by alpelliz          #+#    #+#             */
/*   Updated: 2024/07/26 13:46:48 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"

int main()
{
    // Bureaucrat buro("Ale", 149);

    // std::cout << buro.getName() << " has a grade of " << buro.getGrade() << std::endl;
    // while (buro.getGrade() > 1)
    // {
    //     buro.incrementGrade();
    //     std::cout << buro.getName() << " has a grade of " << buro.getGrade() << std::endl;
    // }
    // std::string new_name;
    // int new_grade;
    // std::cout << "Enter a new name: ";
    // std::cin >> new_name;
    // while (new_grade < 1 || new_grade > 150)
    // {
    //     std::cout << "Enter a new grade: ";
    //     std::cin >> new_grade;
    //     std::cin.clear();
    //     std::cin.ignore();
    // }
    // Bureaucrat buro2(new_name, new_grade);
    // std::cout << buro2.getName() << " has a grade of " << buro2.getGrade() << std::endl;

    try{
        Bureaucrat buro3("Ugo", 149);
        std::cout << buro3 << std::endl;
        buro3.decrementGrade();
        std::cout << buro3 << std::endl;
        buro3.decrementGrade();
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    
    try {
        Bureaucrat buro4("Gianni", 2);
        std::cout << buro4 << std::endl;
        buro4.incrementGrade();
        std::cout << buro4 << std::endl;
        buro4.incrementGrade();
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << std::endl;

    try {
        Bureaucrat buro5("Pino", 0);
        std::cout << buro5 << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat buro6("Annibaldo", 151);
        std::cout << buro6 << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}