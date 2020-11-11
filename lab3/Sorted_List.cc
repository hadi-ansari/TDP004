#include <iostream>

#include "Sorted_List.h"



Sorted_List::Sorted_List()
  : first{nullptr}
{}
Sorted_List::Sorted_List(int v)
  : first{new Node{v}}
{}

// void Sorted_List::insert(int v)
// {
  
//   if( first == nullptr || first -> value > v)
//     {
//       first = new Node{nullptr, v};
//     }
//   else
//     {
//       Sorted_List::insert(first -> next);
//     }
  
  
// }


struct Sorted_list::Node
{
public:
  Node(int v)
    :next{nullptr}, value{v}
  {}
private:
  int value;
  Node* next;
};
