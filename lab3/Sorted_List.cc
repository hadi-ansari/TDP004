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

