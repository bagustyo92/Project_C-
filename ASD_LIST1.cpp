#include <iostream>
#include <stdlib.h>

using namespace std; 

struct kompleks{
	float a;
	float b;
	struct kompleks *next;
};
typedef struct kompleks kompleks;

int main(){
	kompleks *head, *pNew, *temp;
	int i;
	
	head=NULL;
	pNew=(kompleks *)malloc(sizeof(kompleks));
	if(pNew != NULL){
		pNew->a=5;
		pNew->b=6;
		pNew->next=head;
		head=pNew;
		cout<<head->next<<endl;
	}
	pNew=(kompleks *)malloc(sizeof(kompleks));
	if(pNew != NULL){
		pNew->a=3;
		pNew->b=4;
		pNew->next=head;
		head=pNew;
		cout<<head->next<<endl;
	}
	pNew=(kompleks *)malloc(sizeof(kompleks));
	if(pNew != NULL){
		pNew->a=1;
		pNew->b=2;
		pNew->next=head;
		head=pNew;
		cout<<head->next<<endl;
	}
	temp = head;
	cout<<"Data A - Node 1 : "<<head->a<<endl;
	cout<<"Data A - Node 2 : "<<head->b<<endl;	
	cout<<"Data B - Node 1 : "<<head->next->a<<endl;
	cout<<"Data B - Node 2 : "<<head->next->b<<endl;
	cout<<"Data C - Node 1 : "<<temp->next->next->a<<endl;
	cout<<"Data C - Node 2 : "<<temp->next->next->b<<endl;
	
	temp = head;
	i = 0;
	while (temp != NULL){
		i++;
		cout<<"pointer temp sekarang menunjuk node ke "<<i<<endl;
		cout<<temp->next<<endl;
		temp=temp->next;
	}
	cout<<"pointer temp sekarang menunjuk NULL"<<endl;

	temp = head;
	while (temp != NULL){
		head=head->next;
		free(temp);
		temp=head;
	} 
	return 0;
}
