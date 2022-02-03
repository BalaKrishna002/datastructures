#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int a[MAX],top=-1;

void push(int x){
    if(top==MAX-1){
        printf("\nStackoverflow\n");
    }else{
        a[++top]=x;
    }
}

int peek(){
    return a[top];
}

int pop(){
    if(top==-1){
        return -1;
    }else{
        return a[top--];
    }
}


void display(){
    int i;
    if(top==-1){
        printf("\nNo elements in Stack\n");
    }else{
        for(i=top;i>-1;i--){
            printf(" _\n");
            printf("|%d|\n",a[i]);
        }
    }
}

int main(){
    int x,ch;
    printf("1.push \n2.pop \n3.peek \n4.display \n5.exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("\nEnter element to insert: ");
                   scanf("%d",&x);
                   push(x);
                   break;
            case 2:x=pop();
                   if(x==-1){
                       printf("\nStackunderflow\n");
                   }else{
                       printf("\nElement %d is deleted Successfully\n",x);
                   }
                   break;
            case 3:x=peek();
                   printf("\nElement at top of stack is=%d\n",x);
                   break;
            case 4:display();
                   break;
            case 5:exit(0);
            default:printf("\nIvalid choice\n");
        }
    }
}