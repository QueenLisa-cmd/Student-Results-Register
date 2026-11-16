#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

struct Student
{
  std::string registrationNumber;
  std::string name;
  std::string course;
  double marks;  
  bool isValid()const
  {
    return !registrationNumber.empty() &&
    !name.empty() &&
    !course.empty() &&
    marks >= 0 && marks <=100;
  }
  bool operator == (const Student&other) const
  {
    return registrationNumber == other.registrationNumber;
  }
};

inline std::ostream&operator<<(std::ostream&out,const Student&student)
{
    out<<student.registrationNumber<<"|"
    <<student.name<<"|"
    <<student.course<<"|"
    <<student.marks;

    return out;
}

inline std::istream& operator>>(std::istream& in,Student& student)
{
    std::string line;

    if (!std::getline(in, line))
    return in;

    std::stringstream ss(line);
    std::string registrationNumber;
    std::string name;
    std::string course;
    std::string marksText;

    if(!std::getline(ss, registrationNumber,'|')||
!std::getline(ss, name, '|')||
!std::getline(ss, course, '|')||
!std::getline(ss, marksText))
{
    in.setstate(std::ios::failbit);
    return in;
}

try
{
   size_t position;
   double marks = std::stod(marksText, &position);
   
   if (position!=marksText.size())
   throw std::invalid_argument("invalid marks");
   
    Student temporary{
        registrationNumber,
        name,
        course,
        marks
    };

    if(!temporary.isValid())
    throw std::invalid_argument("Invalid Student record");

    student = temporary;
}
catch (...)
{
    in.setstate(std::ios::failbit);
}
return in;
}
