#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include <iostream>
#include "bitset.hpp"

// THIS IS JUST AN EXAMPLE
// There should be at least one test per Bitset method

// Will check the size and good methods
TEST_CASE( "Test bitset construction", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());

    Bitset c(16);
    REQUIRE(c.size() == 16);
    REQUIRE(c.good());

    Bitset d("00100000");
    REQUIRE(d.size() == 8);
    REQUIRE(d.good());

    c.set(22);
    REQUIRE(c.good() == false);

    d.set(29);
    REQUIRE(d.good() == false);
}

// Will check the set and test functions
TEST_CASE( "Test bitset values", "[bitset]" ) {
    Bitset b; 
    for (int i = 0; i < 8; i++)
    {
        b.set(i);
        REQUIRE(b.test(i) == true);
    }
    
    Bitset c(16);
    for (int i = 0; i < 16; i++)
    {
        c.set(i);
        REQUIRE(c.test(i) == true);
    }

    Bitset d("00000000");
    for (int i = 0; i < 8; i++)
    {
        d.set(i);
        REQUIRE(d.test(i) == true);
    }
}

// Will check the reset function
TEST_CASE( "Test bitset reset", "[bitset]" ) {
    Bitset b; 
    for (int i = 0; i < 8; i++)
    {
        b.set(i);
        b.reset(i);
        REQUIRE(b.test(i) == false);
    }
    
    Bitset c(16);
    for (int i = 0; i < 16; i++)
    {
        c.set(i);
        c.reset(i);
        REQUIRE(c.test(i) == false);
    }

    Bitset d("11111111");
    for (int i = 0; i < 8; i++)
    {
        d.reset(i);
        REQUIRE(d.test(i) == false);
    }
}

// Will check the toggle function
TEST_CASE( "Test bitset toggle", "[bitset]" ) {
    Bitset b; 
    for (int i = 0; i < 8; i++)
    {
        b.toggle(i);
        REQUIRE(b.test(i) == true);
        b.toggle(i);
        REQUIRE(b.test(i) == false);
    }
    
    Bitset c(16);
    for (int i = 0; i < 16; i++)
    {
        c.toggle(i);
        REQUIRE(c.test(i) == true);
        c.toggle(i);
        REQUIRE(c.test(i) == false);
    }

    Bitset d("00000000");
    for (int i = 0; i < 8; i++)
    {
        d.set(i);
        REQUIRE(d.test(i) == true);
        d.reset(i);
        REQUIRE(d.test(i) == false);
    }
}

// Will test the asString function
TEST_CASE( "Test bitset asString", "[bitset]" ) {

    Bitset b;
    REQUIRE(b.asString() == "00000000");
    b.set(1);
    REQUIRE(b.asString() == "01000000");

    Bitset c(16);
    REQUIRE(c.asString() == "0000000000000000");
    c.set(1);
    REQUIRE(c.asString() == "0100000000000000");

    Bitset d("00100000");
    REQUIRE(d.asString() == "00100000");
}