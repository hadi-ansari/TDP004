#include <iostream>

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
Sorted_List::Sorted_List(int v)
  : first{new Node{ nullptr, v}}
{}
// Copy constructor
Sorted_List::Sorted_List(Sorted_List const& rhs)
{
  // Node* current_rhs{rhs.first};

  // while(current_rhs != nullptr)
  //   {
  //     insert(current_rhs -> value);
  //     current_rhs = current_rhs -> next;
  //   }
  *this = rhs;
}
Sorted_List& Sorted_List::operator=(Sorted_List const& rhs)
 {
   Node* current{first};
   Node* current_rhs{rhs.first};
   //   Node* previous_rhs{rhs.first};
   
   while(current != nullptr)
     {
       Node* temp{current};
       
       current = current -> next;
       remove(temp -> value);
     }
   while(current_rhs != nullptr)
     {
       insert(current_rhs -> value);
       current_rhs = current_rhs -> next; 
     }
   
   return *this;
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
void Sorted_List::print()const
{
  Node* current{first};
  while(current != nullptr)
    {
      std::cout << current -> value << " ";
      current = current -> next;
    }
  std::cout << std::endl;
}
void Sorted_List::insert(int v)
{
  insert_node(first, v);
}
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
void Sorted_List::remove(int v)
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

int Sorted_List::get_first_element()const
{
  return first -> value;
}
