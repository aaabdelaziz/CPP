//============================================================================
// Name        : DynamicAllocation.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	/* C uses malloc() and calloc() function to allocate memory dynamically at run time
	 *  and uses free() function to free dynamically allocated memory.
	 *  C++ supports these functions and also has two operators new and
	 *  delete that perform the task of allocating and freeing the memory in a better and easier way.*/

	/*The new operator denotes a request for memory allocation on the Heap.
	 * If sufficient memory is available, new operator initializes the memory and returns
	 * the address of the newly allocated and initialized memory to the pointer variable.
	 * */

	/*
	 * Difference between malloc in C and New in C++, is that
	 * https://www.includehelp.com/cpp-tutorial/difference-between-new-and-malloc.aspx
	 *
	 * malloc() is a library function of stdlib.h and it was used in C language
	 * to allocate memory for N blocks at run time, it can also be used in C++
	 * programming language.
	 * Whenever a program needs memory to declare at run time we can use this
	 * function.
	 *
	 *  new--> new is an operator in C++ programming language,
	 *  it is also used to declare memory for N blocks at run time.
	 *  Both are used for same purpose, but still they have some differences,
	 *  the differences are:
	 *  new is an operator whereas malloc() is a library function.
	 *  new allocates memory and calls constructor for object initialization.
	 *  But malloc() allocates memory and does not call constructor.
	 *  Return type of new is exact data type while malloc() returns void*.
	 *  new is faster than malloc() because an operator is always faster than
	 *  a function.
	 * */

    cout<<"Start Example"<<endl;
	// 1-Pointer initialization to null
	//int* v = nullptr;  //NULL in C but here in C++ it`s nullptr
    /*no difference between putting nullptr or NULL for Pointer     */
    //Init Pointer
    int* v = nullptr;
    //You then should allocate in heap
    v=new int;
    *v=8;
	cout<<*v<<endl;


    //2- Pointer Allocation without Init
	char *ptr=new char;
	*ptr='f';
	 cout<<*ptr<<endl;


   /* ------------------------------------- */
	int *vtr = new int[10];
	for(int i=0;i<10;i++){
		vtr[i]=i+5; std::cout<<vtr[i]<<" ";
	}
	cout<<endl;

	/*if enough memory is not available in the heap to allocate,
	 *  the new request indicates failure by throwing an exception of type std::bad_alloc,
	 *   unless “nothrow” is used with the new operator, in which case it returns a NULL pointer*/
	int *h = new(nothrow) int;  // to return nullptr instead of bad alloc
	if (!h)
	{
	   cout << "Memory allocation failed\n";
	}

	// C++ program to illustrate dynamic allocation
	// and deallocation of memory using new and delete

	// Pointer initialization to null
	int* p = NULL;

	// Request memory for the variable
	// using new operator
	p = new(nothrow) int;
	if (!p)
		cout << "allocation of memory failed\n";
	else
	{
		// Store value at allocated address
		*p = 29;
		cout << "Value of p: " << *p << endl;
	}

	// Request block of memory
	// using new operator
	float *r = new float(75.25);

	cout << "Value of r: " << *r << endl;

	// Request block of memory of size n
	int n = 5;
	int *q = new(nothrow) int[n];

	if (!q)
		cout << "allocation of memory failed\n";
	else
	{
		for (int i = 0; i < n; i++)
			q[i] = i+1;

		cout << "Value store in block of memory: ";
		for (int i = 0; i < n; i++)
			cout << q[i] << " ";
	}

	// freed the allocated memory
	delete p;
	delete r;

	// freed the block of allocated memory
	delete[] q;


	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
