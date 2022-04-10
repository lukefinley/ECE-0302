#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "deque.hpp"

// TODO

TEST_CASE( "Tests", "[deque]" ) 
{
    Deque<int> dq;
    REQUIRE(dq.isEmpty());
    dq.pushBack(1);
    dq.pushBack(2);
    dq.pushBack(3);
    dq.pushBack(4);
    REQUIRE(dq.front() == 1);
    REQUIRE(dq.back() == 4);
    REQUIRE(!dq.isEmpty());
    dq.popBack();
    REQUIRE(dq.back() == 3);
    dq.popFront();
    REQUIRE(dq.front() == 2);

    Deque<int> dqx = dq;
    REQUIRE(dqx.front() == 2);
    REQUIRE(dqx.back() == 3);
    dq.popFront();
    dq.popFront();
    REQUIRE(dq.isEmpty());
    REQUIRE(!dqx.isEmpty());
    dq.pushBack(1);
    dq.pushBack(2);
    dq.pushBack(3);
    dq.pushBack(4);
    dqx = dq;
    REQUIRE(dqx.front() == 1);
    REQUIRE(dqx.back() == 4);

    Deque<int> dqy(dq);
    REQUIRE(dqy.front() == 1);
    REQUIRE(dqy.back() == 4);
}
