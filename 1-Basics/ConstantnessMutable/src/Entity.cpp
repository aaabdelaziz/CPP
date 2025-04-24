#include"Entity.h"

#ifdef Example1
	int Entity::GetX() const{
		//You can`t change the m_x val here beacuse
		// m_x =2;  // will give compiler error, as all class attributes becomes read only
		return m_x;
	}

	void Entity::setX(int val){
		m_x=val;
	}
#elif defined(Example2)

	Entity::Entity(){

		std::cout<<"Default constructor is called "<<endl;
	}
	const int* const Entity::GetX () const{
		return m_x;
	}
	void Entity::setX(int val){
		*m_x=val;
	}
#elif defined(Example3)


	Entity::Entity(){

		std::cout<<"Default constructor is called "<<endl;
	}
	Entity::Entity(const Entity& e){

			std::cout<<"Copy constructor is called "<<endl;
		}
	int Entity::GetX () const{
		return m_x;
	}
	void Entity::setX(int val){
		m_x=val;
	}

#elif defined(Example4)

	//Here using const Method overloading
	Entity::Entity(){

		std::cout<<"Default constructor is called "<<endl;
	}
	Entity::Entity(const Entity& e){

			std::cout<<"Copy constructor is called "<<endl;
	}
	//Will be called if the obj to class was constant

	int Entity::GetX () const{
		std::cout<<"Calling const GetX, and can`t modify class members"<<endl;
		return m_x;
	}
	//Will be called if the obj to class wasn`t constant
	int Entity::GetX (){
		std::cout<<"Calling GetX, and can modify class members"<<endl;
		return m_x;
	}
	void Entity::setX(int val){
		m_x=val;
	}
#elif defined(Example5)
	//Here using const Method overloading and can change const class member variable
	Entity::Entity(){
		DebugVar=1;
		std::cout<<"Default constructor is called "<<endl;
	}

	Entity::Entity(const Entity& e){
		DebugVar=1;
		std::cout<<"Copy constructor is called "<<endl;
	}
	//this method Will be called if the obj to class was constant
	int Entity::GetX () const{
		// DebugVal=2; --> this will give compiler error if DebugVar isn`t defined -> mutable int DebugVar;
		DebugVar=2; //Here we are able to modify it as it`s defined as Mutable
		std::cout<<"Calling const GetX, and can`t modify class members"<<endl;
		return m_x;
	}
	//Will be called if the obj to class wasn`t constant
	int Entity::GetX (){
		std::cout<<"Calling GetX, and can modify class members"<<endl;
		return m_x;
	}
	int Entity::GetDebugVar () const {
		std::cout<<"Getting DebugVar"<<endl;
		return DebugVar;
	}


	void Entity::setX(int val){
		m_x=val;
	}
#elif defined(Example6)
	const std::string& Entity::GetName() const{
		//we can increment m_DebugCount without losing the constantness of this method
				m_DebugCount++;
				return m_Name;
	}
	const int& Entity::GetDebugCount() const{
		return m_DebugCount;
	}

	void Entity::SetName(string s){
		m_Name=s;
	}
#elif defined(Example7)

#endif
