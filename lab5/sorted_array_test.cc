#include "catch.hpp"

#include "sorted_array.h"

#include <sstream>
#include <string>


TEST_CASE("Less test1 int")
{
  Less <int> c1{};
  CHECK (c1.compare(2, 3) == true);
  
}
// TEST_CASE("Less test2 double")
// {
//   Less <double> c1{1.2, 15.5};
//   CHECK (c1.compare() == true);
  
// }
// TEST_CASE("Less test2 string")
// {
//   Less <std::string> c1{"bb", "aa"};
//   CHECK (c1.compare() == false);
// }
TEST_CASE("default initialization int")
{
  sorted_array <int> a;
  CHECK (a.size() == 0);
  CHECK_THROWS (a.at(0));
  CHECK_THROWS (a.erase(0));
  CHECK_THROWS (a.erase(-5));
  CHECK_THROWS (a.erase(5));
}
TEST_CASE("default initialization double")
{
  sorted_array <double> a;
  CHECK (a.size() == 0);
  CHECK_THROWS (a.at(0));
  CHECK_THROWS (a.erase(0));
  CHECK_THROWS (a.erase(-5));
  CHECK_THROWS (a.erase(5));
}

TEST_CASE("default initialization std::string")
{
  sorted_array <std::string> a;
  CHECK (a.size() == 0);
  CHECK_THROWS (a.at(0));
  CHECK_THROWS (a.erase(0));
  CHECK_THROWS (a.erase(-5));
  CHECK_THROWS (a.erase(5));
}

TEST_CASE("insertion int")
{
  sorted_array <int> a;
  a.insert(5);
  CHECK (a.size() == 1);
  CHECK (a.at(0) == 5);
  CHECK (a[0] == 5);

  a.insert(10);
  CHECK (a.size() == 2);
  CHECK (a[0] == 5);
  CHECK (a[1] == 10);
}


TEST_CASE("insertion double")
{
  sorted_array <double> a;
  a.insert(5.4);
  CHECK (a.size() == 1);
  CHECK (a.at(0) == 5.4);
  CHECK (a[0] == 5.4);

  a.insert(1.4);
  CHECK (a.size() == 2);
  CHECK (a[0] == 1.4);
  CHECK (a[1] == 5.4);
}


TEST_CASE("insertion string")
{
  sorted_array <string> a;
  a.insert("aaa");
  CHECK (a.size() == 1);
  CHECK (a.at(0) == "aaa");
  CHECK (a[0] == "aaa");

  a.insert("bb");
  CHECK (a.size() == 2);
  CHECK (a[0] == "aaa" );
  CHECK (a[1] == "bb");
}

TEST_CASE("initialization int")
{
  sorted_array <int>  a{17, 9, 5, 2, -100};
    CHECK (a.size() == 5);
    CHECK (a[0] == -100);
    CHECK (a[1] == 2);
    CHECK (a[2] == 5);
    CHECK (a[3] == 9);
    CHECK (a[4] == 17);

    a.insert(1);
    CHECK (a.size() == 6);
    CHECK (a[0] == -100);
    CHECK (a[1] == 1);
    CHECK (a[2] == 2);
    CHECK (a[3] == 5);
    CHECK (a[4] == 9);
    CHECK (a[5] == 17);

    a.erase(5);
    CHECK (a.size() == 5);
    CHECK (a[0] == -100);
    CHECK (a[1] == 1);
    CHECK (a[2] == 2);
    CHECK (a[3] == 5);
    CHECK (a[4] == 9);

    CHECK_THROWS(a.erase(5));

    a.erase(2);
    CHECK (a.size() == 4);
    CHECK (a[0] == -100);
    CHECK (a[1] == 1);
    CHECK (a[2] == 5);
    CHECK (a[3] == 9);
}

TEST_CASE("initialization double")
{
  sorted_array <double>  a{17.6, 9.8, 5.00, 12.89, -100.0};
    CHECK (a.size() == 5);
    CHECK (a[0] == -100);
    CHECK (a[1] == 5);
    CHECK (a[2] == 9.8);
    CHECK (a[3] == 12.89);
    CHECK (a[4] == 17.6);

    a.insert(1.3);
    CHECK (a.size() == 6);
    CHECK (a[0] == -100);
    CHECK (a[1] == 1.3);
    CHECK (a[2] == 5);
    CHECK (a[3] == 9.8);
    CHECK (a[4] == 12.89);
    CHECK (a[5] == 17.6);

    a.erase(5);
    CHECK (a.size() == 5);
    CHECK (a[0] == -100);
    CHECK (a[1] == 1.3);
    CHECK (a[2] == 5);
    CHECK (a[3] == 9.8);
    CHECK (a[4] == 12.89);

    CHECK_THROWS(a.erase(5));

    a.erase(2);
    CHECK (a.size() == 4);
    CHECK (a[0] == -100);
    CHECK (a[1] == 1.3);
    CHECK (a[2] == 9.8);
    CHECK (a[3] == 12.89);
}

