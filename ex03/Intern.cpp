#include "Intern.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
  *this = src;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &src)
{
  (void)src;
  return (*this);
}

AForm *Intern::makeShrubberyCreationForm(std::string target)
{
  return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string target)
{
  return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string target)
{
  return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
  // Array of form names and corresponding member function pointers
  std::string formNames[] = {
      "shrubbery creation",
      "robotomy request",
      "presidential pardon"};

  AForm *(Intern::*funcPtrs[])(std::string) = {
      &Intern::makeShrubberyCreationForm,
      &Intern::makeRobotomyRequestForm,
      &Intern::makePresidentialPardonForm};

  for (int i = 0; i < 3; i++)
  {
    if (formName == formNames[i])
    {
      std::cout << "Intern creates " << formName << std::endl;
      return (this->*funcPtrs[i])(target);
    }
  }

  std::cout << "Intern could not create form: " << formName << " does not exist." << std::endl;
  return (NULL);
}
