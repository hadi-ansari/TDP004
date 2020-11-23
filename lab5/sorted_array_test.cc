#include "catch.hpp"

#include "sorted_array.h"

#include <sstream>

TEST_CASE("default initialization")
{
    sorted_array a;
    CHECK (a.size() == 0);
    CHECK_THROWS (a.at(0));
    CHECK_THROWS (a.erase(0));
    CHECK_THROWS (a.erase(-5));
    CHECK_THROWS (a.erase(5));
}

TEST_CASE("insertion")
{
    sorted_array a;
    a.insert(5);
    CHECK (a.size() == 1);
    CHECK (a.at(0) == 5);
    CHECK (a[0] == 5);

    a.insert(1);
    CHECK (a.size() == 2);
    CHECK (a[0] == 1);
    CHECK (a[1] == 5);
}

TEST_CASE("initialization")
{
    sorted_array a{17, 9, 5, 2, -100};
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

TEST_CASE("const array")
{
    sorted_array const a{1, 2, 3, 4, 5};

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

TEST_CASE("print empty")
{
    std::ostringstream oss;
    sorted_array empty;
    oss << empty;
    CHECK (oss.str() == "{}");
}

TEST_CASE("print")
{
    std::ostringstream oss;
    sorted_array array{2, 3, 5, 7, 11, 13};
    oss << array;
    CHECK (oss.str() == "{2, 3, 5, 7, 11, 13}");
}
