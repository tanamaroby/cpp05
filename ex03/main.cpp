#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <exception>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

void printTitle(const std::string &title)
{
  std::cout << CYAN << "=== " << title << " ===" << RESET << std::endl;
}

int main()
{
  printTitle("Exercise 02: Robust Testing of Bureaucrat & Forms");

  Bureaucrat alice("Alice", 1);
  Bureaucrat bob("Bob", 70);
  Bureaucrat charlie("Charlie", 150);

  ShrubberyCreationForm shrubbery("home");
  RobotomyRequestForm robotomy("Bender");
  PresidentialPardonForm pardon("Marvin");

  // Print initial form states
  std::cout << shrubbery << std::endl;
  std::cout << robotomy << std::endl;
  std::cout << pardon << std::endl;

  // Testing signing forms with various bureaucrats
  printTitle("Signing Forms");

  bob.signForm(shrubbery);    // Should succeed (grade 70 vs 145)
  charlie.signForm(robotomy); // Should fail (grade 150 > 72)
  alice.signForm(pardon);     // Should succeed (grade 1 vs 25)
  alice.signForm(robotomy);   // Should succeed (grade 1 vs 25)

  std::cout << shrubbery << std::endl;
  std::cout << robotomy << std::endl;
  std::cout << pardon << std::endl;

  // Robust test: try signing multiple times
  bob.signForm(shrubbery); // Already signed, should just acknowledge
  alice.signForm(pardon);  // Already signed

  printTitle("Executing Forms");

  // Execute each form with different bureaucrats

  // Shrubbery by Bob (grade 70) - should succeed (exec grade 137)
  bob.executeForm(shrubbery);

  // Robotomy by Bob (grade 70) - should fail: insufficient exec grade (45)
  bob.executeForm(robotomy);

  // Robotomy by Alice (grade 1) - should succeed with 50% success/failure
  alice.executeForm(robotomy);

  // Pardon by Alice (grade 1) - should succeed
  alice.executeForm(pardon);

  // Executing unsigned form to test exception handling
  ShrubberyCreationForm unsignedForm("unsigned_home");
  alice.executeForm(unsignedForm); // Should print error about not signed

  printTitle("Boundary Condition Tests");

  try
  {
    Bureaucrat tooHigh("TooHigh", 0); // Should throw GradeTooHighException
  }
  catch (std::exception &e)
  {
    std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
  }

  try
  {
    Bureaucrat tooLow("TooLow", 151); // Should throw GradeTooLowException
  }
  catch (std::exception &e)
  {
    std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
  }

  try
  {
    ShrubberyCreationForm invalidForm("invalid");
    AForm &formRef = invalidForm;
    formRef.beSigned(Bureaucrat("LowGrade", 150)); // Should throw GradeTooLowException
  }
  catch (std::exception &e)
  {
    std::cout << RED << "Exception caught while signing: " << e.what() << RESET << std::endl;
  }

  printTitle("All tests completed successfully!");

  return 0;
}
