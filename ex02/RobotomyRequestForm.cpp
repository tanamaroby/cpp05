#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
  std::srand(std::time(NULL)); // Seed for randomization
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target)
{
}

// Assignment operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
  if (this != &other)
  {
    AForm::operator=(other);
    _target = other._target;
  }
  return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
}

// Private member function to perform the robotomy action
void RobotomyRequestForm::_action() const
{
  std::cout << "Bzzz... bzzz... Drilling noises..." << std::endl;

  // Simulate 50% success rate
  if (std::rand() % 2)
    std::cout << _target << " has been robotomized successfully." << std::endl;
  else
    std::cout << "Robotomy failed on " << _target << "." << std::endl;
}

// Override execute
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
  if (!isSigned())
    throw AForm::FormNotSignedException();
  if (executor.getGrade() > getGradeToExec())
    throw AForm::GradeTooLowException();

  _action();
}
