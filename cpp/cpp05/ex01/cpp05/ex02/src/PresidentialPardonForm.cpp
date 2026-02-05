#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){
    std::cout << "PresidentialPardonForm created" <<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 145, 137), _target(target)
{
    std::cout << "Presidentiaaal" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj), _target(obj._target)
{
    std::cout << "copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
        this->_signed = other._signed;
    return *this;
}

std::ostream &operator <<(std::ostream &os, PresidentialPardonForm &obj)
{
    os << "PresidentialPardonForm " << obj.getName() << " is signed: " << obj.getSigned() << ", and requires grade " << obj.getGradeToSign() << " to sign, and " << obj.getGradeToExecute() << " to execute.";
    return os;
}