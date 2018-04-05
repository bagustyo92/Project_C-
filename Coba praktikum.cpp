#include <iostream>

using namespace std;

void tukar (float *x, float *y);

int main (){
	float bil1, bil2;
	
	bil1=10;
	bil2=15;
	
	cout << "Bilangan 1 = " << bil1 << "\tBilangan 2 = " << bil2;
	tukar(&bil1,&bil2);
	cout << "\nBilangan 1 = " << bil1 << "\tBilangan 2 = " << bil2;
	
	return 0;
}

void tukar (float *x, float *y){ //pass by refrence = alamatnya
	float temp;
	
	temp = *x;
	*x = *y;
	*y = temp;
}
