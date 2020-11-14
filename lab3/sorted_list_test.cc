// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// Note that the testcases outline here serve simply as inspiration
// you are not required to implement these tests, but you need to
// create tests for your list, so it might be a good idea to use
// these tests as a basis.

// This define lets Catch create the main test program
// (Must be in only one place!)
#include "catch.hpp"

#include <random>
#include <iostream>

#include "Sorted_List.h"
//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Create an empty list" ) 
{
    Sorted_List l{};

    REQUIRE( l.is_empty() );
    REQUIRE( l.size() == 0 );
}

TEST_CASE( "Create a list with one node" ) 
{
    Sorted_List l{5};

    REQUIRE( !l.is_empty() );
    REQUIRE( l.size() == 1);
    // Tests that the only item in the list is both first and last item in the list
    REQUIRE( l.get_first_value() == 5);
    REQUIRE( l.get_last_value() == 5);
}


TEST_CASE( "Insert an item in an empty list" ) 
{
    Sorted_List l{};

    l.insert(5);
    REQUIRE( !l.is_empty() );
    REQUIRE( l.size() == 1 );
    REQUIRE( l.get_first_value() == 5);
    REQUIRE( l.get_last_value() == 5);	
}

TEST_CASE( "Insert two item in an empty list" ) 
{
    Sorted_List l{};

    l.insert(5);
    l.insert(3);
    REQUIRE( !l.is_empty() );
    REQUIRE( l.size() == 2 );
  
}
TEST_CASE( "Insert three item in an empty list" ) 
{
    Sorted_List l{};

    l.insert(5);
    l.insert(3);
    l.insert(1);
    REQUIRE( !l.is_empty() );
    REQUIRE( l.size() == 3 );
  
}
TEST_CASE( "Insert four item in an empty list" ) 
{
    Sorted_List l{};

    l.insert(5);
    l.insert(3);
    l.insert(1);
    l.insert(13);
    REQUIRE( !l.is_empty() );
    REQUIRE( l.size() == 4 );
  
}

TEST_CASE( "Remove one item from a list with one item" ) 
{
    Sorted_List l{};

    l.insert(5);
    l.remove(5);
    REQUIRE( l.is_empty() );
    REQUIRE( l.size() == 0 );
  
}
TEST_CASE( "Remove one item from a list with two item " ) 
{
    Sorted_List l{};

    l.insert(3);
    l.insert(1);
    l.remove(3);
    REQUIRE( !l.is_empty() );
    REQUIRE( l.size() == 1 );
  
}
TEST_CASE( "Remove two item from a list with two item " ) 
{
    Sorted_List l{};

    l.insert(3);
    l.insert(1);
    l.remove(1);
    l.remove(3);
    REQUIRE( l.is_empty() );
    REQUIRE( l.size() == 0 );
  
}
TEST_CASE( "Remove three item from a list with four item " ) 
{
    Sorted_List l{};

    l.insert(3);
    l.insert(1);
    l.insert(12);
    l.insert(4);
    l.remove(1);
    l.remove(3);
    l.remove(4);
    REQUIRE( !l.is_empty() );
    REQUIRE( l.size() == 1 );
  
}





SCENARIO( "Empty lists" ) 
{
  
    GIVEN( "An empty list" ) 
    {
	Sorted_List l{};

	REQUIRE( l.is_empty() );
	REQUIRE( l.size() == 0 );
    
	WHEN( "an item is inserted" )
	{

	  l.insert(5); // insert an item
      
	    THEN( "the size increase and the item is first in the list" )
	    {
		REQUIRE( !l.is_empty()  );
		REQUIRE( l.size() == 1 );
		REQUIRE( l.get_first_value() == 5 ); /* test that item is first in list */
	    }
	}


	WHEN( "an item is removed" )
	{

	  // remove an item
	  l.remove(13);
      
	    THEN( "the list is still empty" )
	    {
	        REQUIRE( l.is_empty()  );
		REQUIRE( l.size() == 0 );
	    }
	}

	WHEN( "the list is copied to a new list" )
	{

	  // copy your list to a new variable (copy constructor)
	  Sorted_List l2{l};
	  THEN( "the new list is also empty" )
	    {
	      // add your REQUIRE statements
	      REQUIRE( l2.is_empty()  );
	      REQUIRE( l2.size() == 0 );
	    }
	}

	WHEN( "the list is copied to an existing non-empty list" )
	{
	  // create and fill a list to act as the existing list
	  // copy (assign) your empty list to the existing
	  Sorted_List l2{};
	  l2.insert(34);
	  l2 = l;
	    THEN( "the existing list is also empty" )
	    {
	      // add your REQUIRE statements
	      REQUIRE( l2.is_empty()  );
	      REQUIRE( l2.size() == 0 );
	    }
      
	}
    }
}


