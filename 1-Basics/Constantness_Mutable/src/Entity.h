#ifndef ENTITY_H_
#define ENTITY_H_

#include <iostream>
using namespace std;

//#define Example1
#define Example7

#ifdef Example1
	class Entity{
		int m_x,m_y;
	public:
		//Block Method GetX() from modifying any of class members
		int GetX () const;
		void setX(int val);
	};

#elif defined(Example2)

	class Entity{
			//Here I defined m_x as a pointer
			int *m_x,m_y;

		public:
			Entity();
			//Block Method GetX() from modifying any of class members, and also
			//Refrain the object that may call that method from changing the returned pointer address content or
			//the address inside the pointer itself from modification
			//So, in case we used a pointer member in class, you can give high restriction on it to be even modified.
			const int* const GetX () const;
			void setX(int val);
		};
#elif defined(Example3)

	class Entity{
			int m_x,m_y;

		public:
			Entity();
			Entity(const Entity& e);
			//Block Method GetX() from modifying any of class members, and also
			//Refrain the object that may call that method from changing the returned pointer address content or
			//the address inside the pointer itself from modification
			//So, in case we used a pointer member in class, you can give high restriction on it to be even modified.
			int GetX () const;
			void setX(int val);
		};
#elif defined(Example4)

	class Entity{
			int m_x,m_y;

		public:
			Entity();
			Entity(const Entity& e);
			//Block Method GetX() from modifying any of class members, and also
			//Refrain the object that may call that method from changing the returned pointer address content or
			//the address inside the pointer itself from modification
			//So, in case we used a pointer member in class, you can give high restriction on it to be even modified.
			int GetX () const;
			int GetX () ;
			void setX(int val);
		};
#elif defined(Example5)
	class Entity{
				int m_x,m_y;
				int Debugal;
				//Allow the method to can change the member function if using Mutable keyword
				mutable int DebugVar;
			public:
				Entity();
				Entity(const Entity& e);
				//Block Method GetX() from modifying any of class members, and also
				//Refrain the object that may call that method from changing the returned pointer address content or
				//the address inside the pointer itself from modification
				//So, in case we used a pointer member in class, you can give high restriction on it to be even modified.
				int GetX () const;
				int GetX () ;
				int GetDebugVar () const ;

				void setX(int val);
			};

#elif defined(Example6)
class Entity{
		std::string m_Name;
		//make it mutable to allow the const method to change it`s value
		mutable int m_DebugCount =0;
public:
		//return by const reference to make it read only and can`t rewrite on it
		void SetName(string s);
		const std::string& GetName() const;
		const int& GetDebugCount() const;
};
#elif defined(Example7)

#endif














#endif

