#include <iostream>

using namespace std;

struct motor {
		float volts;
		float amps;
	};

int main(){
	
	motor m1;
	motor *pm1;
	
	m1.volts = 100;
	m1.amps =110;
	
	pm1 =&m1;
	
	cout << "voltase motor m1 = " << m1.volts;
	cout << "\namps motor m1 = " << m1.amps;
	cout << "\nvoltase motor m1 = " << pm1->volts;
	cout << "\namps motor m1 = " << pm1->amps;
	
	return 0;
}
