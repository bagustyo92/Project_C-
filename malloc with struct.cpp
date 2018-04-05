#include <iostream>
#include <stdlib.h>

using namespace std;

struct motor{
	float amps;
	float volts;
	struct motor *next;
};


int main (){
	//1 Deklarasi Pointer
	motor *mtr1, *mtr2;
		
	//2 Buat alokasi memory dinamis dan simpan alamat di *mtr   int a; int a = new int (); <-- ini membuat int a bukan mallioc
	mtr1 = new motor(); //sama dengan baris 19
	mtr2 = (motor*)malloc(sizeof(motor));
	
	//3 cek alokasi memori dgn if
	if (mtr1 != NULL&& mtr2 != NULL){
	
	//4 isi
	mtr1->amps=1.2;
	mtr1->volts=220;
	mtr1->next=mtr2;
	mtr2->amps=2;
	mtr2->volts=110;
	
	//tampilab
	cout << "Besar kuat arus dari motor 1 adalah " << mtr1->amps << endl;
	cout << "Besar tegangan dari motor 1 adalah " << mtr1->volts << endl;
	cout << "Besar kuat arus dari motor 2 adalah " << mtr2->amps << endl;
	cout << "Besar tegangan dari motor 2 adalah " << mtr2->volts << endl;
	cout << "BEsar kuat arus motor 2diakses dari mtr1 " << mtr1->next->amps;
	
	//Membebaskan alokasi memori yang dipesan
	free(mtr1);
	free(mtr2);
	
	}
	
	return 0;
}
