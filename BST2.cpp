#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct node {
	int data;
    struct node *right;
    struct node *left;
};
typedef struct node node;
node *createNode(int bil);
void insert(node **root, node *newNode);
void insert_modif(node **root, node *newNode);
void inorder(node *root);
void inorder_modif(node *root);
void preorder(node *root);
bool deleteNode(node **root, int key);
bool deleteNode_modif(node **root, int key);
node *findLargestBST(node *root);
void deleteBST(node **root);
main(){
  node *root, *pNew;
  char pilih;
  int bil;
  bool success;
  root = NULL;
  do{
   		system("cls");
		cout<<"MASUKAN PILIHAN\n";
		cout<<"1. MASUKAN DATA\n";
		cout<<"2. HAPUS DATA\n";
		cout<<"3. CETAK DATA TREE SECARA INORDER\n";
		cout<<"4. CETAK DATA TREE SECARA PREORDER\n";
		cout<<"TEKAN p UNTUK KELUAR \n";
		cout<<"MASUKAN PILIHAN ANDA = "; 
		fflush(stdin);
		cin>>pilih;
     if (pilih == '1'){
     		cout<<"nilai yang akan dimasukkan ke tree: ";
         cin>>bil;
         pNew = createNode(bil);
         if (pNew == NULL){
         	cout<<"insert gagal";
            getch();
         }
         else
            insert_modif(&root, pNew);
     }
     else if (pilih == '2'){
     		cout<<"nilai yang akan dihapus : ";
         cin>>bil;
     		success = deleteNode(&root, bil);
         if(!success){
         	cout<<"\ndata gagal dihapus";
         	getch();
         }
     }
     else if (pilih=='4'){
			cout<<"preorder\n";
			preorder(root);
			getch();
     }
     else if (pilih == '3'){
			cout<<"inorder\n";
		inorder_modif(root);
        getch();
     }
  } while (pilih != 'p');
  deleteBST(&root);
}
node *createNode(int bil){
   node *pNew;

   pNew = (node *)malloc(sizeof(node));
   if (pNew != NULL){
      pNew->data = bil;
      pNew->left = NULL;
      pNew->right = NULL;
   }
   return(pNew);
}

void insert(node **root, node *newNode){
	if(*root == NULL)
		*root = newNode;
   	else if (newNode->data < (*root)->data)
    	insert(&((**root).left), newNode);
   	else
    	insert(&((**root).right), newNode);
}
void insert_modif(node **root, node *newNode){
	if(*root == NULL)
   		*root = newNode;
   	else if (newNode->data < (*root)->data)
    	insert_modif(&((**root).right), newNode);
   	else
    	insert_modif(&((**root).left), newNode);
}
void inorder(node *root){
	if (root == NULL) return;
		inorder(root->left);
		cout<<" ";
    	cout<<root->data;
    	inorder(root->right);
    	getch();
}
void inorder_modif(node *root){
	if (root == NULL) return;
		inorder_modif(root->right);
		cout<<" ";
    	cout<<root->data;
    	inorder_modif(root->left);
    	getch();
}
/*void inorder_modif (node *root) {
	if (root == NULL) return;
		inorder_modif(root->right);
		cout << root->data  << " ";
		inorder_modif(root->left);
}*/
void preorder(node *root){
	if(root==NULL) return;
	cout<<" ";
	cout<<root->data;
	preorder(root->left);
	preorder(root->right);
	getch();
}
node *findLargestBST(node *root){
	if (root ->right == NULL)
   	return(root);
   else
   	return(findLargestBST(root->right));
}

bool deleteNode(node **root, int key){
   node *pDel;
   node *pReplace;

	if(*root == NULL)
   	return(false);
   else if (key < (*root)->data)
      return(deleteNode(&((**root).left), key));
   else if (key > (*root)->data)
      return(deleteNode(&((**root).right), key));
   else{
   	if ((*root)->left == NULL && (*root)->right == NULL){
      	pDel = *root;
         *root = NULL;
         free(pDel);
         return(true);
      }
      else if ((*root)->left == NULL){
      	pDel = *root;
         *root = (*root)-> right;
         free(pDel);
         return(true);
      }
      else if ((*root)->right == NULL){
      	pDel = *root;
         *root = (*root)-> left;
         free(pDel);
         return(true);
      }
      else{
      	pDel = *root;
         pReplace = findLargestBST((*root)->left);
         pDel->data = pReplace->data;
         return (deleteNode(&((**root).left), pReplace->data));
      }
   }
}
bool deleteNode_modif (node **root, int key){
	if(*root == NULL)
   		return(false);
	 else if (key > (*root)->data) {
	deleteNode_modif (&(*root)->left, key);
	} else if (key < (*root)->data) {
	deleteNode_modif (&(*root)->right, key);
	} else {
		if ((*root)->left == NULL) {
			(*root) = (*root)->right;
			return true;
		} else if ((*root)->right == NULL) {
			(*root) = (*root)->left;
		} else {
			node *hapus=*root, *terbesar=findLargestBST((*root)->left);
			hapus->data=terbesar->data;
			return deleteNode_modif((&(hapus->right)),terbesar->data);				
		}
	}
}
void deleteBST(node **root){
	while(*root != NULL)
   	deleteNode(root, (*root)->data);
}
void delete_modif(node **root) {
	node *terkecil = findLargestBST(*root);
    deleteNode_modif (root, terkecil->data);
}
