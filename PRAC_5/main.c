#include <stdio.h>
#include <stdlib.h>

struct Dnode{
    int data;
    struct Dnode *prev,*next;
};

struct Dnode *head;

void create(int ele){
    if(head==NULL){
        head=(struct Dnode *)malloc(sizeof(struct Dnode));
        head->data=ele;
    }

    else
    {
        printf("Already Created \n");
    }
    
}

int main(){
    
    return 0;
}