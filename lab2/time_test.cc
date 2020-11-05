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
TEST_CASE( "Minute test" )
{
  Time t1{23, 59, 59};
  Time t2{t1 + 1};
  REQUIRE( t2.get_string() == "23:59:60");
}


