#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int a[MAX],top=-1;

void push(int x)
{
    if(top==MAX-1){
        printf("Stack OverFlow");
    }else{
        a[++top]=x;
    }
}


int pop()
{
    if(top==-1){
        return -1;
    }else{
        return a[top--];
    }
}

int peek()
{
    if(top==-1){
        return -1;
    }else{
        return a[top];
    }
}

void main()
{
    int ch,x;
    printf("1.insert \n2.pop \n3.peek \nexit");
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
            case 3:x=peek();
                   if(x==-1){
                       printf("Stack UnderFlow");
                   }else{
                       printf("%d is Top of stack",x);
                   }
                   break;
            case 4:exit(0);
            default:printf("Invalid Choice");
                
        }
    }
    
}


//OUTPUT:
/*1.insert 
2.pop 
3.peek 
exit
enter your choice: 1

Enter a number: 2

enter your choice: 1

Enter a number: 5

enter your choice: 1

Enter a number: 8

enter your choice: 1

Enter a number: 9

enter your choice: 1

Enter a number: 0

enter your choice: 1

Enter a number: 3
Stack OverFlow
enter your choice: 3
0 is Top of stack
enter your choice: 2
0 is delted from stack
enter your choice: 2
9 is delted from stack
enter your choice: 2
8 is delted from stack
enter your choice: 2
5 is delted from stack
enter your choice: 2
2 is delted from stack
enter your choice: 2
Stack UnderFlow
enter your choice: 5
Invalid Choice
enter your choice: 4
*/