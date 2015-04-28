#include<stdio.h>
#include<conio.h>
int main()
{
int siz,n,p,a[100],j,z,k,f;
printf("The size of the individual memory block is %d \n",sizeof (int));
printf("Enter the size of total memory   (it should not exceed the limit 100)  \n");
scanf("%d",&n);
printf("The current status of memory is  : 0 represent empty 1 represent free block \n ");
for(j=0;j<n;j++)
{
    a[j]=0;
    printf("%d  ",a[j]);

}

printf("\nEnter the no of initial processes present  ");
scanf("%d",&p);
printf("\nEnter the respective positions\n");
for(k=1;k<=p;k++)
{
scanf("%d",&z);
while(a[z]==1)
{
    printf("The memory position is already occupied  :: Enter other position  \n");
    scanf("%d",&z);
}
a[z]=1;
}
printf("The new memory status before compaction is\n\n");
for(j=0;j<n;j++)
{

    printf("%d  ",a[j]);

}
printf("\nThe memory after compaction is  \n");
for(j=0;j<=p;j++)
{

    a[j]=1;
    printf("%d  ",a[j]);
}
for(j=p;j<=n;j++)
{

    a[j]=0;
    printf("%d  ",a[j]);
}


return 0;
}


