// Carlos Chitty
// Lab# 6 part 2

#include <iostream.h>
#include <iomanip.h>
#include <string.h>
//
//  base class definition
//
class Inventory 
	{
      private:
       	int 		quant;              // number on hand
            int 		reorder;           // reorder quantity
            double price;               // price per unit
            char*	descrip;	// description of item
  	public:
      	Inventory (int q, int r, double p, char* d) 
			: quant(q), reorder(r), price(p)
{
descrip = new char[strlen(d)+1];
strcpy (descrip, d); 
}
            ~Inventory()
			{
			delete descrip;	// Some C++ may require delete [] descrip;
			}
            void printI()
{
cout <<"Description: "  << descrip << endl; 
}
            int get_quant()
{
return quant; 
}
            int get_reorder()
{
return reorder; 
}
            double get_price()
{
return price; 
}
	};
//
// first derived class 
//
class Auto : public Inventory 
	{
        	char * manufacturer;
  	public:
      	Auto (int q, int r, double p, char * d, char *  man) :
        		Inventory(q, r, p, d)   // calls base constructor
{
manufacturer = new char [strlen (man)+1];
strcpy (manufacturer, man); 
}
        	~Auto()
{
delete manufacturer; 	// May use delete [] manufacturer
}
        	void print()
{
cout << setiosflags (ios::fixed);
 cout << "Manufacturer: "  << manufacturer  << endl;  
}
        	char * get_manufacturer()
{
return manufacturer; 
}
		};
//
// Second derived class  
//
class Transmission : public Inventory 
	{
        	char * vendor;
  	public:
        	Transmission (int q, int r, double p, char * d, char * ven) : Inventory(q, r, p, d)
			{
vendor = new char [strlen (ven)+1];
strcpy (vendor, ven);  
			}        	
		~ Transmission ()
{
delete vendor; 	// May require delete [] vendor
}
        	void print()
{
cout << setiosflags(ios::fixed);
cout << "Vendor: "  << vendor << endl;  
}
        	char * get_vendor() const
			{
			return vendor;
			}
	};

void main()
{
	Auto Car( 5,2,15545.91,"four-wheel drive truck", "GM");
	Transmission Transmissions( 25,10,1789.98,"transmission for the truck", "Aztec Inc.");

	cout << "Answer to part b) \n\n";
	cout << "Quantity: " << Car.get_quant() << endl;
	cout << "Reorder: " << Car.get_reorder() << endl;
	cout << "Price per unit: $" << Car.get_price() << endl;
	Car.print();
	Car.printI();

	cout << "\n\nAnswer to part c) \n\n";
	cout << "Quantity: " << Transmissions.get_quant() << endl;
	cout << "Reorder: " << Transmissions.get_reorder() << endl;
	cout << "Price per unit: $" << Transmissions.get_price() << endl;
	Transmissions.print();
	Transmissions.printI();

	cout << "\n\nAnswer to part d) \n\n";
	cout << "Quantity, Reorder, Price per unit and Description comes from base class"
	     << " Inventory.\nManufactorer comes from derived class Auto.\n"
		 << "Vendor comes from derived class Transmission.\n";
		
}
