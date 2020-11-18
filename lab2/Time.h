// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs

// Komplettering: Funktioner som enbart består av en if(villkor) och returnerar true eller false
//                ska returnera villkoret direkt.

// Ang. to_string
// Komplettering: Fundera lite på vad som egentligen behöver hanteras i detta fall.
//                Vad är det som skiljer fallen 24h, am och pm? 
//                Vad är det som egentligen behöver göras i if-satserna?
// Forts. minuter och sekunder bör inte hanteras inuti if-satsen då dessa inte skiljer 
//        sig mellan ampm och 24h.

// Komplettering: Ta en titt i inputoperatorn. / Hadi & Nils: Vi har mejlat Mladen om detta och han godkände den.
#ifndef TIME_H
#define TIME_H
class Time
{
 public:
  Time(int const h, int const m, int const s);
  Time();
  
  bool is_valid()const;
  void fix_time();
  std::string to_string(bool time_24 = true)const;
  
  Time operator-(int num)const;
  Time operator+(int num)const;
  Time& operator++();
  Time operator++(int);
  Time& operator--();
  Time operator--(int);
  bool operator==(Time const& t)const;
  bool operator!=(Time const& t)const;
  bool operator>(Time const& t)const;
  bool operator<(Time const& t)const;
  bool operator>=(Time const& t)const;
  bool operator<=(Time const& t)const;

  
  int get_hour()const;
  int get_minute()const;
  int get_second()const;

  friend std::istream& operator>>(std::istream & lhs, Time & rhs);
   
 private:
  int hour{};
  int minute{};
  int second{};
};

// Kommentar: Bra! Detta löste ni väldigt elegant.
std::ostream& operator<<(std::ostream & lhs, Time const& rhs);


#endif
