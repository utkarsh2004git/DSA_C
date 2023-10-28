#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

struct Stack{
    int size;  
    int top;  
    int *arr; 
     
};

void push(struct Stack *s,int element){
    if(s->top==s->size-1){
        printf("Stack Overflow");
    }
    else{
        s->top++;
        s->arr[s->top]=element;
    }
}

int pop(struct Stack *s){
    int t;
    if(s->top==-1){
        printf("Stack Underflow");
    }
    else{
        t=s->arr[s->top];
        s->top--;
        return t;
    }
}

char peek(struct Stack *s){
    if(s->top==-1){
        printf("None");
        return 0;
    }
    return s->arr[s->top];
}

int compare(struct Stack *s,char ch1,char ch2){
    if(ch1=='*' || ch1=='/' ){
        if(ch2=='*' || ch2=='/'){
            return 1 ;
        }
    }
    if(ch1=='+' || ch1=='-' ){
        if(ch2=='+' || ch2=='-'){
            return 1 ;
        }
    }

    return 0;
}

int append(struct Stack *s,char e[],char pe[]){
}


int main(){
    struct Stack s;
    // printf("Enter the length of array : ");
    // scanf("%d",&s.size);
    s.size=100;
    s.arr=(int*)malloc(s.size*sizeof(int));
    s.top=-1;

    char eqn[]="(2+(5*(1+2)))";
    char posteqn[100];
    append(&s,eqn,posteqn);
    printf("Post fix eqn\n");
    for (int i = 0; i < strlen(eqn); i++)
    {
        printf("%c",posteqn[i]);
    }
    
    
    return 0;
}

