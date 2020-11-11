#include <iostream>

#include "Sorted_List.h"

List::Sorted_List()
  : first{nullptr}
{}
List::Sorted_List(int v)
  : first{new Node{nullptr, v}}
{}

void List::insert(int v)
{
  
  if( first == nullptr || first -> value > v)
    {
      first = new Node{nullptr, v};
    }
  else
    {
      List::insert(first -> next);
    }
  
  
}

struct Sorted_List::Node
{
public:
  Time::Node(Node* ptr, int v)
    : next{ptr}, value{v}
  {}
private:
  int value{};
  Node* next;
}
