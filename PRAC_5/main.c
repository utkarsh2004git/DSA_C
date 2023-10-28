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
    struct Dnode *temp;
    temp->data=ele;
    temp->next=head;
    head->prev=temp;
    head=temp;
    printf("Element Added at begin\n");
}

void add_end(int ele){
    struct Dnode *temp,*prev;
    temp=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    temp->data=ele;
    temp->prev=prev;
    temp->next=NULL;
    printf("Element Added at end\n");
}
int main(){
    create(10);
    // add_begin(5);
    // add_begin(5);
    add_end(5);
    return 0;
}