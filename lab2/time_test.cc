#include <iostream> 

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
  REQUIRE( t1.to_string() == "15:00:04" );
}
TEST_CASE( "24 format test2" )
{
  Time t1{1, 1, 0};
  REQUIRE( t1.to_string() == "01:01:00" );
}
TEST_CASE( "Operator+ test1" )
{
  Time t1{13, 59, 0};
  Time t2{t1 + 5};
  REQUIRE( t2.to_string() == "13:59:05" );
}
TEST_CASE( "Operator+ test2" )
{
  Time t1{1, 3, 55};
  Time t2{t1 + 20};
  REQUIRE( t2.to_string() == "01:04:15" );
}
TEST_CASE( "Operator+ test3" )
{
  Time t1{12, 3, 0};
  Time t2{t1 + 100};
  REQUIRE( t2.to_string() == "12:04:40" );
}

TEST_CASE( "Operator- test1" )
{
  Time t1{13, 23, 55};
  Time t2{t1 - 1};
  REQUIRE( t2.to_string() == "13:23:54" );
}
TEST_CASE( "Operator- test2" )
{
  Time t1{9, 13, 0};
  Time t2{t1 - 1};
  REQUIRE( t2.to_string() == "09:12:59" );
}
TEST_CASE( "Operator- test3" )
{
  Time t1{9, 0, 0};
  Time t2{t1 - 1};
  REQUIRE( t2.to_string() == "08:59:59" );
}
TEST_CASE( "Operator- test4" )
{
  Time t1{0, 0, 0};
  Time t2{t1 - 1};
  REQUIRE( t2.to_string() == "23:59:59" );
}

TEST_CASE( "Increment prefix test1" )
{
  Time t1{15, 10, 14};
  ++t1;
  REQUIRE( t1.to_string() == "15:10:15" );
}
TEST_CASE( "Increment prefix test2" )
{
  Time t1{23, 59, 59};
  ++t1;
  REQUIRE( t1.to_string() == "00:00:00" );
}
TEST_CASE( "Increment prefix test3" )
{
  Time t1{23, 59, 59};
  ++t1;
  ++t1;
  REQUIRE( t1.to_string() == "00:00:01" );
}
TEST_CASE( "Increment postfix test1" )
{
  Time t1{12, 6, 23};
  t1++;
  REQUIRE( t1.to_string() == "12:06:24" );
}
TEST_CASE( "Increment postfix test2" )
{
  Time t1{12, 6, 23};
  Time t2{t1++};
  REQUIRE( t2.to_string() == "12:06:23" );
}
TEST_CASE( "Decrement prefix test1" )
{
  Time t1{21, 32, 3};
  --t1;
  REQUIRE( t1.to_string() == "21:32:02" );
}
TEST_CASE( "Decrement prefix test2" )
{
  Time t1{21, 32, 21};
  Time t2{--t1};
  REQUIRE( t2.to_string() == "21:32:20" );
}
TEST_CASE( "Decrement postfix test1" )
{
  Time t1{00, 10, 1};
  t1--;
  REQUIRE( t1.to_string() == "00:10:00" );
}
TEST_CASE( "Decrement postfix test2" )
{
  Time t1{00, 10, 1};
  Time t2{t1--};
  REQUIRE( t2.to_string() == "00:10:01" );
}

TEST_CASE( "Comparison test1" )
{
  Time t1{0, 0, 1};
  Time t2{12, 30, 40};
  REQUIRE( (t1 > t2) == false );
}
TEST_CASE( "Comparison test2" )
{
  Time t1{12, 32, 59};
  Time t2{12, 31, 59};
  REQUIRE( (t1 > t2) == true );
}
TEST_CASE( "Comparison test3" )
{
  Time t1{23, 2, 49};
  Time t2{22, 50, 56};
  REQUIRE( (t1 < t2) == false );
}
TEST_CASE( "Comparison test4" )
{
  Time t1{0, 0, 0};
  Time t2{0, 0, 1};
  REQUIRE( (t1 < t2) == true );
}
TEST_CASE( "Comparison test5" )
{
  Time t1{23, 57, 46};
  Time t2{20, 57, 46};
  REQUIRE( (t1 != t2) == true );
}
TEST_CASE( "Comparison test6" )
{
  Time t1{20, 7, 6};
  Time t2{20, 7, 6};
  REQUIRE( (t1 != t2) == false );
}
TEST_CASE( "Comparison test7" )
{
  Time t1{2, 17, 21};
  Time t2{16, 5, 23};
  REQUIRE( (t1 == t2) == false );
}
TEST_CASE( "Comparison test8" )
{
  Time t1{14, 1, 31};
  Time t2{14, 1, 31};
  REQUIRE( (t1 == t2) == true );
}
// How to test iostream operators????
// TEST_CASE( "Ostream test1" )
// {
//   Time t1{17, 50, 28};
//   std::cout << t1 << std::endl;
//   REQUIRE( true );
// }
// TEST_CASE( "Istream test1" )
// {
//   Time t1{};
//   std::cin >> t1;
//   REQUIRE( true );
// }
