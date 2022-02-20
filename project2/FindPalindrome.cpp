#include <string>
#include <vector>
#include <iostream>
#include <locale> 
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	locale loc;
	for (unsigned int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i],loc);
	}
}

// Function that returns all strings in a vector as lowercase
static vector<string> getlcVector(const vector<string> & stringVector)
{
	// Create new vector for lowercase strings, equal to input vector
	vector<string> lcVector(stringVector.size());
	lcVector = stringVector;

	// Loop through and convert every string in lc vector to lowercase
	for (unsigned int i = 0; i < lcVector.size(); i++)
		convertToLowerCase(lcVector[i]);
	return lcVector;	// Return the lowercase vector
}

// Function that converts a vector into a long, lowercase string
static string convertVectorToString(const vector<string> & stringVector)
{
	// Declare blank string and lowercase vector
	string total = "";
	vector<string> lc = getlcVector(stringVector);

	// Loop through lowercase vector and add each to large string
	for (unsigned int i = 0; i < lc.size(); i++)
		total += lc[i];
	return total;	// Return the large string
}

// Function that determines if all characters are valid
static bool validWords(const vector<string> & stringVector)
{
	// Convert vector to long string
	string str = convertVectorToString(stringVector);
	// Determine if there is an invalid character
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (!((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)))
			return false;
	}
	return true;
}

// Funciton that determines if new word is absent from vector
static bool isUnique(const vector<string> & stringVector, const string & newStr)
{
	// Convert inputs to lowercase
	vector<string> lc = getlcVector(stringVector);
	string newStr1 = newStr;
	convertToLowerCase(newStr1);
	
	// Loop through vector
	for (unsigned int i = 0; i < lc.size(); i++)
	{
		// If string is in vector, return false
		if(newStr1 == lc[i])
			return false;
	}
	return true;
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	// Base case
	if (currentStringVector.size() == 0 && isPalindrome(convertVectorToString(candidateStringVector)))
	{
		// Add the candidate vector to the vector of dromes if it is a palindrome
		dromes.push_back(candidateStringVector);
		numDromes++;
		return;
	}
	else if (currentStringVector.size() == 0)
		return;
	
	for (unsigned int i = 0; i < currentStringVector.size(); i++)
	{
		// Take element i from current vector and put it in the back of candidate vector
		candidateStringVector.push_back(currentStringVector[i]);
		for (unsigned int j = 0; j < currentStringVector.size() - 1; j++)
		{
			if (j >= i)
				currentStringVector[j] = currentStringVector[j + 1];
		}
		currentStringVector.pop_back();
		
		// If second cut test is passed, call recursive function
		if (cutTest2(candidateStringVector, currentStringVector))
			recursiveFindPalindromes(candidateStringVector, currentStringVector);
		
		// Take last element of candidate vector and place it in position i of current vector
		if (currentStringVector.size() > 0)
		{
			currentStringVector.push_back(currentStringVector[currentStringVector.size() - 1]);
			for (unsigned int j = currentStringVector.size() - 1; j > i; j--)
				currentStringVector[j] = currentStringVector[j - 1];
		}
		currentStringVector[i] = candidateStringVector[candidateStringVector.size() - 1];
		candidateStringVector.pop_back();
	}
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	// Construct variables
	numWords = 0;
	numDromes = 0;
}

FindPalindrome::~FindPalindrome()
{
	clear();
}

int FindPalindrome::number() const
{
	return numDromes;
}

void FindPalindrome::clear()
{
	// Clear all values
	strings.clear();
	dromes.clear();
	numDromes = 0;
	numWords = 0;
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	string str = convertVectorToString(stringVector);
	char c = '0';
	char cno = '0';
	int count = 0;

	// Loops through every character, and assigns it to char c
	for (unsigned int i = 0; i < str.size(); i++)
	{
		count = 0;
		c = str[i];
		// For every char c, loop through the string to find more instances
		for (unsigned int j = 0; j < str.size(); j++)
		{
			// Increment counter if a match is found
			if (str[j] == c)
				count++;
		}
		// If second instance of odd count, or first instance when 
		// string is even or c not in center, return false
		if (count % 2 == 1 && (cno == c || cno == '0') && str.size() % 2 == 1 && str[str.size() / 2] == c)
			cno = c;
		else if (count % 2 == 1 && (cno != c || str.size() % 2 == 0 || str[str.size() / 2] != c))
			return false;
	}
	return true;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1, const vector<string> & stringVector2)
{
	// Convert vectors to strings
	string str1 = convertVectorToString(stringVector1);
	string str2 = convertVectorToString(stringVector2);

	// Check for bigger string
	if (str1.size() > str2.size())
	{
		// Loop through all characters in small string
		for (unsigned int i = 0; i < str2.size(); i++)
		{
			// If character in small is not present in large, return false
			if (str1.find(str2[i]) < 0 || str1.find(str2[i]) > str1.size())
				return false;
		}
	}
	else
	{
		// Loop through all characters in small string
		for (unsigned int i = 0; i < str1.size(); i++)
		{
			// If character in small is not present in large, return false
			if (str2.find(str1[i]) < 0 || str2.find(str1[i]) > str2.size())
				return false;
		}
	}
	return true;
}

bool FindPalindrome::add(const std::string & value)
{
	// Create one word vector
	vector<string> val(1);
	val[0] = value;
	
	// Clear palindrome vector
	dromes.clear();
	numDromes = 0;
	
	// Return false if the word is invalid or not unique
	if (validWords(val) == false || isUnique(strings, value) == false)
		return false;
	else
	{
		strings.push_back(value);	// Add the string to the vector
		numWords++;	// Update number of words
		
		// If cut test 1 is successful, clear the palindromes and chack cases again with new candidate vector
		if (cutTest1(strings))
		{
			dromes.clear();
			numDromes = 0;
			vector<string> candidateVector;
			recursiveFindPalindromes(candidateVector, strings);
		}
	}
	return true;
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	// Loop through vector
	for (unsigned int i = 0; i < stringVector.size(); i++)
	{
		// Return false if a word is invalid or not unique
		if (validWords(stringVector) == false || isUnique(strings, stringVector[i]) == false)
			return false;
	}
	
	// Add the new vector to the original vector
	for (unsigned int i = 0; i < stringVector.size(); i++)
		strings.push_back(stringVector[i]);
	numWords += stringVector.size();	// Update number of words
	
	// If cut test 1 is successful, clear the palindromes and chack cases again
	if (cutTest1(strings))
	{
		dromes.clear();
		numDromes = 0;
		vector<string> candidateVector;
		recursiveFindPalindromes(candidateVector, strings);
	}
	return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// Return the palindromes
	return dromes;
}
