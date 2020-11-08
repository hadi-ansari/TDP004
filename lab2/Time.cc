// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>

#include "Time.h"

Time::Time(int const h, int const m, int const s)
  :hour{h}, minute{m}, second{s}
{
}


bool Time::is_valid()const
{
  if ( hour < 24 && hour >= 0
     && minute < 60 &&  minute >= 0
     && second < 60 && second >= 0 )
    {
      return true;
    }
  return false;
}
void Time::fix_time()
{
  int temp{};
  
  if( second < 0)
    {
      temp = ( abs(second) + 59 ) / 60;
      temp = temp * (-1);
    }
  else
    {
      temp = second / 60;
    }
  second = std::abs(second + 60) % 60;
  minute = minute + temp;
  temp = 0;

   if( minute < 0)
    {
      temp = ( abs(minute) + 59 ) / 60;
      temp = temp * (-1);
    }
  else
    {
      temp = minute / 60;
    }
  minute = std::abs(minute + 60) % 60;
  hour = hour + temp;
  
  hour = std::abs(hour + 24) % 24;
  
}
std::string Time::to_string(bool time_24 )const
{
  std::string time{};
  std::string min{};
  std::string sec{};
  std::stringstream ss;

  ss << std::setw(2) << std::setfill('0') << minute;
      min = ss.str();
      ss.str("");

      ss << std::setw(2) << std::setfill('0') << second;
      sec = ss.str();
      ss.str("");
      
  if(time_24)
    {
     ss << std::setw(2) << std::setfill('0') << hour;
     std::string temp_h{};
     temp_h = ss.str();
     ss.str("");
     time = temp_h + ':';
     time += min + ':';
     time += sec;
    }
  else
    {
      time = ':' + min + ':' + sec;
      if(hour < 12)
	{
	  ss << std::setw(2) << std::setfill('0') << hour;
	  time.insert( 0,  ss.str());
	  time += " am";
	}
      else if(hour == 12)
	{
	  time.insert(0, "12");
	  time += " pm";
	}
      else
	{
	  ss << std::setw(2) << std::setfill('0') << (hour % 12);
	  time.insert( 0, ss.str());
	  time += " pm";      
	}
    }
  return time;
}

Time Time::operator+(int num)const
{
  Time temp{hour, minute, second + num};
  if(!temp.is_valid())
    {
      temp.fix_time();
    }
  return temp;
}
Time Time::operator-(int num)const
{
  Time temp{hour, minute, second - num};
  if(!temp.is_valid())
    {
      temp.fix_time();
    }
  return temp;
}
Time& Time::operator++()
{
  ++second;
  if(!is_valid())
    {
      fix_time();
    }
  return *this;

}
Time Time::operator++(int)
{
  Time temp{*this};
  ++second;
  if(!is_valid())
    {
      fix_time();
    }
  return temp;
}
Time& Time::operator--()
{
  --second;
  if(!is_valid())
    {
      fix_time();
    }
  return *this;

}
Time Time::operator--(int)
{
  Time temp{*this};
  --second;
  if(!is_valid())
    {
      fix_time();
    }
  return temp;
}
bool Time::operator>(Time const& t)
{
  int lhs_sum_of_seconds{};
  int rhs_sum_of_seconds{};
    
  lhs_sum_of_seconds = hour*3600 + minute*60 + second;
  rhs_sum_of_seconds = t.get_hour()*3600 + t.get_minute()*60 + t.get_second();
  
  if(lhs_sum_of_seconds > rhs_sum_of_seconds)
    {
      return true;      
    }
  return false;
}
bool Time::operator<(Time const& t)
{
  int lhs_sum_of_seconds{};
  int rhs_sum_of_seconds{};
    
  lhs_sum_of_seconds = hour*3600 + minute*60 + second;
  rhs_sum_of_seconds = t.get_hour()*3600 + t.get_minute()*60 + t.get_second();
  
  if(lhs_sum_of_seconds < rhs_sum_of_seconds)
    {
      return true;      
    }
  return false;

}
bool Time::operator!=(Time const& t)
{
  int lhs_sum_of_seconds{};
  int rhs_sum_of_seconds{};

  lhs_sum_of_seconds = hour*3600 + minute*60 + second;
  rhs_sum_of_seconds = t.get_hour()*3600 + t.get_minute()*60 + t.get_second();

  if(lhs_sum_of_seconds != rhs_sum_of_seconds)
    {
      return true;      
    }
  return false;
  
}
bool Time::operator==(Time const& t)
{
  int lhs_sum_of_seconds{};
  int rhs_sum_of_seconds{};

  lhs_sum_of_seconds = hour*3600 + minute*60 + second;
  rhs_sum_of_seconds = t.get_hour()*3600 + t.get_minute()*60 + t.get_second();

  if(lhs_sum_of_seconds == rhs_sum_of_seconds)
    {
      return true;      
    }
  return false;
  
}

int Time::get_hour()const
{
  return hour;
}
int Time::get_minute()const
{
  return minute;
}
int Time::get_second()const
{
  return second;
}

std::istream& operator>>(std::istream & lhs, Time & rhs)
{
  do
    {
      lhs >> rhs.hour >> rhs.minute >> rhs.second;
      if(!rhs.is_valid())
	{
	  std::cerr << "Felaktig inmatning!" << std::endl;
	}
    }
  while(!rhs.is_valid());
  return lhs;
}


std::ostream& operator<<(std::ostream & lhs, Time const& rhs)
{
  lhs << rhs.to_string();
  return lhs;
}


