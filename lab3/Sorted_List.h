// Ser i överlag mycket bra ut. Ni har fått några kompletteringar och de ska ni
// fixa.  Kommentarerna är bör ni kolla på men behövs inte fixas.

// Komplettering: undvik variabelnamn som endast är en bokstav. Otydligt.

#ifndef SORTED_LIST_H
#define SORTED_LIST_H

class Sorted_List
{
private:
  struct Node;
  Node* first{};
  
  void insert_node( Node* &, int);
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
  // Kommentar: Tips till framtiden: om användaren till er lista vill skriva ut
  //            till någon annan ström än cout blir det svårt nu. Istället skulle
  //            er print-funktion kunna ta in en ostream& så användaren kan
  //            bestämma vilken ström den vill printa till.
  void print()const;
  bool is_empty()const;
  int size()const;
  // Komplettering: Konstigt att en Sorted_List har en funktion som kollar om
  //                listan är sorterad eller inte. Namnet antyder att listan
  //                ska vara sorterad så det borde inte behövas för användaren
  //                till listan. 
  // bool check_order()const; /Hadi & Nils: Vi har fixat koden så att den inte behöver en
  //          check_order funktion längre.
  
  int get_value(int const )const; /* return value by index (zero indexing) */
  int get_first_value()const;
  int get_last_value()const;
};
#endif
