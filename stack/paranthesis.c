#include <stdio.h>

struct Stack{
    int top;
    char arr[10];
};


int stacKEmpty(struct Stack *s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}
int push(struct Stack *s,char elem){
    if(s->top==10){
       printf("Full");
       return 1;
    }
    s->top++;
    s->arr[s->top]=elem;
}
int pop(struct Stack *s){
    if(stacKEmpty(s)==1){
        printf("Empty");
    }
    char elem=s->arr[s->top];
    s->top--;
    return elem;
}
int main()
{
    struct Stack s1;
    s1.top=-1;
    char str[]="()(((()";
   int temp=1;
    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='('){
            push(&s1,'(');
        }
        if(str[i]==')'){

            if(s1.top==-1){
                temp =2;
                break;
            }
            pop(&s1);
        }
        i++;
    }
    int e=s1.top;
    if(temp==2 || e!=-1){
        printf("Unbalanced");
    }
    else{
        printf("Balanced");
    }

    return 0;
}
