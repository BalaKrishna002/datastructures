
#include <stdio.h>

#include<stdlib.h>
typedef struct hashtable{
    int data;
    struct hashtable *next;
}node;

int hash(int x){
    return x%10;
}

void insert(node *t[10],int x){
    int i=hash(x);
    node *p=(node *)malloc(sizeof(node));
    p->data=x;
    p->next=NULL;
    if(t[i]->next==NULL){
        t[i]->next=p;
    }else{
        p->next=t[i]->next;
        t[i]->next=p;
    }
}

void search(node *t[10], int x){
    int i=hash(x);
    int flag=0;
    node *temp=t[i]->next;
    while(temp!=NULL){
        if(temp->data==x){
            flag=1;
            break;
        }else{
            temp=temp->next;
        }
    }
    if(flag){
        printf("\nElement %d found\n",x);
    }else{
        printf("\nElement %d not found\n",x);
    }
}

void delete(node *t[10],int x){
    int i=hash(x),flag=0;
    node *temp=t[i]->next;
    node *temp1=t[i];
    while(temp!=NULL){
        if(temp->data==x){
            flag=1;
            break;
        }else{
            temp1=temp;
            temp=temp->next;
        }
    }
    if(flag){
        printf("\nElement %d deleted\n",x);
    }else{
        printf("\nElement %d not deleted\n",x);
    }
}

void display(node *t[10]){
    node *temp;
    int i;
    for(i=0;i<10;i++){
        temp=t[i]->next;
        printf("%d||->",i);
        while(temp!=NULL){
            printf("[%d]->",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main()
{
    node *t[10];
    int i,ch,x;
    for(i=0;i<10;i++){
        t[i]=(node*)malloc(sizeof(node));
        t[i]->next=NULL;
    }
    while(1){
        printf("1.Insert \n2.search \n3.delete \n4.display \n5.exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("\nEnter element to insert: ");
                   scanf("%d",&x);
                   insert(t,x);
                   break;
            case 2:printf("\nEnter element to search: ");
                   scanf("%d",&x);
                   search(t,x);
                   break;
            case 3:printf("\nEnter element to delete: ");
                   scanf("%d",&x);
                   delete(t,x);
                   break;
            case 4:printf("\nElements in hashtable are: ");
                   display(t);
                   break;
            case 5:exit(0);
                   break;
            default:printf("\nInvalid Choice");
        }
    }


    return 0;
}
