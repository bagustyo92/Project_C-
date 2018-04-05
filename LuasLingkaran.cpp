#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{
	//1. Header Progres
	cout << = "=========================================\n";
	cout << = "Header Program Luas Lingkaran\n";
	cout << = "=========================================\n";
	
	//2. Variabel Program
	int jari;
	double pi=3.14;
	double luas;
	
	//3. Proses output dan input variabel
	cout << "Masukan Nilai Jari-Jari : " << endl;
	cin >> jari;
	
	//4. Proses perhitungan
	luas = pi * jari * jari;
	
	//5. Output Hasil
	cout << = "Luas Lingkaran = " << luas << endl;
	
	//6. Footer
	cout << "=========================================\n";
	cout << "DONE!!!\n";
	cout << "=========================================\n";
	return 0;
}
