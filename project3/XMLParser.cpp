// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser()
{
	elementNameBag = new Bag<string>;
	parseStack = new Stack<string>;
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
	clear();
	delete elementNameBag;
	elementNameBag = nullptr;
	delete parseStack;
	parseStack = nullptr;
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	string str;	// Declare temporary string to add to token structure
	TokenStruct t;	// Declare tempotary token structure to add to token vector
	bool declToggle = false;	// Declare toggle for declaration token type
	
	// Loop through entire string
	for (unsigned int i = 0; i < inputString.size(); i++)
	{
		// If first value is >, return false
		if (inputString[i] == '>')
		{
			tokenizedInputVector.clear();
			return false;
		}
		
		// If the next markup is a tag
		if (inputString[i] == '<')
		{
			// If there was content recorded previously, add it to the vector
			if (str.size() > 0)
			{
				t.tokenString = str;
				t.tokenType = CONTENT;
				tokenizedInputVector.push_back(t);
				str = "";	// clear string
			}
			t.tokenType = START_TAG;	// Set type to start tag as a default
			
			// Loop through remaining contents of tag
			while (inputString[i] != '>')
			{
				i++;	// increment i
				
				// Return false if no closing >
				if (i == inputString.size())
				{
					tokenizedInputVector.clear();
					return false;
				}
				
				// Return false if another < is before >
				if (inputString[i] == '<')
				{
					tokenizedInputVector.clear();
					return false;
				}
				
				// Set token types, or build string
				if (inputString[i] == '/' && inputString[i - 1] == '<')
					t.tokenType = END_TAG;
				else if (inputString[i] == '/' && i < (inputString.size() - 1) && inputString[i + 1] == '>')
					t.tokenType = EMPTY_TAG;
				else if (inputString[i] == '?' && inputString[i - 1] == '<')
					declToggle = true;
				else if (inputString[i] == '?' && i < (inputString.size() - 1) && inputString[i + 1] == '>' && declToggle == true)
					t.tokenType = DECLARATION;
				else if (inputString[i] == '>')
					break;
				else
					str += inputString[i];
			}
			t.tokenString = str;	// Add str to token structure
			str = "";	// clear string
			tokenizedInputVector.push_back(t);	// Add token structure to vector
		}
		
		// If the next markup is not a tag, build string content
		else
			str += inputString[i];
	}
	
	return true;
}  // end

// TODO: Implement a helper function to delete attributes from a START_TAG
// or EMPTY_TAG string (you can change this...)
static std::string deleteAttributes(std::string input)
{
	string temp;	// Declare temporary string variable
	
	// Loop through all letters in the string
	for (unsigned int i = 0; i < input.size(); i++)
	{
		// If whitespace not detected, build string. Otherwise, return string
		if (input[i] != ' ')
			temp += input[i];
		else
			return temp;
	}
	
	return temp;	// Return temporary string
}

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	string name;	// Declare variable to hold the name
	string whiteFront, whiteBack; // Declare variables to hold whitespace
	int k = 0;	// Declare counter variable
	
	// Return false if the vector is empty
	if (tokenizedInputVector.size() == 0)
		return false;
		
	// Check if content is at front of vector
	if ((tokenizedInputVector[0]).tokenType == CONTENT)
	{
		whiteFront = (tokenizedInputVector[0]).tokenString;	// Get front string
		
		// Return false if front content is not whitespace
		for (unsigned int i = 0; i < whiteFront.size(); i++)
		{
			if (whiteFront[i] != ' ')
				return false;
		}
		
		tokenizedInputVector.erase(tokenizedInputVector.begin());	// Delete whitespace
	}
	
	// Check if content is at the end of vector
	if ((tokenizedInputVector[tokenizedInputVector.size() - 1]).tokenType == CONTENT)
	{
		whiteBack = (tokenizedInputVector[tokenizedInputVector.size() - 1]).tokenString;	// Get back string
		
		// Return false if back content is not whitespace
		for (unsigned int i = 0; i < whiteBack.size(); i++)
		{
			if (whiteBack[i] != ' ')
				return false;
		}
		
		tokenizedInputVector.pop_back();	// Delete whitespace
	}
	
	// Return false if the vector does not end with a tag
	if ((tokenizedInputVector[tokenizedInputVector.size() - 1]).tokenType != END_TAG)
		return false;
		
	// Get index of first non-declaration tag
	while ((tokenizedInputVector[k]).tokenType == DECLARATION)	
		k++;
	
	// Return false if the vector does not start with a start tag
	if ((tokenizedInputVector[k]).tokenType != START_TAG)
		return false;
		
	// Return false if not contained within one element
	if (deleteAttributes((tokenizedInputVector[k]).tokenString) != (tokenizedInputVector[tokenizedInputVector.size() - 1]).tokenString)
		return false;
	
	// Loop through vector
	for (unsigned int i = 0; i < tokenizedInputVector.size(); i++)
	{
		// Delete attributes if type is start or empty
		if ((tokenizedInputVector[i]).tokenType == START_TAG || (tokenizedInputVector[i]).tokenType == EMPTY_TAG)
			name = deleteAttributes((tokenizedInputVector[i]).tokenString);
			
		// Get name if type is end
		else if ((tokenizedInputVector[i]).tokenType == END_TAG)
			name = (tokenizedInputVector[i]).tokenString;
			
		elementNameBag->add(name);	// Add name to bag
			
		// Loop through name string to error check
		for (unsigned int j = 0; j < name.size(); j++)
		{
			// If character is invalid, return false
			if ((name[j] >= 33 && name[j] <= 44) || name[j] == 47 || (name[j] >= 59 && name[j] <= 64) || (name[j] >= 91 && name[j] <= 94) || name[j] == 96 || (name[j] >= 123 && name[j] <= 126))
			{
				elementNameBag->clear();
				return false;
			}
				
			// If initial character is invalid, return false
			else if (j == 0 && (name[j] >= 44 && name[j] <= 57))
			{
				elementNameBag->clear();
				return false;
			}
				
			// If whitespace is detected in the end tag, return false
			else if ((tokenizedInputVector[i]).tokenType == END_TAG && name[j] == ' ')
			{
				elementNameBag->clear();
				return false;
			}
		}
		
		// Push name into stack if start tag
		if ((tokenizedInputVector[i]).tokenType == START_TAG)
			parseStack->push(name);
		
		// If end tag does not match name at top of stack, return false
		if ((tokenizedInputVector[i]).tokenType == END_TAG && parseStack->peek() != name)
		{
			elementNameBag->clear();
			return false;
		}
			
		// If end tag matches name at top of stack, pop the stack
		else if ((tokenizedInputVector[i]).tokenType == END_TAG && parseStack->peek() == name)
			parseStack->pop();
	}
	
	// If the stack is not empty, return false
	if (parseStack->isEmpty() == false)
	{
		elementNameBag->clear();
		return false;
	}
	
	return true;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
	elementNameBag->clear();
	parseStack->clear();
	tokenizedInputVector.clear();
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	// If both tests are valid, return if element is in bag
	if (tokenizedInputVector.size() > 0 && elementNameBag->isEmpty() == false)
		return elementNameBag->contains(inputString);
	
	return false;
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	// If both tests are valid, return how many elements are in bag
	if (tokenizedInputVector.size() > 0 && elementNameBag->isEmpty() == false)
		return elementNameBag->getFrequencyOf(inputString);
	
	return 0;
}

