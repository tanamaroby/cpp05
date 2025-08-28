#include "Form.hpp"

// Constructor
Form::Form(const std::string &name, int gradeToSign, int gradeToExec)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
  if (gradeToSign < 1 || gradeToExec < 1)
    throw GradeTooHighException();
  if (gradeToSign > 150 || gradeToExec > 150)
    throw GradeTooLowException();
}

// Copy constructor
Form::Form(const Form &other)
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
}

// Assignment operator
Form &Form::operator=(const Form &other)
{
  if (this != &other)
  {
    // _name, _gradeToSign and _gradeToExec are const and can't be assigned
    _isSigned = other._isSigned;
  }
  return *this;
}

// Destructor
Form::~Form() {}

// Getters
const std::string &Form::getName() const
{
  return _name;
}

bool Form::isSigned() const
{
  return _isSigned;
}

int Form::getGradeToSign() const
{
  return _gradeToSign;
}

int Form::getGradeToExec() const
{
  return _gradeToExec;
}

// Member function to attempt to sign the form
void Form::beSigned(const Bureaucrat &bureaucrat)
{
  if (bureaucrat.getGrade() > _gradeToSign)
    throw GradeTooLowException();
  _isSigned = true;
}

// Exception what()
const char *Form::GradeTooHighException::what() const throw()
{
  return "Form exception: grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
  return "Form exception: grade too low";
}

// Overload operator<< for Form status output
std::ostream &operator<<(std::ostream &out, const Form &form)
{
  out << "Form \"" << form.getName() << "\", signed: " << (form.isSigned() ? "yes" : "no")
      << ", grade required to sign: " << form.getGradeToSign()
      << ", grade required to execute: " << form.getGradeToExec();
  return out;
}
