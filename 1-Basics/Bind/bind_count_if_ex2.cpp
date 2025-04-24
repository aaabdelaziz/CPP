// To find the longer words
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

// condition
bool isLongerThan(std::string word, int limit)
{
	return word.length() > limit;
}

// function to count long words
int countLongWords()
{
	std::string words[]
		= { "apple",	 "banana", "cherry", "date",
			"elderberry", "fig", "grape", "honeydew" };

	// using binding function
	return std::count_if(
		words,
		words + (sizeof(words) / sizeof(std::string)),
		std::bind2nd(std::ptr_fun(isLongerThan), 5)); 
}

// Driver Code
int main()
{
	std::cout
		<< "Number of words longer than 5 characters: "
		<< countLongWords() << std::endl;
	return 0;
}
