#include "Bureaucrat.hpp"

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
