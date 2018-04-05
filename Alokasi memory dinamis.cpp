#include <iostream>
#include <stdlib.h>

using namespace std;

struct Employee{
	char name [40];
	int id;
};

int main (){
	int myInt;
	Employee john;
	cout << "size of int is " << sizeof(myInt);
	cout << "\nsize of int is " << sizeof(int);
	cout << "\nSize of employee is " << sizeof(Employee);
	cout << "\nSize of john is " << sizeof(john);
	cout << "\nSize of char is " << sizeof(char);
	cout << "\nSize of short is " << sizeof(short);
	cout << "\nSize of int is " << sizeof(int);
	cout << "\nSize of long is " << sizeof(long);
	cout << "\nSize of float is " << sizeof(float);
	cout << "\nSize of double is " << sizeof(double);
	
	return 0;
}
