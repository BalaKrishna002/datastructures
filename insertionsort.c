#include <stdio.h>
void insertionsort(int a[20] , int n)
{
    int i,temp,j;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i;
        while(j>0 && temp<a[j-1])
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=temp;
    }
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}
void main()
{
    int n,i;
    printf("enter the size of the array ");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements in the array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    insertionsort(a,n);
}