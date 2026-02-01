#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
private:
  std::string _target;

  // Disable default constructor
  ShrubberyCreationForm();

public:
  // Constructor with target parameter
  ShrubberyCreationForm(const std::string &target);

  // Copy constructor and assignment operator
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

  // Destructor
  virtual ~ShrubberyCreationForm();

  // Override execute function
  virtual void execute(Bureaucrat const &executor) const;

private:
  // Private helper function to perform the actual action
  void _action() const;
};

#endif
