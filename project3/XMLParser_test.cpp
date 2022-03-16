#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include <iostream>
#include "catch.hpp"
#include "XMLParser.hpp"

using namespace std;

// TODO Implement tests of your Stack class and XMLParser class here

TEST_CASE( "Test Bag add", "[XMLParser]" )
{
	   INFO("Hint: testing Bag add()");
		// Create a Bag to hold ints
		Bag<int> intBag;
		int testSize = 2;
		int bagSize;
		bool success;
		for (int i=0; i<testSize; i++) {
			success = intBag.add(i);
			REQUIRE(success);
			bagSize = intBag.size();
			success = (bagSize == (i+1));
			REQUIRE(success);
		}
}

TEST_CASE( "Test Stack push", "[XMLParser]" )
{
	   INFO("Hint: testing Stack push()");
		// Create a Stack to hold ints
		Stack<int> intStack;
		int testSize = 3;
		int stackSize;
		bool success;
		for (int i=0; i<testSize; i++) {
			success = intStack.push(i);
			REQUIRE(success);
			stackSize = intStack.size();
			success = (stackSize == (i+1));
			REQUIRE(success);
		}
		intStack.pop();
		REQUIRE(intStack.size() == 2);
}

TEST_CASE( "Test Stack", "[XMLParser]" )
{
		// Create a Stack to hold ints
		Stack<int> intStack;
		intStack.push(1);
		REQUIRE(intStack.peek() == 1);
		intStack.clear();
		REQUIRE(intStack.isEmpty());
}

TEST_CASE( "Test XMLParser tokenizeInputString", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test>stuff</test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		std::vector<TokenStruct> v;
		TokenStruct t;
		t.tokenString = "test";
		t.tokenType = START_TAG;
		v.push_back(t);
		t.tokenString = "stuff";
		t.tokenType = CONTENT;
		v.push_back(t);
		t.tokenString = "test";
		t.tokenType = END_TAG;
		v.push_back(t);
		std::vector<TokenStruct> v1 = myXMLParser.returnTokenizedInput();
		for (int i = 0; i < 3; i++)
		{
			REQUIRE(v[i].tokenType == v1[i].tokenType);
			REQUIRE(v[i].tokenString == v1[i].tokenString);
		}
		success = myXMLParser.parseTokenizedInput();
		REQUIRE(success);
}

TEST_CASE( "Test XMLParser", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<?xml version?><test>stuff</test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		success = myXMLParser.parseTokenizedInput();
		REQUIRE(success);
}

TEST_CASE( "Test XMLParser 2", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test>stuff</test>>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(!success);
}

TEST_CASE( "Test XMLParser 3", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "     <?xml version?><test>stuff</test>    ";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		success = myXMLParser.parseTokenizedInput();
		REQUIRE(success);
}

TEST_CASE( "Test XMLParser 4", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test>stuff<noggin></noggin></test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		success = myXMLParser.parseTokenizedInput();
		REQUIRE(success);
}

TEST_CASE( "Test XMLParser 5", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test>stuff<noggin></noggin><borneo></borneo></test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		success = myXMLParser.parseTokenizedInput();
		REQUIRE(success);
}

TEST_CASE( "Test XMLParser 6", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test>stuff<noggin><borneo></borneo></noggin></test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		success = myXMLParser.parseTokenizedInput();
		REQUIRE(success);
}

TEST_CASE( "Test XMLParser 7", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test><borneo><noggin></borneo></noggin></test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		success = myXMLParser.parseTokenizedInput();
		REQUIRE(!success);
}

TEST_CASE( "Test XMLParser 8", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test lofts></test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		success = myXMLParser.parseTokenizedInput();
		REQUIRE(success);
		REQUIRE(myXMLParser.containsElementName("test"));
		REQUIRE(myXMLParser.frequencyElementName("test") == 2);
		myXMLParser.clear();
		REQUIRE(myXMLParser.frequencyElementName("test") == 0);
}

TEST_CASE( "Test XMLParser 9", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<t&est lofts></t&est>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		success = myXMLParser.parseTokenizedInput();
		REQUIRE(!success);
}

TEST_CASE( "Test XMLParser 10", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test lofts></Test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		success = myXMLParser.parseTokenizedInput();
		REQUIRE(!success);
}