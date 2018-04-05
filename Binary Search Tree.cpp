#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include "screen.h"

using namespace std;

//===============================

struct node {
	int data;
	struct node *right;
	struct node *left;
};typedef struct node node;

node *createNode (int bil);
void insert(node **root, node *newnode);
void inorder(node *root);
void preorder(node *root);
void postorder(node *root);
void inorder_reverse(node *root);
node *findLargestBST(node  *root);
bool deleteNode(node **root, int key);
bool deleteNode_modif (node **root, int key);
void deleteBST(node **root);
bool modif;
void tampilkan (node *akar);
void menu(node *akar);

//===============================

bool isEmpty(node *parameter) {
	if (parameter == NULL) {
		return true;
	} else{
	return false;
	}
}

void cin_fail() {
if (cin.fail()) { 
cout << "Data yang anda masukkan Salah";
cin.ignore();
cin.clear();
}
}
	
int main() {
	modif = false;
	node *akar = NULL;
	scrn.title_screen();
	akar = NULL;
	menu(&(*akar));
	}

node *createNode (int bil) {
	node *baru;
	
	baru = (node *)malloc(sizeof(node));
	
	if (baru != NULL) {
		baru->data = bil;
		baru->left = NULL;
		baru->right = NULL;
	}
	return (baru);
}

void insert (node **root, node *newnode){
	if (isEmpty(*root)) {
	*root = newnode;
	} else {
		if (!modif) {
		if (newnode->data < (*root)->data) {
			insert (&(*root)->left, newnode);
		} else if (newnode->data >= (*root)->data) {
			insert (&(*root)->right, newnode);
		} 

	} else {
		if (newnode->data <= (*root)->data) {
			insert (&(*root)->right, newnode);
		} else if (newnode->data > (*root)->data) {
			insert (&(*root)->left, newnode);
		} 
		
		}
	}
	
}
 
void inorder(node *root) {
	if (!isEmpty(root)) {
		inorder(root->left);
		cout << root->data << " ";
		inorder (root->right);
	}
}

void inorder_reverse (node *root) {
	if (!isEmpty(root)) {
	inorder_reverse(root->right);
	cout << root->data  << " ";
	inorder_reverse(root->left);
	}
}

void postorder (node *root){     
	if(!isEmpty(root)){                    
		postorder(root->left);                     
		postorder (root->right);                     
		cout << root->data << " ";                    
	}      
}

void preorder (node *root){    
	if(!isEmpty(root)){                   
		cout << root->data << " ";                   
		preorder(root->left);                    
		preorder (root->right);                    
	}      
}

node *findLargestBST (node *root) {
	if (root->right == NULL)
	return (root);
	else
	return(findLargestBST(root->right));
}

bool deleteNode (node **root, int key){
	if (isEmpty(*root)) {
	return false;
	} else if (key < (*root)->data) {
	deleteNode (&(*root)->left, key);
	} else if (key > (*root)->data) {
	deleteNode (&(*root)->right, key);
	} else {
		if (isEmpty((*root)->left)) {
		(*root) = (*root)->right;
		return true;
		} else if (isEmpty((*root)->right)) {
			(*root) = (*root)->left;
			} else {
			node *hapus=*root, *terbesar=findLargestBST((*root)->left);
			hapus->data=terbesar->data;
			return deleteNode((&(hapus->left)),terbesar->data);	
			
			}
		
		}
	
 	}
	
bool deleteNode_modif (node **root, int key){
	if (isEmpty(*root)) {
	return false;
	} else if (key > (*root)->data) {
	deleteNode_modif (&(*root)->left, key);
	} else if (key < (*root)->data) {
	deleteNode_modif (&(*root)->right, key);
	} else {
		if (isEmpty((*root)->left)) {
		(*root) = (*root)->right;
		return true;
		} else if (isEmpty((*root)->right)) {
			(*root) = (*root)->left;
			} else {
			node *hapus=*root, *terbesar=findLargestBST((*root)->left);
			hapus->data=terbesar->data;
			return deleteNode_modif((&(hapus->right)),terbesar->data);	
			
			}
		
		}
	
 	}

void deleteBST(node **root) {
	while(*root != NULL)
	if (!modif) {
		deleteNode (root, (*root)->data);
	} else {
	    deleteNode_modif (root, (*root)->data);
	}
}

void delete_modif(node **root) {
	node *terkecil = findLargestBST(*root);
    deleteNode_modif (root, terkecil->data);
}

void cari (node* parameter2, int key) {
	bool ketemu = false;
	node *parameter = new node;
	parameter = parameter2;
	scrn.search_screen();
	if (!modif) {
		while (!ketemu) {
			if (parameter->data == key) {
				ketemu = true;
				break;
				} else if (parameter->data < key) {
					if (parameter->right == NULL) break;
			         parameter = parameter->right;
			} else if (parameter->data > key) {
				   if (parameter->left == NULL) break;
				parameter = parameter->left;
			   } 
		  }

	} else {
		while (!ketemu) {
			if (parameter->data == key) {
				ketemu = true;
				break;
				} else if (parameter->data < key) {
					if (parameter->left == NULL) break;
			         parameter = parameter->left;
			} else if (parameter->data > key) {
				   if (parameter->right == NULL) break;
				parameter = parameter->right;
			   } 
		  }
	
	}

	if (ketemu) {
		cout << "Data Ditemukan...";
		} else {
		cout << "Data tidak ditemukan...";
		}
		_getch();
	
}

