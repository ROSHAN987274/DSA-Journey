#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int main(){
    struct Node *head;
    head = (struct Node*)malloc(sizeof(struct Node));

    head -> data = 1;    
    struct Node *second;
    second = (struct Node*)malloc(sizeof(struct Node));
 
    second-> data = 2;
    second-> next = NULL;
    head-> next = second;

    struct Node *temp;
    temp = head;

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp =  temp->next;
    }

    return 0;
}