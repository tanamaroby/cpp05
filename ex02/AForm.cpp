#include "AForm.hpp"

// Constructor
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExec)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
  if (_gradeToSign < 1 || _gradeToExec < 1)
    throw AForm::GradeTooHighException();
  if (_gradeToSign > 150 || _gradeToExec > 150)
    throw AForm::GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm &other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign),
      _gradeToExec(other._gradeToExec)
{
}

// Assignment operator
AForm &AForm::operator=(const AForm &other)
{
  if (this != &other)
  {
    // _name, _gradeToSign, and _gradeToExec are const and cannot be assigned
    _isSigned = other._isSigned;
  }
  return *this;
}

// Destructor
AForm::~AForm()
{
}

// Getters
const std::string &AForm::getName() const
{
  return _name;
}

bool AForm::isSigned() const
{
  return _isSigned;
}

int AForm::getGradeToSign() const
{
  return _gradeToSign;
}

int AForm::getGradeToExec() const
{
  return _gradeToExec;
}

// Member function to allow a Bureaucrat to sign the form
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
  if (bureaucrat.getGrade() > _gradeToSign)
    throw AForm::GradeTooLowException();
  _isSigned = true;
}

// Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
  return "AForm Exception: Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
  return "AForm Exception: Grade too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
  return "AForm Exception: Form not signed";
}

// Output stream overload for printing form details
std::ostream &operator<<(std::ostream &os, const AForm &form)
{
  os << "Form \"" << form.getName() << "\", signed: ";
  if (form.isSigned())
    os << "yes";
  else
    os << "no";
  os << ", grade required to sign: " << form.getGradeToSign();
  os << ", grade required to execute: " << form.getGradeToExec();
  return os;
}
