// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h
#include <iostream>
#include <string>

#include "Time.h"

Time::Time(int const h, int const m, int const s)
  :hour{h}, minute{m}, second{s}
{}


Time& Time::operator++()
{
  ++second;
  return *this;

}
Time Time::operator+(int num)const
{
  return Time {hour, minute, second + num};
}


void Time::print_time()const
{
  std::cout << hour << ":" << minute << ":" << second << std::endl;
}
int Time::get_hour()const
{
  return hour;
}
int Time::get_minute()const
{
  return minute;
}
std::string Time::get_string()const
{
  std::string time{};
  time = std::to_string(hour) + ":";
  time += std::to_string(minute) + ":";
  time += std::to_string(second);
  return time;

}
