// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs
#include <string>
#ifndef TIME_H
#define TIME_H
class Time
{
 public:
  Time(int const h, int const m, int const s);


  bool is_valid()const;
  void fix_time();
  std::string to_string(bool time_24 = false)const;
  
  Time operator-(int num)const;
  Time operator+(int num)const;
  Time& operator++();

  
  int get_hour()const;
  int get_minute()const;
  
   
 private:
  int hour{};
  int minute{};
  int second{};
};

#endif
