#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
struct mahasiswa {
	char nim[20];
	char nama[15];
   	char jurusan[20];
	char angkatan[4];
};
int main(){
	int jml;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout << "PROGRAM INPUT DAN OUTPUT DATA MAHASISWA BY STRUCT"<<endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"\n\nMasukkan jumlah mahasiswa : ";cin>>jml;
	mahasiswa mhs[jml];
	mahasiswa *pmhs;
	pmhs=mhs;
	system("cls");
	
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout << "PROGRAM INPUT DAN OUTPUT DATA MAHASISWA BY STRUCT"<<endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++\n\n"<<endl;
	for(int i=0;i<jml;i++){
		cout<<"Mahasiswa ke-"<<i+1<<endl;
		cout<<"Nim\t\t: ";cin>>pmhs[i].nim;
		fflush(stdin);
		cout<<"Nama\t\t: ";gets(pmhs[i].nama);
		fflush(stdin);
		cout<<"Jurusan\t\t: ";gets(pmhs[i].jurusan);
		fflush(stdin);
		cout<<"Angkatan\t: ";cin>>pmhs[i].angkatan;
		fflush(stdin);
		cout<<endl;
	}
	system("cls");
	
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout << "PROGRAM INPUT DAN OUTPUT DATA MAHASISWA BY STRUCT"<<endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++\n\n"<<endl;
	for(int i=0;i<jml;i++){
		cout<<i+1<<". ";
		cout<<"Nim\t\t: "<<pmhs[i].nim<<endl;
		cout<<"   Nama\t\t: "<<pmhs[i].nama<<endl;
		cout<<"   Jurusan\t: "<<pmhs[i].jurusan<<endl;
		cout<<"   Angkatan\t: "<<pmhs[i].angkatan<<endl;
		cout<<endl;
	}
	
	cout << "\n\n======================================" << endl;
	cout << "Terima Kasih, Tekan Enter Untuk Keluar" << endl;
	cout << "======================================" << endl;
	
	return 0;
}
