#include <iostream>
#include <iomanip>

using namespace std;

int main (int argc, char *argv[])
{
	//1. Header Progres
	cout << "=============================\n";
	cout << "Program penjumlahan Matriks\n";
	cout << "=============================\n";

	//2. Variabel Program
	int a[3][3];
	int b[3][3];
	int hasil[3][3];
	
	//3. Proses output dan input variabel
	//4. Proses perhitungan
	cout << "Matriks A" << endl;
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
		cout << "Baris " << i+1 << "Kolom " << j+1 << "= ";
		cin >> a[i][j];
		}
	}
	
	cout << "Matriks B" << endl;
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
		cout << "Baris " << i+1 << "Kolom " << j+1 << "= ";
		cin >> b[i][j];
		}
	}
	
	//5. Output Hasil
	
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
		hasil[i][j] = a[i][j] + b[i][j];
		cout << setw(5) << hasil[i][j];
		}
		cout << endl;
	}
	
	//6. Footer
	return 0;
}
