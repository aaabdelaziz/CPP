
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
/* 
class derived3 : public derived1, public derived2{
// 	// data is inherited here 
	public:
	derived3(){
		data = 3;
	}

	int GetData3(){ return derived3::data;}
};
*/

int main() {
	derived2 d;
	
	cout << "data is " << d.GetData2() << endl; 
	return 0;
}
