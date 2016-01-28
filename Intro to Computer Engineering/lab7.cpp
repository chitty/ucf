// Carlos Chitty
// Lab 7

// Polymorphism

#include <iostream>
using namespace std;
#include <string>

class Staff
{
private:
	string name;
	string address;
	string phone;
public:
	Staff(string, string, string);
	virtual display();
};

Staff::Staff(string nombre, string direccion, string telefono)
{
	name = nombre;
	address = direccion;
	phone = telefono;

}

Staff::display()
{
	cout << "Name: " << name << endl;
	cout << "Address: " << address << endl;
	cout << "Phone Number: " << phone << endl;
}

class SalaryEmployee : public Staff
{
private:
	double salary;
public:
	SalaryEmployee(string, string, string, double);
	display();
};

SalaryEmployee::SalaryEmployee(string n, string direc, string tlf, double money) :
                Staff(n, direc, tlf) // Calls base constructor
{
	salary = money;
}


SalaryEmployee::display()
{
	Staff::display();
	cout << "Salary: $" << salary << endl;
}

class HourlyEmployee : public Staff
{
private:
	double hourly_pay;
public:
	HourlyEmployee(string, string, string, double );
	display();
};


HourlyEmployee::HourlyEmployee(string n, string direc, string tlf, double hp) :
                Staff(n, direc, tlf) // Calls base constructor
{
	hourly_pay = hp;
}


HourlyEmployee::display()
{
	Staff::display();
	cout << "Hourly Pay: $" << hourly_pay << endl;
}


class ContractEmployee : public Staff
{
private:
	int contractDuration;
public:
	ContractEmployee(string, string, string, int);
	display();
};

ContractEmployee::ContractEmployee(string n, string direc, string tlf, int duration) :
                Staff(n, direc, tlf) // Calls base constructor
{
	contractDuration = duration;
}


ContractEmployee::display()
{
	Staff::display();
	cout << "Contract Duration: " << contractDuration <<" weeks" << endl;
}

void print(Staff*[15]);
int main()
{
	Staff *A[15] = {0};

	// Using the new operator to declare a new object
	SalaryEmployee* S1 = new SalaryEmployee( "Carlos", "111 Miami", "305", 50000 ); 
	SalaryEmployee* S2 = new SalaryEmployee( "John", "222 Ohio", "306", 40000 );
	SalaryEmployee* S3 = new SalaryEmployee( "Luis", "333 Utah", "307", 60000 );
	SalaryEmployee* S4 = new SalaryEmployee( "Juan", "444 NYC", "308", 55000 );
	SalaryEmployee* S5 = new SalaryEmployee( "Alex", "555 Dade", "309", 45000 );
	HourlyEmployee* Hour1 = new HourlyEmployee( "Xu", "666 Yale", "409", 10.0 );
	HourlyEmployee* Hour2 = new HourlyEmployee( "Paul", "777 LA", "509", 7.50 );
	HourlyEmployee* Hour3 = new HourlyEmployee( "Alan", "888 Orlando", "407", 50.0 );
	HourlyEmployee* Hour4 = new HourlyEmployee( "Ilan", "999 Tampa", "609", 25.25 );
	HourlyEmployee* Hour5 = new HourlyEmployee( "Becky", "101 Weston", "709", 32.50 );
	ContractEmployee* C1 = new ContractEmployee( "Raul", "110 Denver", "809", 6 );
	ContractEmployee* C2 = new ContractEmployee( "Ramon", "120 Philly", "909", 10 );
	ContractEmployee* C3 = new ContractEmployee( "Jose", "130 Chicago", "009", 5 );
	ContractEmployee* C4 = new ContractEmployee( "Pedro", "140 Wales", "109", 12 );
	ContractEmployee* C5 = new ContractEmployee( "David", "155 Rock", "209", 3 );

	// Stores the address of the information in a random location of the array
	A[0] = S1;
	A[10] = S2;
	A[1] = S3;
	A[14] = S4;
	A[2] = S5;
	A[13] = Hour1;
	A[3] = Hour2;
	A[5] = Hour3;
	A[11] = Hour4;
	A[9] = Hour5;
	A[8] = C1;
	A[6] = C2;
	A[4] = C3;
	A[12] = C4;
	A[7] = C5;

	print(A);

	delete S1,S2,S3,S4,S5,Hour1,Hour2,Hour3,Hour4,Hour5,C1,C2,C3,C4,C5;
	return 0;
}

// Function uses a single for loop to traverse the array and output
// the information accordingly
void print(Staff *arr[15])
{
	for(int i=0; i<15; i++)
	{
		arr[i]->display(); // calls the desired display function
		cout << "\n";
	}
}

