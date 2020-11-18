// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h
#include <iostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>

#include "Time.h"

Time::Time(int const h, int const m, int const s)
  :hour{h}, minute{m}, second{s}
{}

Time::Time()
  :hour{0}, minute{0}, second{0}
{}
bool Time::is_valid()const
{
  return ( hour < 24 && hour >= 0
	   && minute < 60 &&  minute >= 0
	   && second < 60 && second >= 0 );
}
// Kommentar: Funktioner bör inte ha mer än ett ansvar, om ni hade delat upp 
//            detta i två funktioner för negativ och positiv korrigering så 
//            skulle dem bli betydligt mindre komplexa och lättare att förstå.
void Time::fix_time()
{
  if(is_valid() == false)
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
}

// Kommentar: Fantastiskt bra att ni använder stringstream! Det gör det hela så mycket lättare.
std::string Time::to_string(bool time_24 )const
{
  std::stringstream ss;

  ss << std::setfill('0');
   
  if(time_24)
    {
      ss << std::setw(2) << hour << ':' << std::setw(2) << minute
	 << ':' << std::setw(2) << second;
    }
  else
    {
      if(hour < 12)
	{
	  ss << std::setw(2) << hour << ':' << std::setw(2) << minute
	     << ':' << std::setw(2) << second << " am";
	}
      else if(hour == 12)
	{
	  ss << std::setw(2) << hour << ':' << std::setw(2) << minute
	     << ':' << std::setw(2) << second << " pm";
	}
      else
	{
	  ss << std::setw(2) << (hour % 12) << ':' << std::setw(2) << minute
	     << ':' << std::setw(2) << second << " pm";
	}
    }
  return ss.str();
}

Time Time::operator+(int num)const
{
  Time temp{hour, minute, second + num};
  
  temp.fix_time();
  return temp;
}
Time Time::operator-(int num)const
{
  Time temp{hour, minute, second - num};

  temp.fix_time();
  return temp;
}
Time& Time::operator++()
{
  ++second;
  
  fix_time();
  return *this;

}
Time Time::operator++(int)
{
  Time temp{*this};

  ++second;
  fix_time();
  return temp;
}
Time& Time::operator--()
{
  --second;
  fix_time();
  return *this;

}
Time Time::operator--(int)
{
  Time temp{*this};

  --second;
  fix_time();
  return temp;
}
bool Time::operator==(Time const& t)const
{
  int lhs_sum_of_seconds{};
  int rhs_sum_of_seconds{};

  lhs_sum_of_seconds = hour*3600 + minute*60 + second;
  rhs_sum_of_seconds = t.get_hour()*3600 + t.get_minute()*60 + t.get_second();

  return lhs_sum_of_seconds == rhs_sum_of_seconds;
}
bool Time::operator!=(Time const& t)const
{

  return !(*this == t);
  
}
bool Time::operator>(Time const& t)const
{
  int lhs_sum_of_seconds{};
  int rhs_sum_of_seconds{};
    
  lhs_sum_of_seconds = hour*3600 + minute*60 + second;
  rhs_sum_of_seconds = t.get_hour()*3600 + t.get_minute()*60 + t.get_second();
  
  return lhs_sum_of_seconds > rhs_sum_of_seconds;
}
bool Time::operator<(Time const& t)const
{
  return !(*this > t || *this == t);
}
bool Time::operator>=(Time const& t)const
{
  return (*this > t || *this == t);
}
bool Time::operator<=(Time const& t)const
{
  return(*this < t || *this == t);
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
// Komplettering: Modifiera inte rhs innan ni är säkra på att datat i lhs resulterar i en korrekt tid.
  char trash{};
  lhs >> rhs.hour >> trash >> rhs.minute >> trash >> rhs.second;
  if(!rhs.is_valid())
    {
     lhs.setstate(std::ios::failbit);
     // Hadi && Nils: rhs modiferas med en orimlig heltal (med tanken på att
     // användaren endast matar in heltal )  "men" sedan valideras den med if-sats och
     // om värden inte är rimliga heltal får all variabler en nolla som default-värde

// Mladen: Om operatorn inte lyckas uppdatera rhs pga indatat inte är korrekt 
//         så bör rhs fortfarande innehålla originalvärdena, rhs ska behålla 
//         sitt tillstånd. Använd ett temporärt timeobjekt och assignment, =.

     //Hadi & Nils: Vi har mejlat Mladen om detta och han godkände den.
     rhs.hour = 0;
     rhs.minute = 0;
     rhs.second = 0;
    }

  return lhs;
}


std::ostream& operator<<(std::ostream & lhs, Time const& rhs)
{
  lhs << rhs.to_string();
  return lhs;
}


