#include <iostream>

using namespace std;

void tukar(int *x, int *y); //deklarasi methode

int main(){
	int bil1, bil2;
	
	bil1 = 10;
	bil2 = 15;
	
	cout << "Bilangan 1 = "  << bil1 << " Bilangan 2 = " << bil2;
	tukar(&bil1, &bil2); //melempar alamat
	cout << "\nBilangan 1 = "  << bil1 << " Bilangan 2 = " << bil2;
	
	return 0;
}

void tukar(int *x, int *y){
	int temp;
	
	temp = *x;
	*x = *y;
	*y = temp;
}
