#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Stack{
    int size;  
    int top;  
    int *arr;  
};

void push(struct Stack *s,int element){
    if(s->top==s->size-1){
        printf("Stack Overflow\n");
    }
    else{
        s->top++;
        s->arr[s->top]=element;
        printf("%d inserted\n",element);
    }
}
int pop(struct Stack *s){
    int t;
    if(s->top==-1){
        printf("Stack Underflow\n");
    }
    else{
        t=s->arr[s->top];
        s->top--;
        printf("%d popped out\n",t);
        return t;
    }
}
int main(){
    struct Stack s;
    printf("Enter the length of array : ");
    scanf("%d",&s.size);
    s.arr=(int*)malloc(s.size*sizeof(int));
    s.top=-1;
    int choice,ele;
    bool again= true;
    while(again){
        printf("Enter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 0 to stop\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter a element : ");
            scanf("%d",&ele);
            push(&s,ele);
            break;
        case 2:
            pop(&s);           
            break;
        case 0:
            again=false;
            break;
        default:
            break;
        }
    }

    return 0;
}

