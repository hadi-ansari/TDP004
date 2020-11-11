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

//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Create an empty list" ) 
{
    Sorted_List l{};

    REQUIRE( l.is_empty() );
    REQUIRE( l.size() == 0 );
}

// Solve one TEST_CASE or WHEN at a time!
//
// Move this comment and following #if 0 down one case at a time!
// Make sure to close any open braces before this comment.
// The #if 0 will disable the rest of the file.
#if 0

TEST_CASE( "Insert an item in an empty list" ) 
{
    Sorted_List l{};

    l.insert(5);
  
    REQUIRE( l.is_empty() );
    REQUIRE( l.size() == 0 );
  
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

	    // insert an item
      
	    THEN( "the size increase and the item is first in the list" )
	    {
		REQUIRE( l.is_empty()  );
		REQUIRE( l.size() == 0 );
		REQUIRE( /* test that item is first in list */ );
	    }
	}
    
	WHEN( "an item is removed" )
	{

	    // remove an item
      
	    THEN( "the list is still empty" )
	    {
		// add your REQUIRE statements
	    }
	}
    
	WHEN( "the list is copied to a new list" )
	{

	    // copy your list to a new variable (copy constructor)
      
	    THEN( "the new list is also empty" )
	    {
		// add your REQUIRE statements
	    }
	}
    
	WHEN( "the list is copied to an existing non-empty list" )
	{
	    // create and fill a list to act as the existing list
	    // copy (assign) your empty list to the existing
      
	    THEN( "the existing list is also empty" )
	    {
		// add your REQUIRE statements
	    }
      
	}
    }
}

SCENARIO( "Single item lists" )
{

    GIVEN( "A list with one item in it" )
    {

	// create the given scenario
    
	WHEN( "a smaller item is inserted" )
	{
	    THEN( /* describe what will happen */ )
	    {
	    }
	}
	WHEN( "a larger item is inserted" )
	{
	    THEN( /* describe what will happen */ )
	    {
	    }
	}
	WHEN( "an item is removed" )
	{
	    THEN( /* describe what will happen */ )
	    {
	    }
	}
	WHEN( "the list is copied to a new list" )
	{
	    THEN( /* describe what will happen */ )
	    {
	    }
	}
	WHEN( "the list is copied to an existing non-empty list" )
	{
	    THEN( /* describe what will happen */ )
	    {
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
    
	WHEN( "an item smaller than all other is inserted" )
	{
	}
	WHEN( "an item larger than all other is inserted" )
	{
	}
	WHEN( "an item smaller than all but one item is inserted" )
	{
	}
	WHEN( "an item larger than all but one item is inserted" )
	{
	}
	WHEN( "an item is removed" )
	{
	}
	WHEN( "all items are removed" )
	{
	}
	WHEN( "the list is copied to a new list" )
	{
	}
	WHEN( "the list is copied to an existing non-empty list" )
	{
	}
    }
}

SCENARIO( "Lists can be copied" )
{

    GIVEN( "A list with five items in it, and a new copy of that list" )
    {

	WHEN( "the original list is changed" )
	{
	    THEN( "the copy remain unmodified" )
	    {
	    }
	}

	WHEN( "the copied list is changed" )
	{
	    THEN( "the original remain unmodified" )
	    {
	    }
	}
    }
}

SCENARIO( "Lists can be heavily used" )
{

    GIVEN( "A list with 1000 random items in it" )
    {
    
	// create the given list with 1000 random items
	std::random_device rd;
	std::uniform_int_distribution<int> uniform(1,1000);
    
	for (int i{0}; i < 1000; ++i)
	{
	    int random { uniform(rd) }; // generate a random number
	    // insert into list
	}
    
	WHEN( "the list have 1000 random numbers inserted" )
	{
	    // THEN the list have 2000 items in correct order
	    // (assumes unique inserts or duplicates allowed)
	}

	WHEN( "the list have 2000 random numbers removed" )
	{
	    // THEN the list is empty
	    // (assumes successful removes)
	}
    }
}

Sorted_List trigger_move(Sorted_List l)
{
    // do some (any) modification to list
    return l;
}

SCENARIO( "Lists can be passed to functions" )
{

    GIVEN( "A list with 5 items in it" )
    {

	Sorted_List given{};
	// insert 5 items
  
	WHEN( "the list is passed to trigger_move()" )
	{

	    Sorted_List l{ trigger_move(given) };
      
	    THEN( "the given list remain and the result have the change" )
	    {
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
    return l;
}

#endif
