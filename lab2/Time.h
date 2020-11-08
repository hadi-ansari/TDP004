// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs
#include <string>
#include <iostream>
#include <istream>

#ifndef TIME_H
#define TIME_H
class Time
{
 public:
  Time(int const h = 0, int const m = 0, int const s = 0);


  bool is_valid()const;
  void fix_time();
  std::string to_string(bool time_24 = true)const;
  
  Time operator-(int num)const;
  Time operator+(int num)const;
  Time& operator++();
  Time operator++(int);
  Time& operator--();
  Time operator--(int);
  bool operator>(Time const& t);
  bool operator<(Time const& t);
  bool operator!=(Time const& t);
  bool operator==(Time const& t);
  
  int get_hour()const;
  int get_minute()const;
  int get_second()const;

  friend std::istream& operator>>(std::istream & lhs, Time & rhs);
   
 private:
  int hour{};
  int minute{};
  int second{};
};

std::ostream& operator<<(std::ostream & lhs, Time const& rhs);


#endif