void tampilkan(node *akar) {
	short pil;
	cout << "     TAMPILKAN" << endl;
	cout << "================" << endl;
	cout << "1. Tampilkan secara Pre-Order\n";
	cout << "2. Tampilkan secara In-Order\n";
	cout << "3. Tampilkan secara Post-Order\n";
	if (modif) cout << "4. Tampilkan secara In-Order Reverse\n";
	
	do {
	cin_fail();
	cout << "Masukkan Pilihan Anda :" ;
	cin >> pil;
	} while (cin.fail() || pil < 1 || pil > 4);

	switch (pil) {
	case 1 : preorder(akar);
			 _getch();
			break;
	case 2 : inorder(akar);
			_getch();
			break;
	case 3 : postorder(akar);
			_getch();
			break;
	case 4 : if (modif) {
		       inorder_reverse(akar);
			   _getch();
			 } else {
			 cout << "Modif belum diaktifkan...";
			 }
			 break;
	}
	}

void hapus (node *akar) {
	short pil, bil;
	bool berhasil;
	cout << "      HAPUS " << endl;
	cout << "================" << endl;
	cout << "1. Hapus 1 Data\n";
	cout << "2. Hapus Semua Data\n";
	if (modif) cout << "3. Hapus versi Modif\n";

	do {
		cin_fail();
		cout << "Masukkan pilihan anda :" << endl;
		cin >> pil;
	} while (cin.fail() || pil <1 || pil> 3);

	switch (pil) {
	case 1 :     system("cls");
	            cout << "Nilai yang akan dihapus : ";
				cin >> bil;
				if (!modif) berhasil = deleteNode(&akar, bil);
				else {
				     berhasil = deleteNode_modif(&akar, bil);
				}

				if (berhasil) {
					cout << "\nData berhasil dihapus";
				} else {
				    cout << "\nData gagal dihapus";
				}
				_getch();
				menu(akar);
				break;
	case 2 :  system ("cls");
			  deleteBST(&akar);
			  cout << "Semua data berhasil di hapus!";
			  _getch();
			  menu(akar);
			  break;
	case 3 : system ("cls");
			if (!modif) cout << "Modif belum diaktifkan !";
			else{
        	delete_modif(&akar);
			menu(akar);
			}

	}

}

void menu(node *akar) {
	system("cls");
	node *pNew;
	short pil; int bil;
// Main menu 
	    cout << "      MENU" << endl;
		cout << "==================" << endl ;
		cout << "1. Tambah Data\n";
		cout << "2. Tampilkan Data\n";
		cout << "3. Cari Data\n";
		cout << "4. Hapus Data\n";
		cout << "5. Switch ke ";
		  if (!modif)  {
			  cout << "Modif mode\n";
		  }else  {
			 cout << "Normal mode\n";
		  }
		  cout << "6. Keluar\n" << endl;

		do {
		cin_fail();
		cout << "Masukkan Pilihan : ";
		cin >> pil;
		} while (cin.fail() || pil < 1 || pil >6);

		switch (pil) {
		case 1 : system ("cls");
				cout << "Masukkan Nilai ke BST : ";
				cin >> bil;
				    pNew = createNode(bil);
					if (pNew == NULL) {
					cout << "Insert gagal";
					_getch();	
					} else {
						insert (&akar, pNew);
					}
					menu(akar);
					break;
		case 2 : system ("cls");

			if (!isEmpty(akar)) {
				tampilkan(akar);
			} else {
			cout << "Data Kosong" << endl;
			_getch();
			}
			menu(akar);
			     break;

		case 3 : system("cls");
			if (!isEmpty(akar)) {
					cout << "Masukkan data yang ingin anda cari : ";
	                 cin >> bil;
					 cari (akar, bil);
			} else {
			cout << "Data Kosong!";
			_getch();
			}
			menu(akar);
					break;

		
      case 4 : system ("cls");
		  if (!isEmpty(akar)) {
			   hapus(akar);
		  } else {
		  cout << "Data Kosong..." << endl;
		  _getch();
		  }
			   break;

	  case 5 : system ("cls");
		  if (!isEmpty(akar) ) {
		  cout << "Data akan di reset otomatis!" << endl;
		        deleteBST(&akar);
		  }
				if (modif) { 
				modif = false;
				cout << "Mode diubah menjadi Normal Mode";
				}
				else{
					modif = true;
                cout << "Mode diubah menjadi Modif Mode";
				}
				_getch();
				menu(akar);
					break;
	  case 6 : scrn.exit_screen();
					 break;

		}
	

}