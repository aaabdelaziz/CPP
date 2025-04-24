
#include <iostream>

using namespace std;

class complex{
	int real;
	int imag;
public:
	//if default constructor isn`t existed, the compiler should generate it
	complex(){
		cout<<"default constructor is invoked"<<endl;
		real=0;
		imag=0;
	}
	complex(int R,int I){
		//Copy Constructor
		cout<<"Copy Constructor is invoked"<<endl;
		real=R;
		imag=I;
	}
	//Methods (attribures)
	void setImag(int I){
		imag=I;
	}
	void setReal(int R){
		real=R;
	}
	int getImag(){
		return imag;
	}
	int getReal(){
		return real;
	}

	complex sum(complex c){
		//Here a copy constructor of Complex will be called for Complex c

		int Real=this->getReal()+c.getReal();
	    int Image=this->getImag()+c.getImag();

	    complex sumAll(0,0);
	    sumAll.setImag(Image);
	    sumAll.setReal(Real);

		return sumAll;
	}

	complex sumMem(complex c){
			//Here a copy constructor of Complex will be called for Complex c

			int Real=Real+c.getReal();
		    int Image=Image+c.getImag();

		    complex sumAll(0,0);
		    sumAll.setImag(Image);
		    sumAll.setReal(Real);

			return sumAll;
    }

};

//call by value (copying)
complex sum(complex c1, complex c2){

	complex R;
	R.setImag(c1.getImag()+c2.getImag());
	R.setReal(c1.getReal()+c2.getReal());

	//try to change c1 and check effect on main
    c1.setImag(10);

	return R;
}

//call By Reference
complex sumReference(complex &c1, complex &c2){

	complex R;
	R.setImag(c1.getImag()+c2.getImag());
	R.setReal(c1.getReal()+c2.getReal());

	//try to change c1 and check effect on main
    c1.setImag(50);
	return R;
}


int main() {

	complex c1(1,2);
	cout << "Complex1 real: " <<c1.getReal()
	     << " Complex1 imag:"<<c1.getImag()<< endl;

	complex c2(4,6);
	cout << "Complex2 real: " <<c2.getReal()
		 << " Complex2 imag:"<<c2.getImag()<< endl;

    /******************* Sum Methods inside class ******************************/
    cout<<"----------Sum methods from inside class (as member Functions)----------"<<endl;
	// if call Sum of class
	complex sumAll=c1.sum(c2); //copying complex c2 object to complex c object, copy constructor is invoked here
	cout<<"Real sum: "<<sumAll.getReal()<<endl;
	cout<<"Imag sum: "<<sumAll.getImag()<<endl;

	// call SumMem of class
	complex sumMem=c1.sum(c2); //copying complex c2 object to complex c object, copy constructor is invoked here
	cout<<"Real sum: "<<sumMem.getReal()<<endl;
	cout<<"Imag sum: "<<sumMem.getImag()<<endl;
   /*********************** Sum outside class **************************/
    cout<<"----------Sum methods from outside class(as Stand alone functions)----------"<<endl;
	//Or if call an external sum function
    complex R;     //R make 1st call for default constructor
    R=sum(c1,c2);  //R make 2nd call for default constructor
    cout<<R.getReal()<<"+i "<<R.getImag()<<endl;
    cout<<c1.getReal()<<"+i "<<c1.getImag()<<endl;

    //or To decrease Number of created objects, Send by reference
    complex RR=sumReference(c1,c2); //RR make one call to default constructor
    cout<<RR.getReal()<<"+i "<<RR.getImag()<<endl;
    cout<<c1.getReal()<<"+i "<<c1.getImag()<<endl;

	return 0;
}
