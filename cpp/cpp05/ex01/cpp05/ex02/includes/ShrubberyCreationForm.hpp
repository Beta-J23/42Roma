#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include  "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &obj);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm &other);

        void execute(ShrubberyCreationForm const & executor) const;
}

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm &obj);

#endif