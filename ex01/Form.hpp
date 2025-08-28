#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExec;

  Form(); // prevent default construction

public:
  Form(const std::string &name, int gradeToSign, int gradeToExec);
  Form(const Form &other);
  Form &operator=(const Form &other);
  ~Form();

  const std::string &getName() const;
  bool isSigned() const;
  int getGradeToSign() const;
  int getGradeToExec() const;

  void beSigned(Bureaucrat const &bureaucrat);

  class GradeTooHighException : public std::exception
  {
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception
  {
    const char *what() const throw();
  };
};

// Overload for outputting form status
std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
