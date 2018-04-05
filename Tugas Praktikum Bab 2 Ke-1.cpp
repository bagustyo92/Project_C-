#include <iostream>

using namespace std;

struct kompleks {
	float a;
	float b;
};

kompleks tambah (kompleks k1, kompleks k2);

int main (){
	kompleks k1, k2, k3;
	k1.a=12;
	k1.b=13;
	cout << "bilangan kompleks pertama : " << k1.a << " & " << k1.b;
	k2.a =14;
	k2.b =15;
	cout << "\nBIlangan kompleks kedua : " << k2.a << " & " << k2.b;
	k3 = tambah (k1,k2);
	cout << "\nHasil penjumlahan bilangan kompleks : " << k3.a << " & " << k3.b;
}

kompleks tambah (kompleks k1, kompleks k2){ //pass by value = nilainya yang dikirim
	kompleks k3;
	
	k3.a = k1.a + k2.a;
	k3.b = k1.b + k2.b;
	
	return(k3);
}
