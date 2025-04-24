
#include <iostream>
using namespace std;
class base{
	protected:
	int data;
};

class derived1 : public base{
	// data is inherited here 
	public:
	derived1(){
		data = 1;
	}

	int GetData1(){ return data;}
};

class derived2 : public base{
	// data is inherited here 
	public:
	derived2(){
		data = 2;
	}

	int GetData2(){ return data;}
};

// If Enabled code here
// This derived3 will create diamond problem and will cause compiler Problem

class derived3 : public derived1, public derived2{
	// we have 2 copies of data inherited here from both derived1,2 this cause ambiguity for compiler.
	public:
	
	derived3(){
		// this will cause ambiguity and shouldn't set data again
		//data = 3;
	}
	// Solution to problem in Inheritance1.cpp, is to define which data copy should be returned.
	// here we chose to return data of derived2 class
	int GetData3(){ return derived2::data;}
 };

int main() {
	derived3 d;
	
	cout << "data is " << d.GetData3() << endl; 
	return 0;
}


// Or the better solution is in Inheritace3.cpp