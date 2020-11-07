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
// Time validity tests
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
TEST_CASE( "Negativ value for second" )
{
  Time t1{23, 19, -1};
  REQUIRE( t1.is_valid() == false );
}
TEST_CASE( "Negativ value for minute" )
{
  Time t1{2, -33, 55};
  REQUIRE( t1.is_valid() == false );
}
TEST_CASE( "Negativ value for hour" )
{
  Time t1{-12, 13, 32};
  REQUIRE( t1.is_valid() == false );
}
// 24 and am/pm tests 
TEST_CASE( " Am/pm format test1" )
{
  Time t1{11, 37, 23};
  REQUIRE( t1.to_string() == "11:37:23 am" );
}
TEST_CASE( "Am/pm format test2" )
{
  Time t1{15, 0, 4};
  REQUIRE( t1.to_string() == "03:00:04 pm" );
}
TEST_CASE( "Am/pm format test3" )
{
  Time t1{12, 0, 0};
  REQUIRE( t1.to_string() == "12:00:00 pm" );
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
  REQUIRE( t2.to_string() == "01:59:05 pm" );
}
TEST_CASE( "Operator+ test2" )
{
  Time t1{1, 3, 55};
  Time t2{t1 + 20};
  REQUIRE( t2.to_string() == "01:04:15 am" );
}
TEST_CASE( "Operator+ test3" )
{
  Time t1{12, 3, 0};
  Time t2{t1 + 100};
  REQUIRE( t2.to_string() == "12:04:40 pm" );
}

TEST_CASE( "Operator- test1" )
{
  Time t1{13, 23, 55};
  Time t2{t1 - 1};
  REQUIRE( t2.to_string() == "01:23:54 pm" );
}
TEST_CASE( "Operator- test2" )
{
  Time t1{9, 13, 0};
  Time t2{t1 - 1};
  REQUIRE( t2.to_string() == "09:12:59 am" );
}
TEST_CASE( "Operator- test3" )
{
  Time t1{9, 0, 0};
  Time t2{t1 - 1};
  REQUIRE( t2.to_string() == "08:59:59 am" );
}
TEST_CASE( "Operator- test4" )
{
  Time t1{0, 0, 0};
  Time t2{t1 - 1};
  REQUIRE( t2.to_string() == "11:59:59 pm" );
}

TEST_CASE( "Increment prefix test1" )
{
  Time t1{15, 10, 14};
  ++t1;
  REQUIRE( t1.to_string(true) == "15:10:15" );
}
TEST_CASE( "Increment prefix test2" )
{
  Time t1{23, 59, 59};
  ++t1;
  REQUIRE( t1.to_string() == "00:00:00 am" );
}
TEST_CASE( "Increment prefix test3" )
{
  Time t1{23, 59, 59};
  ++t1;
  ++t1;
  REQUIRE( t1.to_string() == "00:00:01 am" );
}
TEST_CASE( "Increment postfix test1" )
{
  Time t1{12, 6, 23};
  t1++;
  REQUIRE( t1.to_string(true) == "12:06:24" );
}
TEST_CASE( "Increment postfix test2" )
{
  Time t1{12, 6, 23};
  Time t2{t1++};
  REQUIRE( t2.to_string(true) == "12:06:24" );
}
