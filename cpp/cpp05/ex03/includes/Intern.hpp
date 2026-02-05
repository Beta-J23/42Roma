#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern{
    public:
    Intern();
    ~Intern();
    AForm* makeForm(std::string form_name, std::string target);
    Intern &operator=(const Intern &other);
};

#endif