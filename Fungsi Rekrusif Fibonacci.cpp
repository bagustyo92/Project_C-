#include <iostream>
#include <stdlib.h>

using namespace std;

int fibo (int i){
	if (i==0){
		return 0;
	}
	if (i==1){
		return 1;
	}
	else {
		return fibo(i-1) + fibo(i-2);
	}
}

int main (){
	cout << "===================================";
	cout << "\n>>>>> PROGRAM DERET FIBONACCI <<<<<";
	cout << "\n===================================";
	
	//Menampilkan menu
	cout << "\n\n===========MENU===========";
	cout << "\n1. Menampilkan deret berjumlah sesuai masukan user";
	cout << "\n2. Memasukan data dalam deret, menampilkan indeks";
	cout << "\n3. Memasukan indeks dan menampilkan data";
	
	int i;
	int j;
	
	//Pilihan menu by code
	int pil;
	cout << "\n\nMasukan pilihan anda : "; cin >> pil;
	system("cls");
	
	switch (pil){
		case 1 :
			//Meminta user memasukan berapa banyak jumlah deret yang ingin ditampilkan
			cout << "===================================";
			cout << "\n>>>>> PROGRAM DERET FIBONACCI <<<<<";
			cout << "\n===================================";
			
			cout << "\n\n========Anda Memilih Menu Menampilkan Deret========";
			cout << "\n\nMasukan jumlah deret bilangan fibonacci : "; cin >> i;
			cout << "\nBerikut adalah deretnya :" << endl;
			for (int a = 0; a<i; a++){
				cout << fibo (a) << " ";
			}
			
			cout << "\n\n\n=========================";
			cout << "\nSEKIAN DAN TERIMA KASIH";
			cout << "\n=======================";
			break;
		
		case 2 :
			//Mencari data dalam deret, menampilkan indeks (user memasukan data lalu menampilkan berada pada indeks keberapa)
			
			cout << "===================================";
			cout << "\n>>>>> PROGRAM DERET FIBONACCI <<<<<";
			cout << "\n===================================";
			
			cout << "\n\n========Anda Memilih Menu Menampilkan Indeks========";
			
			int deret;
			int arFiboList[128];
			
			cout << "\n\nMasukkan jumlah deret fibonacci : ";
			cin >> deret;	
			for (int a=0; a < deret; a++) {
			arFiboList[a-1] = fibo(a);
			cout << arFiboList[a-1] << " ";
			}
			
			int data, indeks;
			indeks = 0;
			//system("CLS");
			cout << "\n\n========Mencari index dari data masukan========\n";
			cout << "\n\nMasukkan angka yang ingin dicari : ";
			cin >> data;
	for (int i=0; i<128; i++) {
		if (arFiboList[i] != 0) {
			if (data == 0) {
				cout << "\nAngka " << data << " berada di indeks : 0\n";				
				break;
			} else if (data == 1) {
				cout << "Angka " << data << " berada di indeks : 1 dan 2\n";
				break;
			} else {
				if (arFiboList[i] == data) {
					indeks = i+1;
					break;
				}
			}
		} else {
			break;
		}
	}
	// output
	if (indeks == 0) { // jika data input bukan fibonacci
		cout << "Angka yang dicari bukan angka fibonacci!\n";
	} else if (indeks >= 1) { // jika data benar fibonacci
		cout << "\nAngka " << data << " berada di indeks : " << indeks+1 << endl;
	}
	cout << endl << endl;
	
	break;
			
			cout << "\n\n\n=========================";
			cout << "\nSEKIAN DAN TERIMA KASIH";
			cout << "\n=======================";
			
		case 3 :
			//Mencari indeks, menampilan data (user memasukan indeks keberapa untuk mengetahui data yg dituju)
			cout << "===================================";
			cout << "\n>>>>> PROGRAM DERET FIBONACCI <<<<<<";
			cout << "\n===================================";
	
			cout << "\n\n========Anda Memilih Menu Menampilkan Data========";
			cout << "\n\nMasukan Indeks deret fibonacci yang ingin ditampilkan : "; cin >> i;
			if (i<40){
				cout << "\nIndeks ke-" << i << " dari deret fibonacci adalah : " << fibo (i-1);		
			}
				else {
				cout << "\nMOHON MAAF, INDEKS YANG ANDA MASUKAN DILUAR JANGKAUAN";			
			}
			
			cout << "\n\n\n=========================";
			cout << "\nSEKIAN DAN TERIMA KASIH";
			cout << "\n=======================";
			break;
	return 0;
	}
}
