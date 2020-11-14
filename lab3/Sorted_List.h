#ifndef SORTED_LIST_H
#define SORTED_LIST_H

class Sorted_List
{
private:
  struct Node;
  Node* first{};
  
  void insert_node( Node* & ptr, int v);
  void del(Node*);
  
 public:
  Sorted_List();
  Sorted_List(int const);
  
  Sorted_List(Sorted_List const&);
  Sorted_List& operator=(Sorted_List const&);
  
  Sorted_List(Sorted_List &&);
  Sorted_List& operator=(Sorted_List &&);
  
  ~Sorted_List();

  void insert(int const);
  void remove(int const);
  std::string to_string()const;
  void print()const;
  bool is_empty()const;
  int size()const;
  bool check_order()const;
  
  int get_value(int const )const; /* return value by index (zero indexing) */
  int get_first_value()const;
  int get_last_value()const;
};
#endif
