#include <iostream>

using namespace std;

struct motor {
	float volts;
	float amps;
};

typedef struct motor motor;

int main()
{
	motor m;
	motor *pm;
	
	m.volts = 10;
	m.amps = 20;
	
	pm = &m;
	
	cout << "Isi m bagian volts diakses secara langsung = " << m.volts;
	cout << "\nIsi m bagian amps diakses secara langsung = " << m.amps;
	
	cout << "\n\nIsi m bagian volts diakses melalui pm = " << pm->volts;
	cout << "\nIsi m bagian amps diakses melalui pm = " << pm->amps;
	
	return 0;
}

//guna baris 5 - 9 adalah memberikan nilai pada variable volts  dan amps pada struct m, juga mengalamatkan m pada pointer pm.
//beda baris 21-22 dengan 25-26 adalah 
