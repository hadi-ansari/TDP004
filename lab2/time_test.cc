#include "catch.hpp"
#include "Time.h"
// här lägger ni era testfall. 
// Jobba enligt TDD; 
//  1. Lägg till testfall
//  2. Testa
//  3. Lägg till (minsta möjliga) implementation
//  4. Testa alla testfall
//  5. Refaktorera (skriv om) så att allt ser bra ut

TEST_CASE( "Test constructor" )
{
  Time t{12, 10, 16};
  REQUIRE( t.get_hour() == 12);
}
TEST_CASE("TEST2")
{
  Time t{12, 10, 16};
  REQUIRE( t.get_minute() == 10);
}

TEST_CASE( "Hour validity test" )
{
  Time t1{24, 0, 0};
  REQUIRE( t1.is_valid() == false );
}
TEST_CASE( "Minute validity test" )
{
  Time t1{12, 61, 59};
  REQUIRE( t1.is_valid() == false );
}
TEST_CASE( "Second validity test" )
{
  Time t1{6, 37, 78};
  REQUIRE( t1.is_valid() == false );
}

TEST_CASE( " Am/pm format test1" )
{
  Time t1{11, 37, 23};
  REQUIRE( t1.to_string(false) == "11:37:23 am" );
}
TEST_CASE( "Am/pm format test2" )
{
  Time t1{15, 0, 4};
  REQUIRE( t1.to_string(false) == "03:00:04 pm" );
}
TEST_CASE( "Am/pm format test3" )
{
  Time t1{12, 0, 0};
  REQUIRE( t1.to_string(false) == "12:00:00 pm" );
}
TEST_CASE( "24 format test1" )
{
  Time t1{15, 0, 4};
  REQUIRE( t1.to_string(true) == "15:00:04" );
}
TEST_CASE( "24 format test2" )
{
  Time t1{1, 1, 0};
  REQUIRE( t1.to_string(true) == "01:01:00" );
}
TEST_CASE( "Operator+ test1" )
{
  Time t1{13, 59, 0};
  Time t2{t1 + 5};
  REQUIRE( t2.to_string(false) == "01:59:05 pm" );
}
TEST_CASE( "Operator+ test2" )
{
  Time t1{1, 3, 55};
  Time t2{t1 + 20};
  REQUIRE( t2.to_string(false) == "01:04:15 am" );
}
TEST_CASE( "Operator+ test3" )
{
  Time t1{12, 3, 0};
  Time t2{t1 + 100};
  REQUIRE( t2.to_string(false) == "12:04:40 pm" );
}

TEST_CASE( "Increment test1" )
{
  Time t1{15, 10, 14};
  ++t1;
  REQUIRE( t1.to_string(true) == "15:10:15" );
}
TEST_CASE( "Increment test2" )
{
  Time t1{23, 59, 59};
  ++t1;
  REQUIRE( t1.to_string(false) == "00:00:00 am" );
}
TEST_CASE( "Increment test3" )
{
  Time t1{23, 59, 59};
  ++t1;
  ++t1;
  REQUIRE( t1.to_string(false) == "00:00:01 am" );
}
