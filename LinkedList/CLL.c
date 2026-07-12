#include "CLL.h"

struct node *Create(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory Allocation Failed.\n");
        return NULL;
    }

    newnode->data = value;

    // Circular Linked List
    newnode->next = newnode;

    return newnode;
}

// Insert after the tail or before the head 
struct node *InsertAfterTail(int value , struct node *head){

    struct node *newnode = Create(value);

    if(head == NULL){
        head = newnode;
        return newnode;
    }

    struct node *temp = head;


    while(temp->next !=head){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;


    return head;
}

// Add at any position
struct node *InsertAtAnyPosition(int value , struct node * head,int position){
    struct node *newnode =Create(value);

    struct node *temp = head;

    if(position == 1){
        return InsertAfterTail(value, head);
    }
    for(int i=1; i<position-1;i++){
        temp = temp->next;
    }
    newnode->next = temp->next;   
    temp->next = newnode;
    
return head; 
}