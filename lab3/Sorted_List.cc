#include <iostream>
#include <string>
#include <algorithm>

#include "Sorted_List.h"

struct Sorted_List::Node
{
  Node(Node* ptr, int v)
    : value{v}, next{ptr}
  {}
  
  int value{};
  Node* next{};
};

Sorted_List::Sorted_List()
  : first{nullptr}
{}
Sorted_List::Sorted_List(int const v)
  : first{new Node{ nullptr, v}}
{}

// Copy constructor and operator
Sorted_List::Sorted_List(Sorted_List const& rhs)
  :first{nullptr}
{
  *this = rhs;
}
Sorted_List& Sorted_List::operator=(Sorted_List const& rhs)
 {
   Node* current{first};
   Node* current_rhs{rhs.first};
   
   // removing all items in lhs list if it is not empty
   while(current != nullptr)
     {
       Node* temp{current};
       
       current = current -> next;
       remove(temp -> value);
     }
   
   // (Deep) Copying items from rhs to lhs which is empty now 
   while(current_rhs != nullptr)
     {
       insert(current_rhs -> value);
       current_rhs = current_rhs -> next; 
     }
   
   return *this;
 }

// Move constructor and operator
Sorted_List::Sorted_List(Sorted_List && rhs)
{
  *this = std::move(rhs);
}
Sorted_List& Sorted_List::operator=(Sorted_List && rhs)
{
  std::swap(first, rhs.first);
  rhs.~Sorted_List(); /* calling rhs destructor explicitly */
  return *this;
}

// Destructor
Sorted_List::~Sorted_List()
{
  del(first);
  first = nullptr;
}
void Sorted_List::del(Node* ptr)
{
  if(ptr != nullptr)
    {
      if(ptr -> next == nullptr)
	{
	  delete ptr;
	}
      else
	{
	  del(ptr -> next);
	  delete ptr;
      	}
    }
}

void Sorted_List::insert(int const v)
{
  insert_node(first, v);
}
// Recursive insert function
void Sorted_List::insert_node(Node* & ptr, int v)
{
  if(ptr == nullptr)
    {
      ptr = new Node{nullptr, v};
    }
  else if(ptr -> value > v)
    {
      Node* temp{new Node{ptr, v}};
      ptr = temp;
    }
  else
    {
      insert_node(ptr -> next, v);
    }
  
}
// Iterative remove function
void Sorted_List::remove(int const v)
{
  Node* current{first};
  Node* previous{first};
  
  while(current != nullptr)
    {
      if(first -> value == v)
  	{
  	  first = current -> next;
  	  delete current;
  	  break;
  	}
      else if(current -> value == v)
  	{
  	  previous -> next = current -> next;
  	  delete current;
  	  break;
  	}
      previous = current;
      current = current -> next;
    }
}
std::string Sorted_List::to_string()const
{
  std::string str{""};
  Node* current{first};
  
  while(current != nullptr)
    {
      str += std::to_string(current -> value);
      if(current -> next != nullptr)
	{
	  str += ' ';
	}
      current = current -> next;
    }  
  return str;
}
void Sorted_List::print()const
{
  std::cout << Sorted_List::to_string() << std::endl;
}
bool Sorted_List::is_empty()const
{
  if(first == nullptr)
    {
      return true;
    }
  return false;
}
int Sorted_List::size()const
{
  Node* current{first};
  int counter{0};
  while(current != nullptr)
    {
      ++counter;
      current = current -> next;
    }
  return counter;
}

bool Sorted_List::check_order()const
{
  if(size() > 1)
    {
      Node* previous{first -> next};
      Node* current{first -> next -> next};
      
      while(current != nullptr)
	{
	  if(previous -> value > current -> value)
	    {
	      return false;
	    }
	  current = current -> next;
	  previous = previous -> next;
	}
    }
  return true;
}

int Sorted_List::get_value(int const index)const
{
  Node* current{first};
  
  for(int i{0}; i < size() ; ++i)
    {
      if (i == index)
	{
	  return current -> value;
	}
      current = current -> next;
    }

  return -1;
}

int Sorted_List::get_first_value()const
{
  return first -> value;
}
int Sorted_List::get_last_value()const
{
  Node* current{first};
  while(current -> next != nullptr)
    {
      current = current -> next;
    }
  return current -> value;;
}
