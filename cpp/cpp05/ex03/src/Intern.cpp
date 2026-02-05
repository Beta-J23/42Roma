#include "../includes/Intern.hpp"

Intern::Intern(){
}

Intern::~Intern(){
    std::cout << "Intern Destroyed" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
    if (this==&other)
        return *this;
    return *this;
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
    AForm *NewForm = NULL;
    std::string possible_names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    int i = 0;
    while (form_name != possible_names[i])
        i++;
    switch(i)
    {
        case 0:
            NewForm = new ShrubberyCreationForm(target);
            std::cout << "Intern created " + form_name << std::endl;
            break;
        case 1:
            NewForm = new RobotomyRequestForm(target);
            std::cout << "Intern created " + form_name << std::endl;
            break;
        case 2:
            NewForm = new PresidentialPardonForm(target);
            std::cout << "Intern created " + form_name << std::endl;
            break;
        default:
            std::cout << "Intern did not create any form" << std::endl;
            break;
    }
    return(NewForm);
}