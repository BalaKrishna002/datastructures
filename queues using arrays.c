#include <stdio.h>
#include<stdlib.h>

#define MAX 20
int a[MAX],front=-1,rear=-1;

void enque(int x){
    if(rear==MAX-1){
        printf("\nQUEUE OVERFLOW\n");
    }else{
        if(front==-1){
            front=rear=0;
        }else{
            ++rear;
        }
        a[rear]=x;
    }
}

int deque(){
    int x;
    if(front==-1){
        return -1;
    }else{
        x=a[front];
        if(front==rear){
            front=rear=-1;
        }else{
            ++front;
        }
        return x;
    }
}
void display(){
    int i;
    if(front==-1){
        printf("\n NO element to print\n");
    }else{
        for(int i=front;i<=rear;i++){
            printf("%d\t",a[i]);
        }
    }
}
int main()
{
    int ch,x;
    while(1){
        printf("\n1.enque \n2.deque \n3.display \n4.exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("\nEnter element to insert\n");
                   scanf("%d",&x);
                   enque(x);
                   break;
            case 2:
                   x=deque();
                   if(x>-1){
                       printf("\nelement %d is deleted from front\n",x);
                   }else{
                       printf("\nQueue Underflow\n");
                   }
                   break;
            case 3:printf("\nelements in queue are\n");
                   display();
                   break;
            case 4:exit(0);
            default:printf("\nInvalid choice\n");
        }
    }
    return 0;
}
