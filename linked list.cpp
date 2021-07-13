/*
	C program to reverse the each word of the linked list
	eg: hello world
	output : olleh dlrow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print();
void linkedList(char* a);
void reverseList();


//creating a new node

struct Node{
	char data;
	struct Node *next;
}*head,*curnode,*prenode,*temp;
void reverse(struct Node *tail);

//converting the string to linked list of characters

void linkedList(char* a)
{
	int i;
	struct Node *temp;
	head = (struct Node *)malloc(sizeof(struct Node));
	head->data=a[0];
	head->next=NULL;
	
	temp=head;
	
	for(i=1;i<strlen(a);i++){
		struct Node *newnode;
		newnode = (struct Node *)malloc(sizeof(struct Node));
		newnode->data=a[i];
		newnode->next=NULL;
		temp->next=newnode;
		temp=temp->next;
		if(i==1)
			head->next=newnode;
	}
	reverseList();
}

//reversing each word of the string

void reverse(struct Node *tail){
	int flag=0;
	flag++;
	prenode=head;
	curnode=head->next;
	head=head->next;
	if(flag==1)
	 prenode->next=NULL;
	while(head != tail){
		head=head->next;
		curnode->next=prenode;
		prenode=curnode;
		curnode=head;
	}
		head=prenode;
	print();
	head=temp;
}


//reversing the inked list
void reverseList(){
	struct Node *tail; 
	temp = head;
	int flag=0;
	while(temp != NULL){
		
		if(temp->data == ' '){
		 reverse(tail);
		 printf("%c",temp->data);
		 temp=temp->next;
		 }
		else{
			temp=temp->next;
			tail=temp;
		}
	}
		reverse(tail);
}


//printing the list
void print(){
	struct Node *temp;
	temp=head;
	while(temp!=NULL){
		printf("%c",temp->data);
		temp=temp->next;
	}
}

int main()
{
	char str[20];
	printf("Enter the string : ");
	scanf("%[^\n]s",str);	
	linkedList(str);
	return 0;
}
