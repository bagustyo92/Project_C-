#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
struct data_brg {
	struct data_brg *prev;
	int node;
	char* brg;
	double hrg;
	int jml;
	struct data_brg *next;
};
typedef struct data_brg data;
struct stacks {
	struct data_brg *top;
	int count;
};
struct queue {
	data *front;
	int count;
	data *rear;
};

data *head;
stacks stack;
queue antri;

char* item1="Sabun Mandi ";
double item1_hrg=7000;
char* item2="Minyak Angin";
double item2_hrg=10000;
char* item3="Shampo Bayi ";
double item3_hrg=20000;
char* item4="Tolak Angin ";
double item4_hrg=3000;
char* item5="Tisu Basah  ";
double item5_hrg=8000;

data *pNew, *temp, *transverse, *pPre, *pEdit;
double total, subtotal, total_item, diskon, ppn, tunai;
int nomer, pil, bil, counter;
char pilih;
bool ketemu, bayar;

void cetakList();
void menustack();
void menuqueue();
void push();
int main();

void appendNode(data *temp){
	if(head==NULL){
		temp->next=NULL;
	} else {
		head->prev=temp;
		temp->next=head;
	}
	temp->prev=NULL;
	head=temp;
	stack.top=temp;
	stack.count++;
}
void push(data *head){
	do{
		system("cls");
		pNew=(data *)malloc(sizeof(data));
		cout<<"====================================\n";
	   	cout<<"|            Daftar Menu           |\n";
		cout<<"====================================\n";
		cout<<"|  No.\tNama\t\t Harga     |"<<endl;
		cout<<"|  1.\t"<<item1<<"\t Rp "<<item1_hrg<<"   |"<<endl;
		cout<<"|  2.\t"<<item2<<"\t Rp "<<item2_hrg<<"  |"<<endl;
		cout<<"|  3.\t"<<item3<<"\t Rp "<<item3_hrg<<"  |"<<endl;
		cout<<"|  4.\t"<<item4<<"\t Rp "<<item4_hrg<<"   |"<<endl;
		cout<<"|  5.\t"<<item5<<"\t Rp "<<item5_hrg<<"   |"<<endl;
		cout<<"|  6.\tKembali ke Menu Utama      |"<<endl;
		cout<<"====================================\n";
		cout<<"\nMasukkan pilihan anda [1-6] ? ";cin>>pil;
		pNew->node=pil;
		if(pil>=1 && pil<=5){
			cout<<"Masukkan jumlah item yang dibeli : ";cin>>pNew->jml;	
		}
		if(pil==1){
			pNew->brg=item1;
			pNew->hrg=item1_hrg;
		} else if (pil==2){
			pNew->brg=item2;
			pNew->hrg=item2_hrg;			
		} else if (pil==3){
			pNew->brg=item3;
			pNew->hrg=item3_hrg;		
		} else if (pil==4){
			pNew->brg=item4;
			pNew->hrg=item4_hrg;		
		} else if (pil==5){
			pNew->brg=item5;
			pNew->hrg=item5_hrg;		
		} else if (pil==6){
			main();
		} else {
			cout<<"keyword salah";
		}
		appendNode(pNew);
		cout<<"ingin lakukan lagi (y/n) ? " ;cin>>pilih;
	}while((pilih=='Y')||(pilih=='y'));
	if((pilih=='N') || (pilih=='n')) {
		menustack();	
	}
}
void pop(data *head){
	cout<<endl;
	if(stack.top==NULL){
		cout<<"belum ada keranjang pak!"<<endl;	
	} else {
		cout<<"Anda yakin akan menghapus barang secara stack (y/n) ? ";cin>>pilih;
		if(pilih=='y' || pilih=='Y'){
			pPre=stack.top;
			stack.top=stack.top->next;
			stack.count--;
			free(pPre);
			head=stack.top;
			cout<<"Hapus Secara Stack Berhasil!"<<endl;	
		} else {
			cout<<"Penghapusan data dibatalkan"<<endl;
		}	
	}
	getch();
	menustack();
}
void edit(data *head){
	do {
		if(stack.top==NULL){
			cout<<"\nbelum ada keranjang pak!"<<endl;
			getch();
			main();
		} else {
			system("cls");
			ketemu=true;
			cout<<"Keranjang Sebelumnya : "<<endl;
			cetakList();
			cout<<"\n\nMasukkan nomor barang yg akan diganti\t: ";
			cin>>bil;
			counter=0;
			pEdit=head;
			while (pEdit!=NULL){
				counter++;
				if (counter==bil){
					break;
				}
				pEdit=pEdit->next;
			}
			if(counter==bil){
				cout<<"Masukkan jumlah barang pengganti\t: ";
				cin>>pEdit->jml;
				cout<<"Penggantian jumlah barang sukses!"<<endl;
			} else {
				cout<<"Node tidak ditemukan"<<endl;
			}
			cout<<"\ningin lakukan lagi ? (y/n) " ;cin>>pilih;
		}
	}while((pilih=='Y')||(pilih=='y'));
	if((pilih=='N') || (pilih=='n')) {
		menustack();	
	}
}
void cetakList(){
	transverse=stack.top;
	total=total_item=0;
	nomer=1;
	cout<<endl;
	if(stack.top==NULL){
		cout<<"belum ada keranjang pak!"<<endl;
	} else {
		cout<<"No.\tNama Barang\tHarga\tJumlah\tSubtotal"<<endl;
		while(transverse!=NULL){
			subtotal=((transverse->hrg)*(transverse->jml));
			cout<<nomer++<<".\t";
			cout<<transverse->brg<<"\t";
			cout<<transverse->hrg<<"\t";
			cout<<transverse->jml<<"\t";
			cout<<subtotal<<endl;
			total_item=total_item+transverse->jml;
			total=total+subtotal;
			transverse=transverse->next; 
		}
		cout<<"================================================="<<endl; 
		if(total_item>30){
			diskon=0.3*total;
		} else if(total_item>20){
			diskon=0.2*total;
		} else if(total_item>10){
			diskon=0.1*total;
		} else {
			diskon=0;
		}
		ppn=0.1*total;
		if(bayar==false){
			cout<<"\t\t\t\tTOTAL\t"<<total;		
		} else {
			cout<<"\t\t\t\tDISKON\t"<<diskon<<endl;
			cout<<"\t\t\t\tPPN\t"<<ppn<<endl;
			total=(total-diskon)+ppn;
			cout<<"\t\t\t\tTOTAL\t"<<total<<endl;
			cout<<"\t\t\t\tTUNAI\t";cin>>tunai;
			cout<<"------------------------------------------------"<<endl;
			cout<<"\t\t\t\tKEMBALI\t"<<tunai-total<<endl;
			cout<<"\n\n\n\t\t    TERIMA KASIH"<<endl;
			cout<<"\t\t        DAN"<<endl;
			cout<<"\t\tSELAMAT BERBELANJA KEMBALI\n\n"<<endl;
		}
	}
	if (ketemu==false && bayar==false){
		getch();
		menustack();	
	}
}
void payment(data *head){
	bayar=true;
	system("cls");
	cout<<endl;
	cout<<"\t\t   DATA TRANSAKSI"<<endl<<endl;
	printf("%s", __DATE__);
 	printf("\t\t\t\t%s", __TIME__);
 	cout<<"\n------------------------------------------------";
 	cetakList();
}

