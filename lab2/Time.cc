// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "Time.h"

Time::Time(int const h, int const m, int const s)
  :hour{h}, minute{m}, second{s}
{}


bool Time::is_valid()const
{
  if(hour < 24 && minute < 60 && second < 60 )
    {
      return true;
    }
  return false;
}
void Time::fix_time()
{
  if(second >= 60)
    {
      minute += second / 60;
      second = second % 60;
      if(minute >= 60)
	{
	  hour += minute / 60;
	  minute = minute % 60;
	  if(hour >= 24)
	    {
	      hour = hour % 24;
  	    }

	}
    }
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
  return Time {hour, minute, second - num};
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


int Time::get_hour()const
{
  return hour;
}
int Time::get_minute()const
{
  return minute;
}
