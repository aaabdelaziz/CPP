
#include <iostream>
#include<vector>
using namespace std;

#define Example3

#ifdef Example1
	void HellowGuest(string Name){
		std::cout<<"Hello:"<<Name<<endl;

	}
	void Hello(){
		std::cout<<"Hello"<<endl;

	}
#elif defined(Example2)

	void Hello(){
		std::cout<<"Hello"<<endl;

	}
	void Caller(int n){
		std::cout<<"I`m Number "<<n<<endl;

	}
#elif defined(Example3)

	void printValue(int value){
		std::cout<<value<<endl;
	}
    //Here we will receieve the function pointer as a variable
	void ForEachElem(std::vector<int>& elements,void(*Func)(int)){

		std::cout<<"Vector Elemets are: "<<endl;
		//Loop on each element in vector elements
		for (int elem: elements)
			//Call the Print Function through the Function Pointer
			Func(elem);
	}


#endif

int main() {
	cout << "Function Pointer Example" << endl;
	/* FUnction Pointer is just a way to assign a function call to a variable
	It`s like a symbol or some code we want to call when we want something to happen,
	 or It`s like a second function call will happen after finishing some Function execution
	 or a function call through a function pointer to it
	 */

#ifdef Example1

	//Assume you called Function Hello(); and now you want to use pointer to function to call
	//that function, So you can use the function pointer as follows
	 void(*function)(string) = &HellowGuest;
	 //or auto function = &HelloGuest; //Give the address of the function instructions to the pointer
	 //or auto function = HelloGuest;  //here is Implicit conversion by compiler, so you need to put & before function Name
	 auto func = Hello;
	 //Then call the Function through the Function pointer
	 function("Ali");

#elif defined(Example2)
	 //As Functions are just a cpu Instructions, so you may use the function pointer to allow
	 // the code in execute these instructions when called

	 //more better, using typedef to define function pointer as
	 typedef void(*FuncPointer)();
	 typedef void(*FuncNum)(int);

	 //Assign Function Name to the Pointer
	 FuncPointer Fun=Hello;
	 FuncNum FNum=Caller;

	 //Use Function Pointer
	 Fun();
	 FNum(2);

#elif defined(Example3)
	 //make a more useful Example for Function Pointer
	 //Assume we`ve a vector and we will make a function pointer that will make some action while we loop on each element on the vector
	 std::vector<int> vals={2,3,11,42,34};
	 //Here we call a function to loop on vector elements, an we give it the function name that we want to execute somewhere inside function ForEachElem
	 ForEachElem(vals,printValue);

#endif

	return 0;
}
