#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Queue{
    int f,r,size;
    int *arr;
};

int isFull(struct Queue *q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    return 0;
}
int isEmpty(struct Queue *q){
    if((q->r==-1)&& q->f==-1){
        return 1;
    }
    return 0;
}

int enqueue(struct Queue *q,int ele){
    if(q->r==-1 && q->f==-1){
        q->r=0;
        q->f=0;
    }
    if(isFull(q)){
        printf("Queue is FUll\n");
        return 0;
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=ele;
    }
    printf("%d is inserted!\n",ele);
}

int dequeue(struct Queue *q){
    int x;
    if(isEmpty(q)){
        printf("Queue is Empty!\n");
        return 0;
    }
    else if(q->f==q->r){
        q->r=-1;q->f=-1;
    }
    else{
        q->f=(q->f+1)%q->size;
        x=q->arr[q->f];
    printf("Element Removed! %d\n\n",x);
    }
    return x;
}
int main(){
    struct Queue q;
    q.r=-1;
    q.f=-1;
    printf("Enter size of Queue : ");
    scanf("%d",&q.size);
    q.arr=(int *)malloc(q.size*sizeof(int));
    int choice,ele;
    bool again= true;
    while(again){
        printf("Enter 1 to enqueue\n");
        printf("Enter 2 to dequeue\n");
        printf("Enter 3 to display\n");
        printf("Enter 0 to stop\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter a element : ");
            scanf("%d",&ele);
            enqueue(&q,ele);
            break;
        case 2:
            dequeue(&q);           
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