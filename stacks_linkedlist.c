#include<stdio.h>
#include<stdlib.h>
typedef struct stackll{
    int data;
    struct stackll *next;
}node;

node *top=NULL;

void push(int x)
{
    node *new;
    new=(node*)malloc(sizeof(node));
    new->data=x;
    new->next=NULL;
    if(top==NULL){
        top=new;
    }else{
        new->next=top;
        top=new;
    }
}

int pop()
{
    int x;
    node *temp;
    if(top==NULL){
        return -1;
    }else{
        x=top->data;
        temp=top;
        top=top->next;
        free(temp);
        return x;
    }
}




void display()
{
    node *temp;
    temp=top;
    if(top==NULL){
        printf("No elements in stack");
    }else{
        while(temp!=NULL){
        printf("|%d|->",temp->data);
        temp=temp->next;
        }
        printf("NULL");
    }
}


void main()
{
    int ch,x;
    printf("1.insert \n2.pop \n3.display \n4.exit");
    while(1){
        printf("\nenter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("\nEnter a number: ");
                   scanf("%d",&x);
                   push(x);
                   break;
            case 2:x=pop();
                   if(x==-1){
                       printf("Stack UnderFlow");
                   }else{
                       printf("%d is delted from stack",x);
                   }
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
            default:printf("Invalid Choice");
                
        }
    }
    
}

//OUTPUT:
/*
1.insert 
2.pop 
3.peek 
4.exit
enter your choice: 1

Enter a number: 2

enter your choice: 1

Enter a number: 4

enter your choice: 3
|4|->|2|->NULL
enter your choice: 2
4 is delted from stack
enter your choice: 2
2 is delted from stack
enter your choice: 2
Stack UnderFlow
enter your choice: 5
Invalid Choice
enter your choice: 4
*/