SCENARIO( "Single item lists" )
{

    GIVEN( "A list with one item in it" )
    {

      // create the given scenario
      Sorted_List l{20};
      
      REQUIRE( !l.is_empty() );
      REQUIRE( l.size() == 1 );
      REQUIRE( l.get_first_value() == 20 );
      
	WHEN( "a smaller item is inserted" )
	{
	  l.insert(15);
	    THEN( "the size increase and smaller item is first in the list")
	    {
	       REQUIRE( !l.is_empty() );
	       REQUIRE( l.size() == 2 );
	       REQUIRE( l.get_first_value() == 15 );
	    }
	}

	WHEN( "a larger item is inserted" )
	{
	  l.insert(35);
	  
	    THEN( "The size increase and the smaller item still is first in the list" )
	    {
	      REQUIRE( !l.is_empty() );
	      REQUIRE( l.size() == 2 );
	      REQUIRE( l.get_first_value() == 20 );
	    }
	}

	WHEN( "an item is removed" )
	{
	  l.remove(20);
	  
	    THEN("The list is empty")
	    {
	      REQUIRE( l.is_empty() );
	      REQUIRE( l.size() == 0 );
	    }
	}
	WHEN( "Trying to remove an item that is not in the list" )
	{
	  l.remove(65);
	  
	    THEN("The does not change and has one item in it")
	    {
	      REQUIRE( l.get_first_value() == 20 );
	      REQUIRE( !l.is_empty() );
	      REQUIRE( l.size() == 1 );
	    }
	}

	WHEN( "the list is copied to a new list" )
	{
	  Sorted_List l2{l};
	  
	    THEN( "new list has also one item same as original one " )
	    {
	      REQUIRE( l2.get_first_value() == 20 );
	      REQUIRE( !l2.is_empty() );
	      REQUIRE( l2.size() == 1 );
	    }
	}

	WHEN( "the list is copied to an existing non-empty list" )
	{
	  // Create a new list with two different items in it
	  Sorted_List l2{};
	  
	  l2.insert(109);
	  l2.insert(88);
	  
	  REQUIRE( l2.get_first_value() == 88 );
	  REQUIRE( !l2.is_empty() );
	  REQUIRE( l2.size() == 2 );
	  
	  l2 = l;
	  
	    THEN( "The non-empty list has one item same as original one" )
	    {
	      REQUIRE( l2.get_first_value() == 20 );
	      REQUIRE( !l2.is_empty() );
	      REQUIRE( l2.size() == 1 );
	    }
	}
    }
}


SCENARIO( "Multi-item lists" )
{

    GIVEN( "A list with five items in it" )
    {

	// create the given scenario and all THEN statements
	// and all REQUIRE statements
      Sorted_List l{};
      l.insert(9);
      l.insert(12);
      l.insert(26);
      l.insert(5);
      l.insert(17);
      // Sorted list is: 5 9 12 17 26 
      
      REQUIRE( l.get_first_value() == 5 );
      REQUIRE( !l.is_empty() );
      REQUIRE( l.size() == 5 );
    
	WHEN( "an item smaller than all other is inserted" )
	{
	  l.insert(3);
	  
	  THEN("The new added item is first in the list and size increase with one")
	    {
	      REQUIRE( l.get_first_value() == 3 );
	      REQUIRE( !l.is_empty() );
	      REQUIRE( l.size() == 6 );
	    }
	}

	WHEN( "an item larger than all other is inserted" )
	{
	  l.insert(235);
	  THEN("Size increase and last item is the inserted item")
	    {
	      REQUIRE( l.get_last_value() == 235 );
	      REQUIRE( !l.is_empty() );
	      REQUIRE( l.size() == 6 );	      
	    }
	}

	WHEN( "an item smaller than all but one item is inserted" )
	{
	  l.insert(7);
	  
	  THEN(" second item is the inserted item and size increase ")
	    {
	      REQUIRE( l.get_first_value() == 5 );
	      // Zero indexing (get_value(1) refers to second item)
	      REQUIRE( l.get_value(1) == 7 );
	      REQUIRE( !l.is_empty() );
	      REQUIRE( l.size() == 6 );	      
	    }
	}
	WHEN( "an item larger than all but one item is inserted" )
	{
	  l.insert(21);
	  
	  THEN( "second last item is the inserted item and size increase" )
	    {
	      REQUIRE( l.get_last_value() == 26 );
	      REQUIRE( l.get_value(4) == 21 );
	      REQUIRE( !l.is_empty() );
	      REQUIRE( l.size() == 6 );
	    }
	}
	WHEN( "an item is removed" )
	{
	  l.remove(12);
	   THEN( "Size decrease and list has four item" )
	    {
	      REQUIRE( !l.is_empty() );
	      REQUIRE( l.size() == 4 );
	    }
	}
	WHEN( "all items are removed" )
	{
	  l.remove(17);
	  l.remove(5);
	  l.remove(9);
	  l.remove(26);
	  l.remove(12);
	   THEN( "The list is empty" )
	    {
	      REQUIRE( l.is_empty() );
	      REQUIRE( l.size() == 0 );
	    }
	}
	WHEN( "the list is copied to a new list" )
	{
	  Sorted_List l2{l};

	  THEN( "new list has a copy of original list with five items " )
	    {
	      REQUIRE( !l2.is_empty() );
	      REQUIRE( l2.to_string() == "5 9 12 17 26" );
	      REQUIRE( l2.size() == 5 );
	    }
	}
	WHEN( "the list is copied to an existing list" )
	{
	  Sorted_List l2{};
	  l2 = l;

	  THEN( "new list has a copy of original list with five items " )
	    {
	      REQUIRE( !l2.is_empty() );
	      REQUIRE( l2.size() == 5 );
	      REQUIRE( l2.to_string() == "5 9 12 17 26" );
	    }
	}
 	WHEN( "the list is copied to an existing non-empty list" )
	{
	  Sorted_List l2{3};
	  
	  l2.insert(24);
	  l2 = l;
	  
	  THEN( "new list has a copy of original list with five items " )
	    {
	      REQUIRE( !l2.is_empty() );
	      REQUIRE( l2.size() == 5 );
	      REQUIRE( l2.to_string() == "5 9 12 17 26");
	    }
	}
    }
}

