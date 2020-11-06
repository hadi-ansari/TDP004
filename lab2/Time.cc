// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h
#include <iostream>
#include <string>

#include "Time.h"

Time::Time(int const h, int const m, int const s)
  :hour{h}, minute{m}, second{s}
{}


bool Time::is_valied()const
{
  if(hour < 24 && minute < 60 && second < 60 )
    {
      return true;
    }
  return false;
}
std::string Time::to_string()const
{
  std::string time{};
  std::string min{};
  std::string sec{};
  
  if(minute < 10)
    {
      min = '0' + std::to_string(minute); 
    }
  else
    {
      min = std::to_string(minute);
    }

  if(second < 10)
    {
      sec = '0' + std::to_string(second);
    }
  else
    {
      sec = std::to_string(second);
    }
  
  time = ':' + min + ':' + sec;
  
  if(hour < 12)
    {
      std::string temp{};
      temp = '0' + std::to_string(hour);
      time.insert( 0, temp );
      time += " am";
    }
  else
    {
      time.insert( 0, std::to_string(hour % 12) );
      time += " pm";      
    }
  return time;
}


Time& Time::operator++()
{
  ++second;
  return *this;

}
Time Time::operator+(int num)const
{
  return Time {hour, minute, second + num};
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


 // int i{1};
 //  stringstream ss;
 //  ss << setw(2) << setfill('0') << i;
 //  string s{ss.str()};
 //  ss.str("");
 
