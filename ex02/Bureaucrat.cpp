#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
  if (_grade < 1)
    throw GradeTooHighException();
  if (_grade > 150)
    throw GradeTooLowException();
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

// Assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
  if (this != &other)
  {
    // _name is const, so cannot assign it
    _grade = other._grade;
  }
  return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Getters
const std::string &Bureaucrat::getName() const
{
  return _name;
}

int Bureaucrat::getGrade() const
{
  return _grade;
}

// Increment grade
void Bureaucrat::incrementGrade()
{
  if (_grade - 1 < 1)
    throw GradeTooHighException();
  --_grade;
}

// Decrement grade
void Bureaucrat::decrementGrade()
{
  if (_grade + 1 > 150)
    throw GradeTooLowException();
  ++_grade;
}

// Exceptions what()
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
  return "Bureaucrat exception: Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
  return "Bureaucrat exception: Grade too low";
}

// Overload operator<<
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
  os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
  return os;
}

void Bureaucrat::signForm(AForm &form) const
{
  try
  {
    form.beSigned(*this);
    std::cout << _name << " signed " << form.getName() << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << _name << " couldn't sign " << form.getName()
              << " because " << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const &form) const
{
  try
  {
    form.execute(*this);
    std::cout << getName() << " executed " << form.getName() << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << getName() << " couldn’t execute " << form.getName()
              << " because " << e.what() << std::endl;
  }
}