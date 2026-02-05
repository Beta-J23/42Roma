#include "../includes/ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm created" <<std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm destroyed" <<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "Shruuuuuuuuuuubbery" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj), _target(obj._target)
{
    std::cout << "copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        _target = other._target;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::ofstream file;
    std::string fname = _target + "shruberry";
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException(executor.getName() + " grade is too low.");
    file.open(fname.c_str());
    if (file.is_open())
    {
        file <<               "           .o00o\n";
        file <<               "         o000000oo\n";
        file <<               "         00000000000o\n";
        file <<               "         00000000000000\n";
        file <<               "     oooooo  00000000  o88o\n";
        file <<               " ooOOOOOOOoo  ```|' |'  888888\n";
        file <<               " OOOOOOOOOOOO.qQQQQq. `8888'\n";
        file <<               " oOOOOOOOOOO.QQQQQQQQQQ/.88'\n";
        file <<               " OOOOOOOOOO.QQQQQQQQQQ/ /q\n";
        file <<               " OOOOOOOOO QQQQQQQQQQ/ /QQ\n";
        file <<               " OOOOOOOOO QQQQQQ/ /QQ'\n";
        file <<               "     OO:F_P:O QQQ/  /Q'\n";
        file <<               "         ||. || |  // |\n";
        file <<               "         d|| |||||_////\n";
        file <<               "         qP| || _' `|Ob\n";
        file <<               "         ||  / ||  ||Op\n";
        file <<               "         |  | O| |\n";
        file <<               " _       /||. ||_/ /|\n";
        file <<               "     `---__/|_||   |  __\n"; 
        file <<               "         `-'  `-'`-'-'" << std::endl;
        if (!file.good())
            std::cerr << "Error writing file" << std::endl;
        else 
            std::cout << "Palm have been planted" << std::endl;
        file.close();
    }
    else
        std::cerr << "file not opened" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &obj)
{
    os << "ShrubberyCreationForm " << obj.getName() << " is signed: " << obj.getSigned() << ", and requires grade " << obj.getGradeToSign() << " to sign, and " << obj.getGradeToExecute() << " to execute.";
    return os;
}




