#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target)
{
}

// Assignment operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
  if (this != &other)
  {
    AForm::operator=(other);
    _target = other._target;
  }
  return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// Private helper function to perform the actual action
void ShrubberyCreationForm::_action() const
{
  std::ofstream ofs((_target + "_shrubbery").c_str());
  if (!ofs)
    throw std::ios_base::failure("Failed to open file");

  ofs << "       _-_\n";
  ofs << "    /~~   ~~\\\n";
  ofs << " /~~         ~~\\\n";
  ofs << "{               }\n";
  ofs << " \\  _-     -_  /\n";
  ofs << "   ~  \\\\ //  ~\n";
  ofs << "_- -   | | _- _\n";
  ofs << "  _ -  | |   -_\n";
  ofs << "      // \\\\\n";
  ofs.close();
}

// Override execute method
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
  if (!isSigned())
    throw AForm::FormNotSignedException();
  if (executor.getGrade() > getGradeToExec())
    throw AForm::GradeTooLowException();

  // Perform the form's action
  _action();
}
