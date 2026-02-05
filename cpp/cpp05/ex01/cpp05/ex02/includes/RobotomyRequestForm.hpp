#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include  "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &obj);
        RobotomyRequestForm &operator=(RobotomyRequestForm &other);

        void execute(RobotomyRequestForm const & executor) const;
}

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm &obj);

#endif