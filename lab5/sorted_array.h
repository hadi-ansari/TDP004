#ifndef SORTED_ARRAY_H
#define SORTED_ARRAY_H

#include <vector>
#include <initializer_list>
#include <ostream>
#include <cstdlib>

// Komplettering: Fundera på vad som händer om T är en jättestor
// datatyp eller en datatyp som är dyr att kopiera. Överför vi
// parametrar på det bästa sättet för att ta hänsyn till det?
// T.ex. Onödigt att kopiera in 'a' och 'b' till compare, bättre att
// bara ta dem som de är.

template <typename T>
class Distance
{
public:
    
  Distance(T const& center)
    : center{center}
  {}
  bool compare(T const& a, T const& b)
  {
    return abs(a - center) < abs(b - center);
  }
private:
  T center{};
};

template <typename T>
class Less
{
 public:
  bool compare(T const& a, T const& b)
  {
    return a < b;
  }

};

template <typename T, typename C = Less<T>>
class sorted_array
{
public:
  
  sorted_array() = default;
  // sorted_array(std::initializer_list<T> list);
  sorted_array(std::initializer_list<T> list, C comparator = {});
  
  void insert(T const& value);
  T erase(int index);
  
  T & operator[](int index);
  T operator[](int index) const;
  
  T & at(int index);
  T at(int index) const;
  
  int size() const;
  
private:
  std::vector<T> data{};
  C comparator;


};

template <typename T, typename C>
std::ostream & operator<<(std::ostream & os, sorted_array<T, C> const& array);


// Kommentar: Bra!
#include "sorted_array.cc"

#endif//SORTED_ARRAY_H


