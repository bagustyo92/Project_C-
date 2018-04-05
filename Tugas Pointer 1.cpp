#include <iostream>

using namespace std;

int main ()
{
	// Deklarasi Variabel
	int x;
	int *px;
	
	// Memasukan alamat variabel x ke px
	px=&x;
	
	// Mengisi variabel x dengan nilai 10
	x=10;
	
	cout << "Variabel x berisi data " << x << " dan berada di alamat " << px;
	
	return 0;
}

// 1. Proses yang terjadi pada baris 12 adalah mengalamatkan variabel x ke px, dan guna & (addres of)
// adalah alamat dari x yang dimasukan ke variabel px itu sendiri
// 2. Baris 16 adalah mencetak variabel x dan juga alamatnya.
// 3. Setelah di compile akan terjadi error karena pointer dan variabelnya harus bertipe sama
