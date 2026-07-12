#ifndef CLL_H
#define CLL_H

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *Create(int value);
struct node *InsertAfterTail(int value,struct node*head);
struct node *InsertAtAnyPosition(int value , struct node * head,int position);

#endif