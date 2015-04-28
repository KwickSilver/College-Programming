#include<stdio.h>

 int main()
 {
    int a[15],i,n,j,p=0,q=0,count=0,flag=0;

    printf("Enter the size of array:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       printf("\n\nEnter the value for %d element:",i+1);
       scanf("%d",&a[i]);
    }
    for(i=0;i<=n;i++)
    {
       if(a[i]==0&&flag==0)
       {
	 p=i;
	 flag=1;
       }
       else
       {
	 if(a[i]==1&&flag==1)
	 {
	   q=i;
	   a[q]=0;
	   a[p]=1;
	   i=p-1;
	   flag=0;
	   count++;
	 }
       }
    }
    for(i=0;i<n;i++)
    printf("%d",a[i]);
   printf("\n\nTotal movement of data is: %d",count);
   return 0;
 }
