#include <iostream>
#include <string>
#include <algorithm>

#include "Sorted_List.h"

struct Sorted_List::Node
{
  Node(Node* ptr, int value)
    : value{value}, next{ptr}
  {}
  
  int value{};
  Node* next{};
};

Sorted_List::Sorted_List()
  : first{nullptr}
{}
Sorted_List::Sorted_List(int const value)
  : first{new Node{ nullptr, value}}
{}
// Kommentar: Bättre att utnyttja konstruktorn i tilldelnings-
//            operator än som ni gjort nu. 
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
  Node* temp{};
  // removing all items in lhs list if it is not empty
  while(current != nullptr)
  {
    // Kommentar: ni skapar en ny nodepekare varje iteration av loopen.
    //            Skulle kunna deklarera temp utanför.
    temp = current;
    current = current -> next;
    remove(temp -> value);
  }
  // Komplettering: onödigt att anropa insert här. Insert går igenom listan
  //                från början igen (den börjar ju iterera från first). Vi är
  //                redan på rätt plats när vi kallar insert, så utnyttja det
  //                istället.
  // (Deep) Copying items from rhs to lhs which is empty now
  while(current_rhs != nullptr)
  {
    if(first == nullptr)
      {
	first = new Node{nullptr, current_rhs -> value};
	current = first;
      }
    else
      {
	current -> next = new Node{nullptr, current_rhs -> value};
	current = current -> next;
      }
    current_rhs = current_rhs -> next;
  }
   
  return *this;
}

// Move constructor and operator
Sorted_List::Sorted_List(Sorted_List && rhs)
{
  *this = std::move(rhs);
}
// Komplettering: Destruktorn kommer att kallas av kompilatorn så att kalla rhs
//            destruktor explicit är onödigt. Det är väldigt sällan (läs aldrig)
//            som ni behöver kalla själva destruktorn ~Sorted_List() explicit.
Sorted_List& Sorted_List::operator=(Sorted_List && rhs)
{
  std::swap(first, rhs.first);
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

void Sorted_List::insert(int const value)
{
  insert_node(first, value);
}
// Recursive insert function
void Sorted_List::insert_node(Node* & ptr, int value)
{
  // Kommentar: De två första delarna av if-satsen skulle kunna lösas
  //            med ptr = new Node{ptr,v}; Alltså ligga i samma block.
  //            Eftersom om ptr är nullptr så är det ekvivalent med
  //            new Node{nullptr,v}
  if(ptr == nullptr)
  {
    ptr = new Node{nullptr, value};
  }
  else if(ptr -> value > value)
  {
    Node* temp{new Node{ptr, value}};
    ptr = temp;
  }
  else
  {
    insert_node(ptr -> next, value);
  }
  
}
// Iterative remove function
void Sorted_List::remove(int const value)
{
  Node* current{first};
  Node* previous{first};
  
  while(current != nullptr)
  {
    if(first -> value == value)
  	{
  	  first = current -> next;
  	  delete current;
  	  break;
  	}
    else if(current -> value == value)
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
// Komplettering: Varför anropar ni to_string som en statisk funktion?
//                Ni vill ju anropa this->to_string() vilket är samma
//                som att bara skriva to_string() inne i klassen ju.
void Sorted_List::print()const
{
  std::cout << to_string() << std::endl;
}
// Komplettering: Kan skrivas som 
//            return first == nullptr;
//            eftersom first == nullptr evalueras till en boolean.
bool Sorted_List::is_empty()const
{
  return first == nullptr;
}
// Kommentar: Kan vara värt (läs bra) att ha en variabel som håller koll på
//            listans storlek och vi slipper då iterera genom den för att räkna.
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

// Komplettering: Spar undan size som en lokal variabel i funktionen istället
//                för att anropa den i varje iteration i for-loopen. Nu jämför
//                vi variabeln i med returvärdet av size() i varje
//                iteration. Size() går igenom hela listan och räknar element
//                ==> dyrt!
int Sorted_List::get_value(int const index)const
{
  Node* current{first};
  int list_size = size();
  
  for(int i{0}; i < list_size ; ++i)
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
// Kommentar: Kan argumenterar att om man som användare vill ha en container för
//            element, där man ska kunna hämta ut sista elementet är en enkel-länkad lista
//            ett dåligt val. Eftersom man måste iterera genom hela listan för att få ut
//            det sista elementet. Isåfall hade man valt någon annan container. Men ni
//            visar att ni har koll på länkade strukturen och det är mycket bra!
int Sorted_List::get_last_value()const
{
  Node* current{first};
  while(current -> next != nullptr)
  {
    current = current -> next;
  }
  return current -> value;;
}
