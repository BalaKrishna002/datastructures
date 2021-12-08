#include<stdio.h>
#include<stdlib.h>

typedef struct slist{
    int data;
    struct slist *next;
} node;

node *create(node*);
void display(node*);
int count(node*);
void search(node*,int);
node *insertatbegin(node*,int);
node *insert_at_end(node*,int);
node *insert_at_position(node*,int,int);
node *delete(node*,int);
void sort(node*);
node *reverse(node*);


int main()
{
    node *head=NULL;
    int ch,pos,x,n;
    while (1)
    {
         
       printf("\n1.Create \n2.Display \n3.Count \n4.Search \n5.Insert at begining \n6.Insert at ending \n7.Insert at middle \n8.Delete \n9.Sort \n 10.Reverse \n11.Exit");
        scanf("%d",ch);
        switch (ch)
       {
        case 1:head=create(head);
                break;

        case 2:printf("The list of elements are\n");
                display(head);
                break;

        case 3:n=count(head);
               printf("The no.of elements are %d\n",n);
               break;

        case 4:printf("\nEnter element to search: ");
               scanf("%d",&x);
               search(head,x);
               break;

        case 5:printf("\nEnter element to insert: ");
               scanf("%d",&x);
               head=insertatbegin(head,x);
               break;

        case 6:printf("\nEnter element to insert: ");
               scanf("%d",&x);
               head=insert_at_end(head,x);
               break;

        case 7:printf("\nEnter element to insert: ");
               scanf("%d",&x);
               printf("\nEnter position to insert: ");
               scanf("%d",&pos);
               head=insert_at_position(head,pos,x);
               break;

        case 8:printf("\nEnter element to delete: ");
               scanf("%d",&x);
               head=delete(head,x);
               break;

        case 9:sort(head);
               printf("\nElements after sorting\n");
               display(head);


        case 10:printf("\nElements after reversing\n");
                head=reverse(head);break;

        case 11:exit(0);

        
        default:printf("correct choice\n");
                break;
        }
    }
    
    
}


node *create(node *first)
{
    node *new,*prev;
    int x;
    printf("Enter data,(enter -1 to stop): ");
    scanf("%d",&x);
    while(x!=-1){
        new=(node*)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;
        if(first==NULL){
            first=new;
            prev=new;
        }else{
            prev->next=new;
            prev=new;
        }
        printf("Enter data,(enter -1 to stop): ");
        scanf("%d",&x);
    }
    return first;
}


void display(node *first)
{
    node *temp=first;
    if(first==NULL){
        printf("No elements found\n");
    }else{
        while(temp!=NULL){
            printf("|%d|->",temp->data);
            temp=temp->next;
        }
        printf("NULL");
    }
}



int count(node *first)
{
    int c=0;
    node *temp=first;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    return c;
}


void search(node *first,int x)
{
    node *temp=first;
    int flag=0;
    while (temp!=NULL)
    {
        if(temp->data=x){
            flag=1;
            break;
        }else{
            temp=temp->next;
        }
    }

    if(flag==1){
        printf("The element %d is found\n",x);
    }else{
        printf("The element %d is not found\n",x);
    }
    
}


node *insertatbegin(node *first,int x)
{
    node *new=(node*)malloc(sizeof(node));
    new->data=x;
    new->next=NULL;
    if(first==NULL){
        first=new;
    }else{
        new->next=first;
        first=new;
    }
    return first;

}



node *insert_at_end(node *first,int x)
{
    node *temp=first;
    node *new=(node*)malloc(sizeof(node));
    new->data=x;
    new->next=NULL;
    if(first=NULL){
        first=new;
    }else{
        while(temp->next==NULL){
            temp=temp->next;
        }
        temp->next=new;
    }
    return first;
}



node *insert_at_position(node *first,int pos,int x)
{
    node *temp=first;
    int n=count(first);
    if(pos>1&&pos<n){
        node *new=(node*)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;
        for(int i=1;pos-1;i++){
            temp=temp->next;
        }
        new->next=temp->next;
        temp->next=new;
    }
    return first;
}


node *delete(node *first,int x)
{
    node *temp,*temp1;
    int flag=0;
    temp=first;
    if(first->data==x){
        first=first->next;
        free(temp);
    }else{
        temp1=first;
        temp=first->next;
        while(temp!=NULL){
            if(temp->data==x){
                flag=1;
                break;
            }else{
                temp1=temp;
                temp=temp->next;
            }
        }
    }
    if(flag==1){
        temp1->next=temp->next;
        free(temp);
    }else{
        printf("Element %d is not found\n");
    }
    return first;
}


void sort(node *first)
{
    node *temp1,*temp2;
    int x;
    for(temp1=first;temp1->next!=NULL;temp1=temp1->next){
        if(temp1->data>temp2->data){
            x=temp1->data;
            temp1->data=temp2->data;
            temp2->data=x;
        }
    }
}



node *reverse(node *first)
{
    node *present=first,*prev=NULL,*save;
    while(present!=NULL){
        save=present->next;
        present->next=prev;
        prev=present;
        present=save;
    }
    return prev;
}