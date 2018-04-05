#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int jumlah(int a,int b)
{
	int result;
	result=a+b;
	return(result);
}

int kurang(int a,int b)
{
	int result;
	result=a-b;
	return (result);
}

int kali (int a,int b)
{
	int result;
	result=a*b;
	return(result);
}

int bagi(int a,int b)
{
	int result;
	result=a/b;
	return (result);
}

int mod(int a,int b)
{
	int result;
	result=a%b;
	return(result);
}

int main()
{
	int x, y, hasiljum, hasilkur, hasilkal, hasilbag, hasilmod, pilihan;
	char pilihan1;
	do{
	system("cls");
	cout<<"=============================\n";
	cout<<"KALKULATOR DUA BILANGAN\n";
	cout<<"=============================\n";	
	cout<<"Masukkan bilangan pertama:";
	cin>>x;
	cout<<"Masukkan bilangan kedua:";
	cin>>y;
	cout<<endl;
	cout<<"Pilih operasi yang ingin dilakukan\n";
	cout<<"1.Penjumlahan\n";
	cout<<"2.Pengurangan\n";
	cout<<"3.Perkalian\n";
	cout<<"4.Pembagian\n";
	cout<<"5.Modulus\n";
	cout<<"0.selesaikan program\n";
	cout<<"Pilihan anda adalah:";
	cin>>pilihan;
	cout<<endl;
	switch (pilihan)
	{
		case 1:
			{
				hasiljum=jumlah(x,y);
				cout<<"Hasil jumlah kedua bilangan tersebut :"<<hasiljum;
				cout<<endl;
			}break;
		case 2:
		{
			hasilkur=kurang(x,y);
			cout<<"Selisih dari dua bilangan tersebut :"<<hasilkur;
			cout<<endl;
		}break;	
		case 3:
		{
			hasilkal=kali(x,y);
			cout<<"Hasil kali dari dua bilangan tersebut adalah:"<<hasilkal;
			cout<<endl;
		}break;
		case 4:
		{
			hasilbag=bagi(x,y);
			cout<<"Hasil pembagian dari kedua bilangan tersebut adalah:"<<hasilbag;
			cout<<endl;
		}break;
		case 5:
		{
			hasilmod=mod(x,y);
			cout<<"Sisa pembagian dari bilangan pertama oleh bilangan kedua adalah:"<<hasilmod;
		}break;
		case 0:
		{
			cout<<"Terima kasih";
		}break;
		default:
			cout<<"Pilihan tidak ada";
			break;
	}
	
	cout<<endl;
	cout<<"Ingin tetap menggunakan program? Y/N :\t";
	cin>>pilihan1;
	
}while(pilihan1=='Y' || pilihan1=='y');

return 0;

}
