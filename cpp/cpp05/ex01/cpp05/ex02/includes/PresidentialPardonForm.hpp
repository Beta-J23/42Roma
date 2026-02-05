#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include  "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &obj);
        PresidentialPardonForm &operator=(PresidentialPardonForm &other);

        void execute(PresidentialPardonForm const & executor) const;
}

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm &obj);

#endif