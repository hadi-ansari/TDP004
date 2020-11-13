#ifndef SORTED_LIST_H
#define SORTED_LIST_H

class Sorted_List
{
private:
  struct Node;
  Node* first{};
  void insert_node( Node* & ptr, int v);
  
 public:
  Sorted_List();
  Sorted_List(int);
  Sorted_List(Sorted_List const&);
  Sorted_List& operator=(Sorted_List const&);
  ~Sorted_List();
  void del(Node* &);
  
  bool is_empty()const;
  int size()const;
  void print()const;
  void insert(int v);
  void remove(int v);
  std::string to_string()const;
  bool check_order()const;
  
  int get_value(int const )const;
  int get_first_value()const;
  int get_last_value()const;
};
#endif