TEST_CASE("initialization string")
{
  sorted_array <string>  a{"aaa", "bbb", "ccc", "ddd", "eee"};
    CHECK (a.size() == 5);
    CHECK (a[0] == "aaa");
    CHECK (a[1] == "bbb");
    CHECK (a[2] == "ccc");
    CHECK (a[3] == "ddd");
    CHECK (a[4] == "eee");

    a.insert("fff");
    CHECK (a.size() == 6);
    CHECK (a[0] == "aaa");
    CHECK (a[1] == "bbb");
    CHECK (a[2] == "ccc");
    CHECK (a[3] == "ddd");
    CHECK (a[4] == "eee");
    CHECK (a[5] == "fff");

    a.erase(5);
    CHECK (a.size() == 5);
    CHECK (a[0] == "aaa");
    CHECK (a[1] == "bbb");
    CHECK (a[2] == "ccc");
    CHECK (a[3] == "ddd");
    CHECK (a[4] == "eee");

    CHECK_THROWS(a.erase(5));

    a.erase(2);
    CHECK (a.size() == 4);
    CHECK (a[0] == "aaa");
    CHECK (a[1] == "bbb");
    CHECK (a[2] == "ddd");
    CHECK (a[3] == "eee");
}

TEST_CASE("const array int")
{
  sorted_array<int> const a{1, 2, 3, 4, 5};

  CHECK (a.size() == 5);
  CHECK (a[0] == 1);
  CHECK (a[0] == a.at(0));
  CHECK (a[1] == 2);
  CHECK (a[1] == a.at(1));
  CHECK (a[2] == 3);
  CHECK (a[2] == a.at(2));
  CHECK (a[3] == 4);
  CHECK (a[3] == a.at(3));
  CHECK (a[4] == 5);
  CHECK (a[4] == a.at(4));
  CHECK_THROWS (a.at(5));
}

TEST_CASE("const array double")
{
  sorted_array<double> const a{1.5, 2.8, 3.6, 4.9, 5.3};

  CHECK (a.size() == 5);
  CHECK (a[0] == 1.5);
  CHECK (a[0] == a.at(0));
  CHECK (a[1] == 2.8);
  CHECK (a[1] == a.at(1));
  CHECK (a[2] == 3.6);
  CHECK (a[2] == a.at(2));
  CHECK (a[3] == 4.9);
  CHECK (a[3] == a.at(3));
  CHECK (a[4] == 5.3);
  CHECK (a[4] == a.at(4));
  CHECK_THROWS (a.at(5));
}

TEST_CASE("const array string")
{
  sorted_array<string> const a{"aaa", "bbb", "ccc", "ddd", "eee"};

  CHECK (a.size() == 5);
  CHECK (a[0] == "aaa");
  CHECK (a[0] == a.at(0));
  CHECK (a[1] == "bbb");
  CHECK (a[1] == a.at(1));
  CHECK (a[2] == "ccc");
  CHECK (a[2] == a.at(2));
  CHECK (a[3] == "ddd");
  CHECK (a[3] == a.at(3));
  CHECK (a[4] == "eee");
  CHECK (a[4] == a.at(4));
  CHECK_THROWS (a.at(5));
}

// TEST_CASE("print empty int")
// {
//     std::ostringstream oss;
//     sorted_array <int> empty;
//     oss << empty;
//     CHECK (oss.str() == "{}");
// }

// TEST_CASE("print empty double")
// {
//     std::ostringstream oss;
//     sorted_array <double> empty;
//     oss << empty;
//     CHECK (oss.str() == "{}");
// }

// TEST_CASE("print empty stringe")
// {
//     std::ostringstream oss;
//     sorted_array <string> empty;
//     oss << empty;
//     CHECK (oss.str() == "{}");
// }

// TEST_CASE("print int")
// {
//     std::ostringstream oss;
//     sorted_array <int> array{2, 3, 5, 7, 11, 13};
//     oss << array;
//     CHECK (oss.str() == "{2, 3, 5, 7, 11, 13}");
// }

// TEST_CASE("print double")
// {
//     std::ostringstream oss;
//     sorted_array <double> array{2.2, 3.6, 5.0, 7.2, 11.12, 13.03};
//     oss << array;
//     CHECK (oss.str() == "{2.2, 3.6, 5, 7.2, 11.12, 13.03}");
// }
// TEST_CASE("print string")
// {
//     std::ostringstream oss;
//     sorted_array <string> array{"aa", "bb", "cc", "dd", "ee"};
//     oss << array;
//     CHECK (oss.str() == "{aa, bb, cc, dd, ee}");
// }