void exit(){
	cout<<"KEYWORD ANDA SALAH\n";
	cout<<"\n============================================";
	cout<<"\nTerima Kasih telah menggunakan aplikasi kami";
	cout<<"\n============================================";
}

void appendNodeQueue(data *temp){
	if(head==NULL){
		temp->prev=NULL;
		head=temp;
		antri.front=temp;
	} else {
		antri.rear->next=temp;
		temp->prev=antri.rear;
	}
	temp->next=NULL;
	antri.rear=temp;
	antri.count++;
}
void enqueue(data *head){
	do{
		system("cls");
		pNew=(data *)malloc(sizeof(data));
		cout<<"====================================\n";
	   	cout<<"|            Daftar Menu           |\n";
		cout<<"====================================\n";
		cout<<"|  No.\tNama\t\t Harga     |"<<endl;
		cout<<"|  1.\t"<<item1<<"\t Rp "<<item1_hrg<<"   |"<<endl;
		cout<<"|  2.\t"<<item2<<"\t Rp "<<item2_hrg<<"  |"<<endl;
		cout<<"|  3.\t"<<item3<<"\t Rp "<<item3_hrg<<"  |"<<endl;
		cout<<"|  4.\t"<<item4<<"\t Rp "<<item4_hrg<<"   |"<<endl;
		cout<<"|  5.\t"<<item5<<"\t Rp "<<item5_hrg<<"   |"<<endl;
		cout<<"|  6.\tKembali ke Menu Utama      |"<<endl;
		cout<<"====================================\n";
		cout<<"\nMasukkan pilihan anda [1-6] ? ";cin>>pil;
		pNew->node=pil;
		if(pil>=1 && pil<=5){
			cout<<"Masukkan jumlah item yang dibeli : ";cin>>pNew->jml;	
		}
		if(pil==1){
			pNew->brg=item1;
			pNew->hrg=item1_hrg;
		} else if (pil==2){
			pNew->brg=item2;
			pNew->hrg=item2_hrg;			
		} else if (pil==3){
			pNew->brg=item3;
			pNew->hrg=item3_hrg;		
		} else if (pil==4){
			pNew->brg=item4;
			pNew->hrg=item4_hrg;		
		} else if (pil==5){
			pNew->brg=item5;
			pNew->hrg=item5_hrg;		
		} else if (pil==6){
			main();
		} else {
			cout<<"keyword salah";
		}
		appendNodeQueue(pNew);
		cout<<"ingin lakukan lagi (y/n) ? " ;cin>>pilih;
	}while((pilih=='Y')||(pilih=='y'));
	if((pilih=='N') || (pilih=='n')) {
		menuqueue();	
	}
}
void dequeue(data *head){
	cout<<endl;
	if(antri.front==NULL){
		cout<<"belum ada keranjang pak!"<<endl;	
	} else {
		cout<<"Anda yakin akan menghapus barang secara deQueue (y/n) ? ";cin>>pilih;
		if(pilih=='y' || pilih=='Y'){
			pPre=antri.front;
			antri.front=antri.front->next;
			antri.count--;
			free(pPre);
			head=antri.front;
			cout<<"Hapus Secara Queue Berhasil!"<<endl;	
		} else {
			cout<<"Penghapusan data dibatalkan"<<endl;
		}	
	}
	getch();
	menuqueue();
}
void editqueue(data *head){
	do {
		if(antri.front==NULL){
			cout<<"\nbelum ada keranjang pak!"<<endl;
			getch();
			main();
		} else {
			system("cls");
			ketemu=true;
			cout<<"Keranjang Sebelumnya : "<<endl;
			cetakList();
			cout<<"\n\nMasukkan nomor barang yg akan diganti\t: ";
			cin>>bil;
			counter=0;
			pEdit=head;
			while (pEdit!=NULL){
				counter++;
				if (counter==bil){
					break;
				}
				pEdit=pEdit->next;
			}
			if(counter==bil){
				cout<<"Masukkan jumlah barang pengganti\t: ";
				cin>>pEdit->jml;
				cout<<"Penggantian jumlah barang sukses!"<<endl;
			} else {
				cout<<"Node tidak ditemukan"<<endl;
			}
			cout<<"\ningin lakukan lagi ? (y/n) " ;cin>>pilih;
		}
	}while((pilih=='Y')||(pilih=='y'));
	if((pilih=='N') || (pilih=='n')) {
		main();	
	}
}
void cetakListqueue(){
	transverse=antri.front;
	total=total_item=0;
	nomer=1;
	cout<<endl;
	if(antri.front==NULL){
		cout<<"belum ada keranjang pak!"<<endl;
	} else {
		cout<<"No.\tNama Barang\tHarga\tJumlah\tSubtotal"<<endl;
		while(transverse!=NULL){
			subtotal=((transverse->hrg)*(transverse->jml));
			cout<<nomer++<<".\t";
			cout<<transverse->brg<<"\t";
			cout<<transverse->hrg<<"\t";
			cout<<transverse->jml<<"\t";
			cout<<subtotal<<endl;
			total_item=total_item+transverse->jml;
			total=total+subtotal;
			transverse=transverse->next; 
		}
		cout<<"================================================="<<endl; 
		if(total_item>30){
			diskon=0.3*total;
		} else if(total_item>20){
			diskon=0.2*total;
		} else if(total_item>10){
			diskon=0.1*total;
		} else {
			diskon=0;
		}
		ppn=0.1*total;
		if(bayar==false){
			cout<<"\t\t\t\tTOTAL\t"<<total;		
		} else {
			cout<<"\t\t\t\tDISKON\t"<<diskon<<endl;
			cout<<"\t\t\t\tPPN\t"<<ppn<<endl;
			total=(total-diskon)+ppn;
			cout<<"\t\t\t\tTOTAL\t"<<total<<endl;
			cout<<"\t\t\t\tTUNAI\t";cin>>tunai;
			cout<<"------------------------------------------------"<<endl;
			cout<<"\t\t\t\tKEMBALI\t"<<tunai-total<<endl;
			cout<<"\n\n\n\t\t    TERIMA KASIH"<<endl;
			cout<<"\t\t        DAN"<<endl;
			cout<<"\t\tSELAMAT BERBELANJA KEMBALI\n\n"<<endl;
		}
	}
	if (ketemu==false && bayar==false){
		getch();
		menuqueue();	
	}
}
void paymentqueue(data *head){
	bayar=true;
	system("cls");
	cout<<endl;
	cout<<"\t\t   DATA TRANSAKSI"<<endl<<endl;
	printf("%s", __DATE__);
 	printf("\t\t\t\t%s", __TIME__);
 	cout<<"\n------------------------------------------------";
 	cetakListqueue();
}


