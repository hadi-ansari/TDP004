#ifndef SORTED_ARRAY_H
#define SORTED_ARRAY_H

#include <vector>
#include <initializer_list>
#include <ostream>

class sorted_array
{

public:

    sorted_array() = default;
    sorted_array(std::initializer_list<int> list);

    void insert(int value);
    int erase(int index);

    int & operator[](int index);
    int operator[](int index) const;

    int & at(int index);
    int at(int index) const;

    int size() const;

private:

    std::vector<int> data{};

};

std::ostream & operator<<(std::ostream & os, sorted_array const & array);

#endif//SORTED_ARRAY_H
