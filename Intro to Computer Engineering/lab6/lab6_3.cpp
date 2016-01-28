// Carlos Chitty
// Lab# 6 part 3

#include <iostream>
#include <string>
using namespace std;

class BaseAbc // base class declaration
{
	int 	i;//private data member
protected: // protected data member
	string name;
public: //public members
	float stuff;
	void print()//print function
	{
		cout << "Hello World!" << endl;
	}
	BaseAbc get_vals();
	BaseAbc( )	//constructor
	{
	}
	~BaseAbc()//destructor
	{
	}
};

class DerivedXyz : protected BaseAbc //derived class that inherits base class as protected
{
	float additional;
private:
	using BaseAbc::stuff; //inherits member stuff as private
public:
	using BaseAbc::print;     // this is now public
	DerivedXyz() //constructor
	{
	}
	~DerivedXyz()	//destructor
	{
	}
};

void main()
{
	DerivedXyz thing; //object of derived class
	thing.print(); //calls print function
}
