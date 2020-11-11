// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs

// Komplettering: alla includes ska vara med innanför header guards för att 
//                undvika försök till att dubbelinkludera. 

// Komplettering: alla funktioner som inte modifierar datamedlemmarna ska vara const.

// Komplettering: Ni saknar operatorer för <= och >=.

// Komplettering: Flytta in is_valid-checken innanför fix_time så behöver ni inte 
//                anropa is_valid varje gång ni ska köra fix_time.

// Komplettering: Alla jämförelseoperatorer ska inte vara fullt implementerade, 
//                dvs att dem kontrollerar själva datamedlemmarna. Implementera max. 2st
//                och använd dessa för att implementera de andra. Kom ihåg negation, !.

// Komplettering: Ni testar inte input/output operatorerna. Använd istringstream/ostringstream för att testa dessa
//                istället för cin/cout. Glöm inte att även testa input när den får fel data och att falggan sätts.
#ifndef TIME_H
#define TIME_H
class Time
{
 public:
 // Komplettering: Om användaren försöker skapa en tom Time, Time t{}, så förväntas det 
 //                det att tomkonstruktorn körs, men istället kallar den på denna konstruktor 
 //                med default värdena. Skapa istället en tomkonstruktor som default initierar tiden.
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
