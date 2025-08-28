#include "Bureaucrat.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

void testCreation(const std::string &name, int grade)
{
  std::cout << CYAN << "[Creating Bureaucrat: " << name << ", grade = " << grade << "]" << RESET << std::endl;
  try
  {
    Bureaucrat b(name, grade);
    std::cout << GREEN << "Success: " << b << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
  }
  std::cout << std::endl;
}

void testIncrement(Bureaucrat &b)
{
  std::cout << YELLOW << "Incrementing grade of " << b.getName() << " (current grade: " << b.getGrade() << ")" << RESET << std::endl;
  try
  {
    b.incrementGrade();
    std::cout << GREEN << "New grade: " << b.getGrade() << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
  }
  std::cout << std::endl;
}

void testDecrement(Bureaucrat &b)
{
  std::cout << YELLOW << "Decrementing grade of " << b.getName() << " (current grade: " << b.getGrade() << ")" << RESET << std::endl;
  try
  {
    b.decrementGrade();
    std::cout << GREEN << "New grade: " << b.getGrade() << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
  }
  std::cout << std::endl;
}

int main()
{
  std::cout << CYAN << "=== Bureaucrat Class Test ===" << RESET << std::endl
            << std::endl;

  // Test valid creations
  testCreation("Alice", 1);
  testCreation("Bob", 150);
  testCreation("Charlie", 75);

  // Test invalid creations
  testCreation("Zero", 0);
  testCreation("TooLow", 151);

  // Create a bureaucrat to test increment/decrement behavior
  Bureaucrat john("John Doe", 2);

  // Display
  std::cout << john << std::endl
            << std::endl;

  // Test increment until it throws
  testIncrement(john); // Should succeed (2 -> 1)
  testIncrement(john); // Should throw exception, grade can't go above 1

  // Set John's grade to 145 for decrement tests
  while (john.getGrade() < 145)
  {
    john.decrementGrade();
  }

  // Test decrement until it throws
  while (john.getGrade() < 150)
  {
    testDecrement(john);
  }

  // At grade 150 now, try decrement one more time to catch exception
  testDecrement(john);

  std::cout << CYAN << "=== End of Test ===" << RESET << std::endl;
  return 0;
}
