#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct circularQueue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct circularQueue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
int isFull(struct circularQueue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}
void enqueue(struct circularQueue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val; 
        printf("Enqued element: %d\n", val);
    }
}
int dequeue(struct circularQueue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f = (q->f +1)%q->size;
        a = q->arr[q->f]; 
    }
    return a;
}
int main(){
    struct circularQueue q;
    q.f = q.r = 0;
    printf("Enter size of Queue : ");
    scanf("%d",&q.size);
    q.arr=(int *)malloc(q.size*sizeof(int));
    int choice,ele;
    bool again= true;
    while(again){
        printf("Enter 1 to enqueue\n");
        printf("Enter 2 to dequeue\n");
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
            printf("%d dequeued\n",dequeue(&q));
                       
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

