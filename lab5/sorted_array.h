#ifndef SORTED_ARRAY_H
#define SORTED_ARRAY_H

#include <vector>
#include <initializer_list>
#include <ostream>
#include <cstdlib>

template <typename T>
class Distance
{
public:
  Distance(T center)
    : center{center}
  {}
  bool compare(T a, T b)
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
  bool compare(T a, T b)
  {
    return a < b;
  }

};

template <typename T, typename C = Less<T>>
class sorted_array
{
public:
  
  sorted_array() = default;
  sorted_array(std::initializer_list<T> list);
  sorted_array(std::initializer_list<T> list, C comparator);
  
  void insert(T value);
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
std::ostream & operator<<(std::ostream & os, sorted_array<T, C> const & array);



#include "sorted_array.cc"

#endif//SORTED_ARRAY_H


