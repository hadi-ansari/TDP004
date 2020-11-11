#include <iostrem>

#include "List.h"

List::List(int v)
  : first{new Node{nullptr, v}}
{}

struct List::Node
{
public:
  Time::Node(Node* ptr, int v)
    : next{ptr}, value{v}
  {}
private:
  int value{};
  Node* next;
}
