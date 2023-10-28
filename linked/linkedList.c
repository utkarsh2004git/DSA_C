#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void display(struct Node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}

int main(){
    struct Node *first=(struct Node*)malloc(sizeof(struct Node));
    struct Node *second=(struct Node*)malloc(sizeof(struct Node));
    struct Node *third=(struct Node*)malloc(sizeof(struct Node));
    struct Node *fourth=(struct Node*)malloc(sizeof(struct Node));

    first->data=11;
    first->next=second;

    second->data=22;
    second->next=third;

    third->data=33;
    third->next=fourth;

    fourth->data=44;
    fourth->next=NULL;

    printf("Displaying\n");
    display(first);
    return 0;
}