
#include <iostream>
using namespace std;

int main() 
{

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
	 *   unless �nothrow� is used with the new operator, in which case it returns a NULL pointer*/
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

	return 0;
}