int main(){
	system("cls");
	cout << "=======================================" << endl;
	cout << "|MENU PEMILIHAN PROGRAM STRUK BELANJA |" << endl;
	cout << "=======================================" << endl;
	cout << "|                                     |" << endl;
	cout << "|1. Program Struk Belanja dengan STACK|" << endl;
	cout << "|2. Program Struk Belanja dengan QUEUE|" << endl;
	cout << "|3. Keluar Program                    |" << endl;
	cout << "|                                     |" << endl;
	cout << "=======================================" << endl;
	cout<<"\nMasukkan pilihan anda [1-3] ? ";cin>>pil;
	switch(pil){
		case 1:
			menustack();
		break;
		case 2:
			menuqueue();
		break;
		default:
			cout<<"\n============================================";
	cout<<"\nTerima Kasih telah menggunakan aplikasi kami";
	cout<<"\n============================================";
		break;
	}
}


void menustack (){
	system("cls");
 	cout<<endl;
	ketemu=false;
	cout<<"SELAMAT DATANG DI TOKO ADANYA GITU AJA"<<endl;
	cout<<endl;
	cout<<"======================================\n";
   	cout<<"|              Menu Utama            |\n";
	cout<<"======================================\n";
	cout<<"|          1. Tambah Barang          |"<<endl;
	cout<<"|          2. Hapus Barang           |"<<endl;
	cout<<"|          3. Edit Barang            |"<<endl;
	cout<<"|          4. Cetak Barang           |"<<endl;
	cout<<"|          5. Pembayaran             |"<<endl;
	cout<<"|          6. Keluar                 |"<<endl;
	cout<<"======================================\n";
	cout<<"\nMasukkan pilihan anda [1-6] ? ";cin>>pil;
	switch(pil){
		case 1:
			push(head);			
		break;
		case 2:
			pop(head);
		break;
		case 3:
			edit(head);
		break;
		case 4:
			cetakList();
		break;
		case 5:
			payment(head);
		break;
		default:
			exit();
		break;
		}
}
void menuqueue (){
	system("cls");
 	cout<<endl;
	ketemu=false;
	cout<<"SELAMAT DATANG DI TOKO ADANYA GITU AJA"<<endl;
	cout<<endl;
	cout<<"======================================\n";
   	cout<<"|              Menu Utama            |\n";
	cout<<"======================================\n";
	cout<<"|          1. Tambah Barang          |"<<endl;
	cout<<"|          2. Hapus Barang           |"<<endl;
	cout<<"|          3. Edit Barang            |"<<endl;
	cout<<"|          4. Cetak Barang           |"<<endl;
	cout<<"|          5. Pembayaran             |"<<endl;
	cout<<"|          6. Keluar                 |"<<endl;
	cout<<"======================================\n";
	cout<<"\nMasukkan pilihan anda [1-6] ? ";cin>>pil;
	switch(pil){
		case 1:
			enqueue(head);			
		break;
		case 2:
			dequeue(head);
		break;
		case 3:
			editqueue(head);
		break;
		case 4:
			cetakListqueue();
		break;
		case 5:
			paymentqueue(head);
		break;
		default:
			exit();
		break;
	}
}
