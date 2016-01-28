// Carlos Chitty
// Lab# 6 part 4

#include <iostream.h>

class Date //first base class
{
	public:
	int day;
	int month;//base class data members
	int year;
	Date()//base class constructor
	{
	}
	~Date()//base class destructor
	{
	}
};

class Time //second base class
{
	public:
	int hour;//base class data members
	int minute;
	int second;
		Time()//base class constructor
		{
		}
	~Time()//base class destructor
		{
		}
};

class DateAndTime : public Date, public Time //multiple inheritance class
{
public:
	void display();		// prints date and time
	void set();//sets date and time
	DateAndTime(int,int,int,int,int,int);//constructor
	~DateAndTime()//destructor
	{
	}
};

//constructor function
DateAndTime::DateAndTime(int d, int m,int y,int h, int min, int s)
{
	day=d;
	month=m;
	year=y;
	hour=h;
	minute=min;
	second=s;
}

void DateAndTime::display()
{
	cout << month << "/" << day << "/" << year << endl;
	cout << hour << ":" << minute << ":" << second << endl;
}

void DateAndTime::set()
{
	cout << "enter month in mm format: ";
	cin >> month;
	month = ( month >= 1 && month <= 12 ) ? month : 0; 
	cout << "enter day in dd format: ";
	cin >> day;
	day = ( day >= 1 && day <= 31 ) ? day : 0;
	cout << "enter year in yy format: ";
	cin >> year;
	year = ( year >= 0 ) ? year : 0;
	cout << "enter hour in hh format: ";
	cin >> hour;
	hour = ( hour >= 0 && hour < 24 ) ? hour : 0;
	cout << "enter minute in mm format: ";
	cin >> minute;
	minute = ( minute >= 0 && minute < 60 ) ? minute : 0;
	cout << "enter second in ss format: ";
	cin >> second;
	second = ( second >= 0 && second < 60 ) ? second : 0;
}
	
void main()
{
	DateAndTime Watch(0,0,0,0,0,0) ;//create new object in derived class
	cout << "Initial Date & Time" << endl;
	Watch.display(); //display intial time and date
	cout << "Set Date & Time" << endl;
	Watch.set(); //set new time and date
	cout << "New Date & Time" << endl;
	Watch.display(); //display new time and date
}
