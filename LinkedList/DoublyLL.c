//Doubly linked List all kinds of Implementations.

#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *Create(int value){   // Create the node 
 
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL){
        printf("Memory allocation failed.");
    }

    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    

return newnode;
}



struct node *InsertAtBeginning(int value ,struct node *head){   //Insert at the beginning
    struct node *newnode;
    newnode = Create(value);

    if(head == NULL){
        head =newnode;
        return head;
    };
    
    newnode-> next = head;
    head -> prev = newnode;
    newnode->prev = NULL;
    head = newnode;  

    return head;
}

struct node *InsertAtEnd(int value,struct node *head){   //Insert at the end 
    struct node *newnode;
    newnode =Create(value);
    if(head == NULL){
        return newnode;
    }

    struct node *temp = head;
    while(temp->next != NULL){
        temp =temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
    newnode->prev = temp;

    return head;
}



struct node *InsertAtPosition(int position,int value, struct node *head){   //Insert at any position
 
    struct node *newnode =Create(value);
 
    struct node *temp = head;
    for(int i=1; i< position-1;i++){
        temp = temp->next;
    }

    newnode-> next = temp->next;
     if(temp->next != NULL){
    temp->next->prev = newnode;
    }
    
    temp->next =newnode;
    newnode->prev = temp;


   

return head;
}

int main(){

    struct node *head;
    
    head = Create(6); 
    head = InsertAtBeginning(5,head);
    head = InsertAtBeginning(4,head);
    head = InsertAtBeginning(3,head);
    head = InsertAtBeginning(2,head);
    head = InsertAtBeginning(1,head);

    head = InsertAtEnd(7,head);
   
    head = InsertAtPosition(6,8,head);
  

    struct node *temp = head;
    struct node* tail;
    while(temp!=NULL){
       printf("%d-> ",temp->data);
        tail = temp;
        temp = temp->next;

    }
    printf("END\n");

    while(tail!=NULL){
        printf("%d->",tail->data);
        tail = tail->prev;
    }
        printf("START");




return 0;
}