SCENARIO( "Lists can be copied" )
{

    GIVEN( "A list with five items in it, and a new copy of that list" )
    {
      Sorted_List l{};
      
      l.insert(9);
      l.insert(4);
      l.insert(56);
      l.insert(19);
      l.insert(34);
      
      Sorted_List l2 {l};
      
      REQUIRE( !l.is_empty() );
      REQUIRE( l.get_first_value() == 4 );
      REQUIRE( l.get_last_value() == 56 );
      REQUIRE( l.size() == 5 );
      
      WHEN( "the original list is changed (removing first item) " )
	{
	  l.remove(4);
	  
	  THEN( "the copy remain unmodified (first item in copy is 5)" )
	    {
	      //Size decrease for l but l2 still has 5 items in it.

		  REQUIRE( l2.get_first_value() == 4 );
		  REQUIRE( !l2.is_empty() );
		  REQUIRE( l2.size() == 5 );
		  REQUIRE( l.size() == 4 );
	    }
	}
	WHEN( "the copied list is changed" )
	{
	  l2.remove(4);
	  
	    THEN( "the original remain unmodified" )
	    {
	      REQUIRE( l.get_first_value() == 4 );
	      REQUIRE( !l.is_empty() );
	      REQUIRE( l.size() == 5 );
	      REQUIRE( l2.size() == 4 );
	    }
	}
    }
}


SCENARIO( "Lists can be heavily used" )
{

    GIVEN( "A list with 1000 random items in it" )
    {
      Sorted_List l{};
      // create the given list with 1000 random items
      std::random_device rd;
      std::uniform_int_distribution<int> uniform(1,1000);
      
      for (int i{0}; i < 1000; ++i)
	{
	  int random { uniform(rd) }; // generate a random number
	  // insert into list
	  l.insert(random);
	}
       WHEN( "the list have 1000 random numbers inserted" )
	{
	  // THEN the list have 1000 items in correct order
	  // (assumes unique inserts or duplicates allowed)
	  THEN( "the list have 1000 items in correct order " )
	    {
	      
	      REQUIRE( l.check_order() == true );
	      REQUIRE( l.size() == 1000 );
	    }
	}

      WHEN( "the list have 1000 random numbers removed" )
	{
	  while(l.size() != 0)
	    {
	      int temp{l.get_first_value()};
	      l.remove(temp);
	    }
	  
	  THEN( "the list have 1000 items in correct order " )
	    {
	      REQUIRE( l.is_empty() );
	      REQUIRE( l.size() == 0 );
	    }
	  // THEN the list is empty
	  // (assumes successful removes)
	}
    }
}

      
Sorted_List trigger_move(Sorted_List l)
{
  // do some (any) modification to list
  
  l.remove(9); /* removes first item in the list */
  return l;
}

