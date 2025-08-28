#include "PresidentialPardonForm.hpp"
#include <iostream>

// Constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), _target(other._target)
{
}

// Assignment operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
  if (this != &other)
  {
    AForm::operator=(other);
    _target = other._target;
  }
  return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
}

// The specific pardon action
void PresidentialPardonForm::_action() const
{
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// Execute method enforcement
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
  if (!isSigned())
    throw AForm::FormNotSignedException();
  if (executor.getGrade() > getGradeToExec())
    throw AForm::GradeTooLowException();
  _action();
}
