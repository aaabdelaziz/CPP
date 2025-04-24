// To find a Greater number than a given number
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std::placeholders;

// condition
bool greaterThan(int num, int limit) { return num > limit; }

// function to count greater than value
int countGreaterThan()
{
	int arr[15] = { 1, 5, 8, 9, 10, 3, 12, 6,
					4, 15, 2, 20, 11, 7, 18 };

	// using binding
	return std::count_if(arr,
						arr + sizeof(arr) / sizeof(int),
						std::bind(&greaterThan, _1, 10));   // Bind here will call greater than function
}

// Driver Code
int main()
{
	std::cout << "Number of elements greater than 10: "
			<< countGreaterThan() << std::endl;
	return 0;
}
