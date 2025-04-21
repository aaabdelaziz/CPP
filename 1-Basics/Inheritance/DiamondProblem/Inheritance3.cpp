
// by using the virtual keyword while inheritance in derived1 , derived2, 
// this tells the compiler to take only one copy in derived3 class, and the derived3 will overwrite that data by 3 
// note if we didn't define data = 3 in derived3, the compiler will return data = 2 from class derived2 
// https://www.youtube.com/watch?v=DiUXoiOLZY0

#include <iostream>
using namespace std;
class base{
	protected:
	int data;
};

class derived1 : virtual public base{
	// data is inherited here 
	public:
	derived1(){
		data = 1;
	}

	int GetData(){ return data;}
};

class derived2 : virtual public base{
	// data is inherited here 
	public:
	derived2(){
		data = 2;
	}

	int GetData(){ return data;}
};

// If Enabled code here
// This derived3 will create diamond problem and will cause compiler Problem

class derived3 : public derived1, public derived2{
	// we have 2 copies of data inherited here from both derived1,2 this cause ambiguity for compiler.
	public:
	
	derived3(){
		data = 3;
	}
	// Solution to problem in Inheritance1.cpp, is to define which data copy should be returned.
	// here we chose to return data of derived2 class
	int GetData(){ return data;}
 };

int main() {
	derived3 d;
	
	cout << "data is " << d.GetData() << endl; 
	return 0;
}
