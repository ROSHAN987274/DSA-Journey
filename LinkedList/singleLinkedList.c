#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *Create(int value){
    struct Node *newNode;
    newNode =(struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Memory Allocation failed.");
    }
 
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;

}

struct Node *InsertAtBeginning(struct Node *head, int value){
    struct Node *newnode ;
    newnode = Create(value);

    newnode->next = head;
    head = newnode;

    return head;

}

void InsertAtEnd(struct Node *head, int value){
    struct Node *newnode;
    newnode = Create(value);
 
    struct Node *temp;
    
    if(head == NULL) {
       head = newnode;
    }
        temp = head;
    
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp-> next = newnode;
}


int countNode(struct Node *head){
    int count=0;
    struct Node *temp;
    temp = head;

    while(temp !=NULL){
    
    temp = temp->next;
    count++;
}
return count;
}

int search(struct Node *head, int key){
    struct Node * temp;
    temp =head;
    while(temp != NULL){
        if(temp->data == key){
            return 1;
        }
      temp = temp-> next;
    }
   return 0;
}

struct Node *InsertAtPosition(struct Node *head, int value , int position){
    struct Node *newnode = Create(value);
    struct Node *temp;
    temp = head;
    for(int i=1; i<position-1; i++){
      
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    
    return head;
}

struct Node *Deletefirst(struct Node* head){
    struct Node *temp = head;

    head = temp->next;
    free(temp);

    return head;

}

struct Node *DeleteAtEnd(struct Node *head){
    struct Node *perv;
    struct Node *temp = head;
    perv = temp;
    
    while(temp->next != NULL){
        perv =temp;
        temp = temp->next;
    }
    perv->next =NULL;
    free(temp);

    return head;
    
}

struct Node* DeleteAtPosition(struct Node *head,int position){
    struct Node *perv;
    struct Node *temp = head;
    perv = temp;

    for(int i=1; i< position; i++){
        perv = temp;
        temp =temp->next;
    }

    perv->next = temp->next;
    free(temp);

    return head;
    
}

int main(){
    int count;
    struct Node *head;
    head = Create(1);

    struct Node *second;
    second = Create(2);
    head -> next = second;

    struct Node *third;
    third = Create(3);

    second -> next = third;

    head = InsertAtBeginning(head , 4);
    
    InsertAtEnd(head,5);

    head = InsertAtPosition(head,6,5);

    head = Deletefirst(head);

    DeleteAtEnd(head);

    DeleteAtPosition(head ,3);

    struct Node *temp;
    temp = head;
    


    while( temp!= NULL){
        printf("%d ",temp->data);
        temp = temp->next;
        
    }
    printf("\n");
    count = countNode(head);
    printf("%d", count);
    
    printf("\n");
    int key =search(head,6);
    printf("%d",key);




    return 0;
}