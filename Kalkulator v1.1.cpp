#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
int perkalian(int a, int b){
	int kali = a*b;
	return kali;
}

int pembagian(int a, int b){
	int bagi = a/b;
	return bagi;
}

int penjumlahan(int a, int b){
	int jumlah = a+b;
	return jumlah;
}

int pengurangan(int a, int b){
	int kurang = a-b;
	return kurang;
}

int modus(int a, int b){
	int mod = a%b;
	return mod;
}

int main (){
	int x, y, kali, bagi, jumlah, kurang;
	char pilihan;
	char proses;
	do {
	cout<<"=============================\n";
	cout<<"KALKULATOR DUA BILANGAN\n";
	cout<<"=============================\n";
	cout << "\nLakukan proses perhitungan di bawah ini!";
	cout << "\nPetunjuk Pilihan:";
	cout << "\n1. (x) untuk perkalian";
	cout << "\n2. (:) untuk pembagian";
	cout << "\n3. (+) untuk penjumlahan";
	cout << "\n4. (-) untuk pengurangan";
	cout << "\n5. (%) untuk modulus";
	
	cout << "\n\nMasukan bilangan pertama\t: "; cin >> x;
	cout << "Masukan bilangan kedua\t\t: "; cin >> y;
	cout << "Masukan proses yang dikerjakan\t: "; cin >> proses;
	
	cout << "Hasilnya adalah\t\t\t: ";
	if (proses == 'x'){
		cout << perkalian(x,y);
	}else if (proses == ':'){
		cout << pembagian(x,y);
	}else if (proses == '+'){
		cout << penjumlahan(x,y);
	}else if (proses == '-'){
		cout << pengurangan(x,y);
	}else if (proses == '%'){
		cout << modus(x,y);
	} else {
		cout << "Proses yang anda pilih salah";
		cout << "\n\t\t\t\t Silahkan pilih proses sesuai pilihan diatas";
	}
	
	cout << "\n\nApa anda masih ingin menggunakan program? (Y / N)";
	cin >> pilihan;
	
	system("cls");
} while (pilihan == 'Y' || pilihan == 'y');

	
	cout << "\n>>> TERIMA KASIH <<<";
	return 0;
}
