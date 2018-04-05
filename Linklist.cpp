#include <iostream>
#include <stdlib.h>

using namespace std;

struct motor { 
	float volts;
	float amps;
	struct motor *next; //sebagai linklist
};


int main (){
	//Deklarasi pointer
	motor *pm1, *pm2, *pm3;
	
	//Membuat pm1-pm3 dengan memori dinamis
	pm1 = (motor*)malloc(sizeof(motor));
	pm2 = (motor*)malloc(sizeof(motor));
	pm3 = (motor*)malloc(sizeof(motor));
	
	if (pm1 != NULL && pm2 != NULL && pm3 != NULL){
		//Memberikan nilai sembarang dengan memori dinamis
		pm1->amps = 10;
		pm1->volts = 20;
		pm2->amps = 30;
		pm2->volts = 40;
		pm3->amps = 50;
		pm3->volts = 60;
		
		//menghubungkan pm1-pm3 dengan linklist	
		pm1->next = pm2;
		pm2->next = pm3;
		pm3->next = NULL;
		
		//Menampilkan semua data pm2 hanya dengan pointer pm1
		cout << "Isi volts dari pm2 yang diakses dari pm1 adalah : " << pm1->next->volts;
		cout << "\nIsi amps dari pm2 yang diakses dari pm1 adalah : " << pm1->next->amps;
		
		//Menampilkan semua data pm3 hanya dengan pointer pm2
		cout << "\n\nIsi volts dari pm3 yang diakses dari pm2 adalah : " << pm2->next->volts;
		cout << "\nIsi amps dari pm3 yang diakses dari pm2 adalah : " << pm2->next->amps;
		
		//Menampilkan semua data pm3 hanya dengan pointer pm1
		cout << "\n\nIsi volts dari pm3 yang diakses dari pm1 adalah : " << pm1->next->next->volts;
		cout << "\nIsi amps dari pm3 yang diakses dari pm1 adalah : " << pm1->next->next->amps;
		
		free(pm1);
		free(pm2);
		free(pm3);
	}
	return 0;
}
