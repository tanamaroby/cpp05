#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExec;

  AForm(); // disable default constructor

public:
  // Orthodox Canonical Form methods
  AForm(const std::string &name, int gradeToSign, int gradeToExec);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);
  virtual ~AForm();

  // Getters
  const std::string &getName() const;
  bool isSigned() const;
  int getGradeToSign() const;
  int getGradeToExec() const;

  // Member functions
  void beSigned(const Bureaucrat &bureaucrat);
  virtual void execute(Bureaucrat const &executor) const = 0; // pure virtual

  // Exceptions
  class GradeTooHighException : public std::exception
  {
  public:
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception
  {
  public:
    virtual const char *what() const throw();
  };
  class FormNotSignedException : public std::exception
  {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
