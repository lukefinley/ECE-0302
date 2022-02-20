#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE( "Test FindPalindrome add a non-allowable word", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
	REQUIRE(b.add("kayak"));
	REQUIRE(b.number() == 1);
	std::vector<std::vector<std::string>> v = b.toVector();
	REQUIRE(v[0][0] == "kayak");
}

TEST_CASE( "Test FindPalindrome add a non unique word", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(b.add("kayak"));
	REQUIRE(b.number() == 1);
	REQUIRE(!b.add("kayak"));
	REQUIRE(b.number() == 1);
}

TEST_CASE( "Test FindPalindrome add a vector", "[FindPalindrome]" )
{
	FindPalindrome b;
	std::vector<std::string> v;
	v.push_back("Do");
	v.push_back("geese");
	v.push_back("see");
	v.push_back("God");
	REQUIRE(b.add(v));
	REQUIRE(b.number() == 1);
}

TEST_CASE( "Test A's", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(b.add("a"));
	REQUIRE(b.add("Aa"));
	REQUIRE(b.add("AaA"));
	REQUIRE(b.number() == 6);
}

TEST_CASE( "Cut tests", "[FindPalindrome]" )
{
	FindPalindrome b;
	std::vector<std::string> v(1);
	std::vector<std::string> v1(1);
	v[0] = "kayak";
	v1[0] = "kayaking";
	REQUIRE(b.cutTest1(v));
	REQUIRE(b.cutTest2(v, v1));
	v[0] = "car";
	v1[0] = "pizza";
	REQUIRE(!b.cutTest1(v));
	REQUIRE(!b.cutTest2(v, v1));
}

TEST_CASE( "Clear", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(b.add("kayak"));
	REQUIRE(b.number() == 1);
	b.clear();
	REQUIRE(b.number() == 0);
	REQUIRE(b.add("flower"));
	REQUIRE(b.number() == 0);
}
