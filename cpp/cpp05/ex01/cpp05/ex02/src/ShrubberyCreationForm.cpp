#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm created" <<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "Shruuuuuuuuuuubbery" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj), _target(obj._target)
{
    std::cout << "copy constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        this->_signed = other._signed;
    return *this;
}

std::ostream &operator <<(std::ostream &os, ShrubberyCreationForm &obj)
{
    os << "ShrubberyCreationForm " << obj.getName() << " is signed: " << obj.getSigned() << ", and requires grade " << obj.getGradeToSign() << " to sign, and " << obj.getGradeToExecute() << " to execute.";
    return os;
}




