#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>


RobotomyRequestForm::RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm created" <<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm destroyed" <<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "Robotomyyyyy" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj), _target(obj._target)
{
    std::cout << "copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
   if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (getSigned() == false)
        std::cout << getName() + "not signed, cannot robotomyze" << std::endl;
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException(executor.getName() + "grade too low, Cannot execute");
    int num = std::rand() % 2;
    if (num == 1)
    {
        //system("afplay ../files/507958__mrthenoronha__saw-8-bit.wav");
        std::cout << "Driiiiiil " + getName() + "have been robotomized" << std::endl;
    }   
    else
        std::cout << "Robotomy faiiiiiiiiiiiiiiled!!!" << std::endl;
};

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm &obj)
{
    os << "RobotomyRequestForm " << obj.getName() << " is signed: " << obj.getSigned() << ", and requires grade " << obj.getGradeToSign() << " to sign, and " << obj.getGradeToExecute() << " to execute.";
    return os;
}