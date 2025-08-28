#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
private:
  std::string _target;

  RobotomyRequestForm(); // prevent default construction

public:
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &other);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
  virtual ~RobotomyRequestForm();

  virtual void execute(Bureaucrat const &executor) const;

private:
  void _action() const; // Perform robotomy (randomized)
};

#endif
