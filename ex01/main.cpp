#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

void testCreateForm(const std::string &name, int gradeSign, int gradeExec)
{
  std::cout << CYAN << "[Creating Form \"" << name
            << "\" (sign: " << gradeSign
            << ", exec: " << gradeExec << ")]" << RESET << std::endl;
  try
  {
    Form f(name, gradeSign, gradeExec);
    std::cout << GREEN << "Created: " << f << RESET << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
  }
  std::cout << std::endl;
}

int main()
{
  std::cout << CYAN << "=== Bureaucrat & Form Test v1.0 ===" << RESET << std::endl
            << std::endl;

  // Create Bureaucrats
  Bureaucrat alice("Alice", 50);
  Bureaucrat bob("Bob", 140);
  Bureaucrat charlie("Charlie", 1);

  // Create Forms with valid and invalid grades
  testCreateForm("TaxForm", 100, 50);
  testCreateForm("SecretMission", 0, 45);   // invalid, too high
  testCreateForm("PublicNotice", 151, 150); // invalid, too low

  // Prepare a valid form
  Form taxForm("TaxForm", 100, 50);

  // Show initial state
  std::cout << taxForm << std::endl
            << std::endl;

  // Bob tries to sign, should fail
  bob.signForm(taxForm);

  // Alice tries to sign, should succeed
  alice.signForm(taxForm);

  // Alice tries to sign again, no effect but shows signed status
  alice.signForm(taxForm);

  // Charlie tries to sign high-grade form
  Form topSecret("TopSecret", 5, 2);
  charlie.signForm(topSecret);

  // Bob tries to sign high-grade form, should fail
  bob.signForm(topSecret);

  std::cout << std::endl
            << CYAN << "=== Test Completed ===" << RESET << std::endl;

  return 0;
}