SCENARIO( "Lists can be passed to functions" )
{

    GIVEN( "A list with 5 items in it" )
    {

	Sorted_List given{};
	// insert 5 items
	given.insert(76);
	given.insert(9);
	given.insert(199);
	given.insert(41);
	given.insert(12);
	
	WHEN( "the list is passed to trigger_move()" )
	{
	  Sorted_List l{ trigger_move(given) };
	    
	    THEN( "the given list remain and the result have the change" )
	    {
	      REQUIRE( !given.is_empty() );
	      REQUIRE( given.size() == 5 );
	      REQUIRE( given.to_string() == "9 12 41 76 199");

	      REQUIRE( !l.is_empty() );
	      REQUIRE( l.get_first_value() == 12);
	      REQUIRE( l.to_string() == "12 41 76 199" );
	      REQUIRE( l.size() == 4 );
	    }
	}
	WHEN( "the list is moved to a new empty list" )
	{
	  Sorted_List l{};
	  
	  // Test assignment move constructor
	  l = trigger_move(given);
	    
	    THEN( "the given list remain and the result have the change" )
	    {
	      REQUIRE( !given.is_empty() );
	      REQUIRE( given.size() == 5 );
	      REQUIRE( given.to_string() == "9 12 41 76 199");

	      REQUIRE( !l.is_empty() );
	      REQUIRE( l.get_first_value() == 12);
	      REQUIRE( l.to_string() == "12 41 76 199" );
	      REQUIRE( l.size() == 4 );
	    }
	}
    }
}

SCENARIO( "List can be moved to other lists" )
{
  GIVEN( "A list with 5 items in it" )
    {
      Sorted_List l{};
      l.insert(43);
      l.insert(298);
      l.insert(8);
      l.insert(29);
      l.insert(60);

      REQUIRE( l.to_string() == "8 29 43 60 298");
      REQUIRE( l.size() == 5 );
      
      WHEN( "the list is moved to a new list" )
	{
	  Sorted_List l2{ std::move(l) };
	  
	  THEN( "The old list is empty and new list has 5 items" )
	    {
	      REQUIRE( l.is_empty() );
	      REQUIRE( l.size() == 0 );
	      REQUIRE( l2.to_string() == "8 29 43 60 298");
	      REQUIRE( l2.size() == 5 );
	    }
	}

      WHEN( "the list is moved to an existing non-empty list" )
	{
	  Sorted_List l2{4};
	  l2.insert(78);
	  
	  REQUIRE( l2.to_string() == "4 78");
	  REQUIRE( l2.size() == 2 );

	  l2 = std::move(l);
	  
	  THEN( "the new list has five items same as old list and old list is empty" )
	    {
	      REQUIRE( l2.to_string() == "8 29 43 60 298");
	      REQUIRE( l2.size() == 5 );
	      
	      REQUIRE( l.is_empty() );
	      REQUIRE( l.size() == 0 );
	    }
	}



    }
}

// In addition you must of course verify that the list is printed
// correct and that no memory leaks occur during use. You can solve
// the printing part on your own. Here's how to run the (test) program
// when you check for memory leaks:

// You must of course verify that no memory leaks occur during use.
// To do so, an external program must be used to track what memory
// is allocated and free'd, you can run such a program like so:
//
// $ valgrind --tool=memcheck a.out

// Finally you need to check that you can do all operations that make
// sense also on a immutable list (eg all operations but insert):  
void use_const_list(Sorted_List const& l)
{
  // perform every operation that do not modify the list here
  int first_value{};
  int last_value{};
  int some_value{};
  int size{};

  bool order{};
  bool empty{};
  
  std::string str{};

  first_value = l.get_first_value();
  last_value = l.get_last_value();
  some_value = l.get_value(1);
  size = l.size();
  order = l.check_order();
  empty = l.is_empty();
  str = l.to_string();
  
  std::cout << "First item: " << first_value << "\nLast item: "
	    << last_value << "\nMiddle item: " << some_value
	    << "\nList size: " << size << "\nOrder: " << std::boolalpha
	    << order << "\nList is empty? " << empty << "\nList:\n"
	    << str << std::endl;
}

SCENARIO( "list can be passed to functions as const list" )
{
  GIVEN( "A list with 3 item in it" )
    {
      Sorted_List l{};
      l.insert(3);
      l.insert(174);
      l.insert(58);

      REQUIRE( l.size() == 3 );
      REQUIRE( l.to_string() == "3 58 174" );
                  
      WHEN( "List is passet to use_const_list()" )
	{
	  use_const_list(l);
	  
	  THEN( "No error occured and list is still the same" )
	    {
	      REQUIRE( l.size() == 3 );
	      REQUIRE( l.to_string() == "3 58 174" );
	    }
	}

    }
}
// Solve one TEST_CASE or WHEN at a time!
//
// Move this comment and following #if 0 down one case at a time!
// Make sure to close any open braces before this comment.
// The #if 0 will disable the rest of the file.
#if 0


#endif
