#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
private:
  std::string _target;

  // Disable default constructor
  PresidentialPardonForm();

public:
  // Constructor with target parameter
  PresidentialPardonForm(const std::string &target);

  // Copy constructor and assignment operator
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

  // Destructor
  virtual ~PresidentialPardonForm();

  // Override execute function
  virtual void execute(Bureaucrat const &executor) const;

private:
  // Specific action performed by this form
  void _action() const;
};

#endif
