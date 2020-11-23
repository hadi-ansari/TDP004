#include "sorted_array.h"

#include <utility>
#include <stdexcept>

using namespace std;

sorted_array::sorted_array(initializer_list<int> list)
    : data{}
{
    for (int val : list)
    {
        insert(val);
    }
}


void sorted_array::insert(int value)
{
    data.push_back(value);
    for (int i {size() - 1}; i > 0; --i)
    {
        if (data[i] < data[i-1])
        {
            swap(data[i-1], data[i]);
        }
        else
        {
            break;
        }
    }
}

int sorted_array::erase(int index)
{
    if (index < 0 || index >= size())
        throw std::out_of_range{"unable to erase; index is out of bounds."};
    for (int i {index}; i + 1 < size(); ++i)
    {
        swap(data[i], data[i+1]);
    }
    int value {data.back()};
    data.pop_back();
    return value;
}

int & sorted_array::operator[](int index)
{
    return data[index];
}

int sorted_array::operator[](int index) const
{
    return data[index];
}

int & sorted_array::at(int index)
{
    return data.at(index);
}

int sorted_array::at(int index) const
{
    return data.at(index);
}

int sorted_array::size() const
{
    return static_cast<int>(data.size());
}

ostream & operator<<(ostream & os, sorted_array const & array)
{
    if (array.size() == 0)
    {
        os << "{}";
        return os;
    }
    os << '{' << array[0];
    for (int i {1}; i < array.size(); ++i)
    {
        os << ", " << array[i];
    }
    os << '}';
    return os;
}
