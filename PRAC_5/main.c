#include <stdio.h>
#include <stdlib.h>

struct Dnode{
    int data;
    struct Dnode *prev,*next;
};

//GLOBAL
struct Dnode *head;

//creating  head
void create(int ele){
    if(head==NULL){
        head=(struct Dnode *)malloc(sizeof(struct Dnode));
        head->data=ele;
        head->prev=NULL;
        head->next=NULL;
        printf("Head is Created\n");
    }
    else{
        printf("Already Created \n");
    }  
}

// Adding element in linked list

void add_begin(int ele){
    struct Dnode * newnode=(struct Dnode*)malloc(sizeof(struct Dnode));
    newnode->data=ele;
    head->prev=newnode;
    newnode->next=head;
    newnode->prev=NULL;
    newnode=head;
    printf("Element Added at begin\n");
}

void add_end(int ele){
    struct Dnode *newnode=(struct Dnode*)malloc(sizeof(struct Dnode));
    struct Dnode *temp,*prev;
    temp=head;
    while (temp->next!=NULL)
    {   prev=temp;
        temp=temp->next;
    }
    newnode->data=ele;
    temp->next=newnode;
    newnode->prev=temp;
    printf("Element Added at end\n");
}

void insert_bet(int ele ,int pos){
    struct Dnode *newnode,*temp,*prev;
    newnode=(struct Dnode *)malloc(sizeof(struct Dnode));
    int count=1;
    temp=head;
    while(count<pos &&temp->next!=NULL ){
        prev=temp;
        temp=temp->next;
        count++;
    }
    newnode->data=ele;
    prev->next=newnode;
    newnode->prev=prev;
    temp->prev=newnode;
}

int main(){
    create(10);
    add_begin(5);
    add_begin(5);
    add_end(5);
    return 0;
}