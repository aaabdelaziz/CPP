
#include "Entity.h"

#ifdef Example1
#elif defined(Example2)
#elif defined(Example3)

	//To print the contents of the entity
	//using the obj will allow copying the contents and make copy constructor
	void PrintEnt(Entity e){
		std::cout<< "Using copy of class object "<<endl;
		std::cout<<"m_x value is " << e.GetX() <<endl;
		e.setX(99);
	}
	//using the pointer will allow accessing the contents / Modifying it without making copy constructor
	void PrintEntity(Entity *e){
		std::cout<< "Using pointer "<<endl;
		std::cout<<"m_x value is " << e->GetX() <<endl;
		e->setX(12);
	}

	//using the pointer will allow accessing directly the same object and modify or read its contents
	// Here no Copy Constructor is called
	void PrintEntity(Entity &e){
		//e = Entity(); is Wrong as e isn`t pointer
		std::cout<< "Using Refrence "<<endl;
		std::cout<<"m_x value is " << e.GetX() <<endl;
		e.setX(19);
	}

#elif defined(Example4)
	//Create a constant object to class
	//so, it allows to call only the constant Methods in class,so call GetX const();
	void PrintEntity(const Entity &e){
		//e = Entity(); is Wrong as e isn`t pointer
		std::cout<< "Using Refrence "<<endl;
		std::cout<<"m_x value is " << e.GetX() <<endl;
		// e.setX(19);  --> can`t be used as setX isn`t constant method
	}

	void PrintEntity(Entity &e){
		//e = Entity(); is Wrong as e isn`t pointer
		std::cout<< "Using Refrence "<<endl;
		std::cout<<"m_x value is " << e.GetX() <<endl;
		// e.setX(19);  --> can`t be used as setX isn`t constant method
	}

#elif defined(Example5)
	//Create a constant object to class
	//so, it allows to call only the constant Methods in class,so call GetX const();
	void PrintEntity(const Entity &e){
		//e = Entity(); is Wrong as e isn`t pointer
		std::cout<< "Using Refrence "<<endl;
		std::cout<<"m_x value is " << e.GetX() <<endl;
		// e.setX(19);  --> can`t be used as setX isn`t constant method
	}
#elif defined(Example6)
#elif defined(Example7)

#endif

int main() {



#ifdef Example1

	Entity e;
	//Set X val
	e.setX(4);
	//Get the x val
	int X_val=e.GetX();

	cout << "X_val="<< 	X_val << endl;

#elif defined(Example2)
    // This way is better to use pointer to class

	//Here I allocated a pointer to class and allocate a class with it`s contents in the heap
	Entity *ptr=new Entity() ;

	ptr->setX(15);
	//Get The Value
	const int * const p = ptr->GetX();

	std::cout<< "Pointer carrying Address " << p <<endl;
	std::cout<< "Pointer has a value " << *p<<endl;

	delete ptr;

	std::cout<< "Pointer carrying Address " << p <<endl;
	std::cout<< "Pointer has a value " << *p<<endl;


//	const int * const p = ptr->GetX();
//	cout<<" Pointer value" << p <<endl;
#elif defined(Example3)

	Entity e;
	std::cout<<"m_x is setted to 30"<<endl;
	e.setX(30);

	std::cout<<"----- using Function Overloading -----"<<endl;
	//Pass by Value
	std::cout<<"Pass by Value"<<endl;
	PrintEnt(e);
	std::cout<<"m_x value after Return "<<e.GetX()<<endl;
	std::cout<<"--------------------------------------"<<endl;

	//Pass by Address
	std::cout<<"Pass by Address"<<endl;
	PrintEntity(&e);
	std::cout<<"m_x value after Return "<<e.GetX()<<endl;
	std::cout<<"--------------------------------------"<<endl;


	//pass by Reference
	std::cout<<"Pass by Reference"<<endl;
	PrintEntity(e);
	std::cout<<"m_x value after Return "<<e.GetX()<<endl;
	std::cout<<"--------------------------------------"<<endl;

#elif defined(Example4)
	Entity e;
	e.setX(11);
	PrintEntity(e);
#elif defined(Example5)

	//Assume Here wanted to modify some variable through constant function
	//Say for some reason, to modify a class member used for Debugging
	//So, we will use Mutable
	Entity e;
	e.setX(33);
	std::cout<< e.GetDebugVar()<<endl;
	PrintEntity(e);
	std::cout<< e.GetDebugVar()<<endl;
#elif defined(Example6)
    //Assume we need to get a member name from class and in each time we wanted
	//to count the number of times we called that name.
	Entity obj;
	//const Entity o; o.setname(); --> will give error as Set Function is not Const
	obj.SetName("Ahmed");
	const std::string& str =obj.GetName();
	std::cout<<str<<endl;
#elif defined(Example7)
	//Another Usage for Mutable Keyword with lambda function is like

		int x=9;
		// The x variable captured by value[=] cannot be modified in
		// a lambda expression by default. However, this default behavior
		// can be overriden by mutable qualifier.
		// A mutable lambda expression is allowed to change the variables
		// captured by copy://look example
		// https://www.nextptr.com/question/a195007104/the-cplusplus-mutable-lambda-expressions-as-stateful-function-objects
		auto IncX= [=]() mutable
	    {
			  /* "x" cannot be modified without
			         keyword mutable. */
			x++;
			return x;
		};

		/*
		 * Or you can
		 *
		 *Call by value, use mutable or you have to define a variable inside classto receive x in
		auto f= [=](){
			int y = x++;
			cout<<x<<endl;
		};
		 *
		 *
		 * */
		std::cout<<IncX()<<endl;
		std::cout<<IncX()<<endl;

		auto bar= IncX;
		std::cout<<bar()<<endl;

		//Note that X will not be cahnged as it was sent by value
		std::cout<<" But X didn`t Changed: "<<x<<endl;



#endif





	return 0;
}
