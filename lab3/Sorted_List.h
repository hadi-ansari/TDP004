#ifndef SORTED_LIST_H
#define SORTED_LIST_H

class Sorted_List
{
private:
  struct Node;
  Node* first{};
  
 public:
  Sorted_List();
  Sorted_List(int);

  bool is_empty()const;
  int size()const;
  void print()const;
  void insert(int v);
  void insert_node( Node* & ptr, int v);
  void remove(int v);
  int get_first_element()const;
};
#endif
