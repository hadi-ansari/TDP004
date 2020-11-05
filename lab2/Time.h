// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs
#include <string>
#ifndef TIME_H
#define TIME_H
class Time
{
 public:
  Time(int const h, int const m, int const s);
  Time& operator++();
  void print_time()const;
  int get_hour()const;
  int get_minute()const;
  std::string get_string()const;
  /* Time operator+(int num); */
   
 private:
  int hour{};
  int minute{};
  int second{};
};

#endif
