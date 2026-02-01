#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
  std::cout << "\n--- TEST: Intern Creating Forms ---" << std::endl;

  Intern someRandomIntern;
  AForm *rrf;
  AForm *scf;
  AForm *ppf;
  AForm *unknown;

  // Test 1: Robotomy Request
  rrf = someRandomIntern.makeForm("robotomy request", "Bender");

  // Test 2: Shrubbery Creation
  scf = someRandomIntern.makeForm("shrubbery creation", "Home");

  // Test 3: Presidential Pardon
  ppf = someRandomIntern.makeForm("presidential pardon", "Alice");

  // Test 4: Unknown Form
  unknown = someRandomIntern.makeForm("unknown form", "Nobody");

  std::cout << "\n--- TEST: Bureaucrat Signing and Executing ---" << std::endl;

  Bureaucrat boss("Boss", 1);

  if (rrf)
  {
    boss.signForm(*rrf);
    boss.executeForm(*rrf);
    delete rrf;
  }

  if (scf)
  {
    boss.signForm(*scf);
    boss.executeForm(*scf);
    delete scf;
  }

  if (ppf)
  {
    boss.signForm(*ppf);
    boss.executeForm(*ppf);
    delete ppf;
  }

  // unknown should be NULL, so we don't delete it
  if (unknown)
    delete unknown;

  return (0);
}
