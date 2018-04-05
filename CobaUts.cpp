#include <iostream>
#include <stdio.h>

using namespace std;

int main (){
	int a[5]={1,2,3,4,5};
	
	for(int i=0; i<5; i++){
		cout << a[i];
		for (int j=0; j<a[i]; j++){
				cout << "*";
		}
	}
	
	//=======================
	
	int x, *ptr, **ptr2;
	ptr = &x; //Harus ada ini kalo mau merubah nilai via ptr (alamat no tanda (*)
	ptr2 = &ptr; //Harus dialamatkan dulu kalo mau bisa diakses
	x = 5;
	**ptr2 = 20;
	cout << *ptr;
	
	
	int arr[5]={1,2,3}, *point;
	point = arr;
	cout << *arr+1;
	
	int i;
    int *ptra[4]; 
    int xx=1, y=2,  zz=3, w=5;
    ptra[0]=*xx, ptra[1]=&y; ptra[2]=&zz; ptra[3]=&w;
    for(i=0;i<4;i++) cout<<"\n " << *ptra[i];

	
	char z[30];
	char s[20];
	cout << "\nMasukan Nama\t : "; gets(z);
	cout << "Masukan NIM\t : "; gets(s);
	cout << z;
	cout << s;
	
	//=======================
	
	cout << "manusia " "setengah salmon";
	
	return 0;
	}
