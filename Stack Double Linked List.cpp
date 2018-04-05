#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct node {
	int data;
	struct node *next;
	struct node *prev;
};

struct stack {
	int count;
	node *top;
};

void push ();
void pop ();
void cetak ();
void mainmenu ();
void exit ();
void hapus ();
void dataAtas ();

stack head;
node *pNew, *temp;
int pilMenu, jml, angka, bantu;
char pilih;

int main (){
	head.count=0;
	head.top=NULL;
	mainmenu();
return 0;
}
void mainmenu(){
	cout << "========================\n";
	cout << "|      MENU UTAMA    	|\n";
	cout << "========================\n";
	cout << "1. Push\n";
	cout << "2. Pop\n";
	cout << "3. Data teratas\n";
	cout << "4. Cetak Semua Data\n";
	cout << "5. Hapus Semua Data\n";
	cout << "6. Exit\n";
	cout << "========================\n";
	cout << endl;
	cetak();
	cout << endl;
	cout << "Masukan menu pilihan anda : "; cin >> pilMenu;
	switch (pilMenu){
		case 1:
			push();
			break;
		case 2:
			pop ();
			break;
		case 3:
			cout << "\nList teratas anda adalah : " << head.top->data;
			cout << "\nAnda ingin kembali ke Main Menu? (Y/N)"; cin >> pilih;
			if (pilih == 'y' || pilih == 'Y'){
				system ("cls");
				mainmenu();
			} else if (pilih == 'n' || pilih == 'N') {
				exit();
			}
			break;
		case 4:
			system("cls");
			cetak();
			cout << "\nAnda ingin kembali ke Main Menu? (Y/N)"; cin >> pilih;
			if (pilih == 'y' || pilih == 'Y'){
				system ("cls");
				mainmenu();
			} else if (pilih == 'n' || pilih == 'N') {
				exit();
			}
			break;
		case 5:
			hapus();
			break;
		default:
			exit();
			break;
	}
}

void push(){
	cout << "Masukan jumlah node yang diinginkan : "; cin >> jml;
	for (int i=0; i<jml; i++){
		cout << "Masukan data yang ingin di-push : "; cin >> angka;
		pNew = (node*)malloc(sizeof(node));
		if (pNew!=NULL){
			pNew->data = angka;
		} if (head.top == NULL){
			head.top = pNew;
			pNew->next = NULL;
			pNew->prev = NULL;
		} else {
			pNew->next = head.top;
			head.top=pNew;
			pNew->prev=pNew;
		}
		head.count++;
	}
	cetak ();
	cout << "Anda ingin kembali ke Main Menu? (Y/N)"; cin >> pilih;
			if (pilih == 'y' || pilih == 'Y'){
				system ("cls");
				mainmenu();
			} else if (pilih == 'n' || pilih == 'N') {
				exit();
			}
}

void pop (){
	if(head.top!=NULL){
		temp = head.top;
		head.top = temp->next;
		
		free(temp);
		cout << endl;
		cetak();
		system("cls");
		head.count--;
		mainmenu();
} else {
	cout << "Anda belum memiliki list atau";
	cout << "\nList yang anda masukan telah terhapus semua\n\n";
	cout << "Anda ingin kembali ke Main Menu? (Y/N)"; cin >> pilih;
			if (pilih == 'y' || pilih == 'Y'){
				system ("cls");
				mainmenu();
			} else if (pilih == 'n' || pilih == 'N') {
				exit();
		}
	}
}

void cetak(){
	temp=head.top;
	cout << "List anda adalah : ";
	if(temp != NULL){
		while(temp!=NULL){
			cout << temp->data <<" ";
			temp=temp->next;
		}
	}
	cout << endl;
}

void hapus(){
	while(head.top!=NULL){
		if(head.top!=NULL){
			temp = head.top;
			head.count--;
			head.top = temp->next;
			free(temp);
		}
	}
	cout << "List anda telah terhapus semua" << endl;
	cout << "Anda ingin kembali ke Main Menu? (Y/N)"; cin >> pilih;
			if (pilih == 'y' || pilih == 'Y'){
				system ("cls");
				mainmenu();
			} else if (pilih == 'n' || pilih == 'N') {
				exit();
			}
}

void exit(){
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "==================================================\n";
	cout << ">> TERIMA KASIH TELAH MENGGUNAKAN APLIKASI KAMI <<\n";
	cout << "==================================================\n";
}
