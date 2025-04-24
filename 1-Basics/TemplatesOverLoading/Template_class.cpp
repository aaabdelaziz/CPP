//============================================================================
// Name        : Template_class.cpp
// Author      : aaaziz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template <class T>  // template class
class Buky{
	T a,b;
public:
	Buky(T x, T y){
		a=x;
		b=y;
	}
	T PrintVals();
};

template <class T>
T Buky<T>::PrintVals(){
 return (a>b?a:b);
}

int main() {
	Buky<int> ob(193,355);
	cout <<ob.PrintVals()<< endl; // prints !!!Hello World!!!
	return 0;
}



