#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h> //untuk clear

using namespace std;

struct tanggal {
	int tgl;
	int bulan;
	int tahun;
};

struct mhs {
	char nim [10];
	char nama [20];
	char alamat [30];
	float ipk;
	tanggal tanggal_lahir;
};

int main (){
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout << "PROGRAM INPUT DAN OUTPUT DATA MAHASISWA BY STRUCT"<<endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout << endl;
	
	mhs mahasiswa[2]; //deklarasi var, menyiapkan 1-- data mhs	
	for (int i = 0; i<2; i++){
		cout << ">>>> MAHASISWA KE-" << i+1 <<"<<<<" << endl;
		cout << endl << "NIM \t \t : "; cin >> mahasiswa[i].nim;
		fflush(stdin);
		cout << "NAMA \t \t : "; gets(mahasiswa[i].nama);
		fflush(stdin);
		cout << "ALAMAT \t \t : "; gets(mahasiswa[i].alamat);
		fflush(stdin);
		cout << "IPK \t \t : "; cin >> mahasiswa[i].ipk;
		fflush(stdin);
		cout << "TANGGAL LAHIR \t : "; cin >> mahasiswa[i].tanggal_lahir.tgl;
		fflush(stdin);
		cout << "BULAN LAHIR \t : "; cin >> mahasiswa[i].tanggal_lahir.bulan;
		fflush(stdin);
		cout << "TAHUN LAHIR \t : "; cin >> mahasiswa[i].tanggal_lahir.tahun;
		fflush(stdin);
		cout << endl;
		}
		system("cls"); //untuk clear
	
	
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		cout << "TAMPILAN INPUT DAN OUTPUT DATA MAHASISWA BY STRUCT"<<endl;
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		cout << endl;
		
	for (int i = 0; i<2; i++){
		cout << endl << ">>>> MAHASISWA KE-" << i+1 <<"<<<<" << endl;
		cout << endl << "NIM 	: " << mahasiswa[i].nim << endl;
		cout << "NAMA	: " << mahasiswa[i].nama << endl;
		cout << "ALAMAT	: " << mahasiswa[i].alamat << endl;
		cout << "IPK	: " << mahasiswa[i].ipk << endl;
		cout << "LAHIR	: " << mahasiswa[i].tanggal_lahir.tgl << " / " << mahasiswa[i].tanggal_lahir.bulan << " / " << mahasiswa[i].tanggal_lahir.tahun << endl;
		}
		
		cout << endl << "++++++++++++++++++++++++++++++++"<<endl;
		cout << "PROGRAM SELESAI, SILAHKAN KELUAR"<<endl;
		cout << "++++++++++++++++++++++++++++++++"<<endl;
	
	return 0;
}
