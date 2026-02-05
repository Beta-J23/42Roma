/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:04:12 by alpelliz          #+#    #+#             */
/*   Updated: 2024/07/24 18:29:52 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"

int main()
{
    try { 
        Bureaucrat impiegato("Ugo", 50);
        Form irpf;
        Form formulario("ISEE", 50, 70);
        std::cout << formulario << std::endl;
        std::cout << irpf << std::endl;
        impiegato.signForm(formulario);
        // bureaucrat->incrementGrade();
        formulario.beSigned(impiegato);
    }
    catch (Form::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat impiegato2("Gino", 25);
        Form formulario2("TAEG", 35, 70);
        std::cout << formulario2 << std::endl;
        impiegato2.signForm(formulario2);
    }
    catch (Form::GradeTooHighException &t)
    {    
        std::cout << t.what() << std::endl;
    }
    catch (Form::GradeTooLowException &t)
    {    
        std::cout << t.what() << std::endl;
    }  
    
    return (0);
}