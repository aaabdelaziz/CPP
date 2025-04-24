// To Handle Exceptions
#include <functional>
#include <iostream>

// function created
void myFunction()
{
	std::cout << "This function does something."
			<< std::endl;
}

// Driver Code
int main()
{
	std::function<void()> func;

	// Normal condition
	try {
		func();
	}
	// Exception when binder created
	catch (std::bad_function_call& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
