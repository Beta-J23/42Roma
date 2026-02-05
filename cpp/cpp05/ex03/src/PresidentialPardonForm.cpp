#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){
    std::cout << "PresidentialPardonForm created" <<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "PresidentialPardonForm destroyed" <<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
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
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (getSigned() == false)
        std::cout << getName() + " not signed, cannot pardon" << std::endl;
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException(executor.getName() + "grade too low, Cannot execute");
    if (getSigned() == true && executor.getGrade() > getGradeToExecute())
        std::cout << _target + " has been pardoned by Zaphod Beeblebrox" << std::endl;
    else
        std::cout << " could not pardon this!" << std::endl;
}


std::ostream &operator <<(std::ostream &os, PresidentialPardonForm &obj)
{
    os << "PresidentialPardonForm " << obj.getName() << " is signed: " << obj.getSigned() << ", and requires grade " << obj.getGradeToSign() << " to sign, and " << obj.getGradeToExecute() << " to execute.";
    return os;
}