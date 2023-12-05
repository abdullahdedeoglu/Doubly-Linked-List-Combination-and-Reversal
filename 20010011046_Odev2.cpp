//Abdullah Dedeoðlu 20010011046
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	struct node * next;
	struct node* prev;
	int deger;
};
node * root1=NULL;
node * root2=NULL;



void listele(node * root, int num){	
	printf("%d. listenin elemanlari: \n", num);
	if(root == NULL){
		printf("Bu liste bos\n");
		return;
	}
	node * iter = root;	
	while(iter->next != NULL){
		
		printf("%d\t",iter->deger);
		printf("%ld\n", iter);
		iter = iter->next;
	}
	printf("%d\t",iter->deger);
	printf("%ld\n", iter);
	printf("\n\n");
}

void ekle(int sayi){
	int i;
	node * iter1 = root1;
	node * iter2 = root2;
	for(i = 1 ; i <= sayi ; i++){
		if(i % 2 == 1) {
			if (root1==NULL){
				root1 = (node*)malloc(sizeof(node));
				root1->deger=rand()%20;
				root1->prev=NULL;
				root1->next=NULL;
			}
			else {
				node * iter1 = root1;
				while(iter1->next!=NULL){
					iter1=iter1->next;
				}
				node * newnode=(node*)malloc(sizeof(node));
				newnode->deger=rand()%20;
				iter1->next=newnode;
				newnode->prev=iter1;
				newnode->next=NULL;
			}	
		}
		else{
			if (root2==NULL){
				root2 = (node*)malloc(sizeof(node));
				root2->deger=rand()%20;
				root2->prev=NULL;
				root2->next=NULL;
			}
			else {
				node * iter2 = root2;
				while(iter2->next!=NULL){
					iter2=iter2->next;
				}
				node * newnode=(node*)malloc(sizeof(node));
				newnode->deger=rand()%20;
				iter2->next=newnode;
				newnode->prev=iter2;
				newnode->next=NULL;
			}	
		}
	}

}

void sirala(int sayi){
	int i;
	node * iter1 = root1;
	node * iter2 = root2;
	node * temproot1 = root1;
	node * temproot2 = root2;	
	
	for(i = 0 ; i < sayi/2 ; i++) {
		if(iter2->next != NULL) {
			iter1 = iter1->next;
			iter2 = iter2->next;
			temproot1->next = temproot2;
			temproot2->prev = temproot1;
			temproot2->next = iter1;
			iter1->prev = temproot2;
			temproot1 = iter1;
			temproot2 = iter2;
		}
		else if (sayi %2 == 1){
			iter1 = iter1->next;
			temproot1->next = temproot2;
			temproot2->prev = temproot1;
			temproot2->next = iter1;
			iter1->prev = temproot2;
			temproot1 = iter1;
		}
		else {
			temproot1->next = temproot2;
			temproot2->prev = temproot1;
		}
	}

}

void reverse()
{
    node * iter = root1;
    node * temp = NULL;
    
    while (iter->next != NULL) {
 		iter = iter->next;
 	}
 	
    while (iter != NULL) {
        temp = iter->next;
        iter->next = iter->prev;
        iter->prev = temp;
        iter = iter->next;
    }
    
    while(temp->prev != NULL){
    	temp = temp->prev;
	}
 
 	if (temp != NULL)
        root1 = temp;
}
 

int main(){
	int sayi;
	printf("Eleman sayisini giriniz:");
	scanf("%d", &sayi);
	
	printf("Iki listenin ayri ayri goruntusu:\n ");
	ekle(sayi);
	listele(root1, 1);
	listele(root2, 2);
	printf("Birlestirilmis goruntu:\n");
	sirala(sayi);
	listele(root1, 1);
	printf("Tersine cevrilmis goruntu:\n");
	reverse();
	listele(root1, 1);
	
}
