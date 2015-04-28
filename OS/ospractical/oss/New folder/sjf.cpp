#include<stdio.h>
#include<conio.h>
 
int main()
{
    int i,j,n,brust_time[10],start_time[10],end_time[10],wait_time[10],temp,tot;
    float avg;
    //clrscr();
    printf("Enter the No. of jobs:\n\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\n \n Enter %d process burst time:\n",i);
        scanf("%d",&brust_time[i]);
    }
     
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(brust_time[i]>brust_time[j])
            {
                temp=brust_time[i];
                brust_time[i]=brust_time[j];
                brust_time[j]=temp;
            }
        }
         
        if(i==1)
        {
            start_time[1]=0;
            end_time[1]=brust_time[1];
            wait_time[1]=0;
        }
         
        else
        {
            start_time[i]=end_time[i-1];
            end_time[i]=start_time[i]+brust_time[i];
            wait_time[i]=start_time[i];
        }
    }
    printf("\n\n BURST TIME \t STARTING TIME \t END TIME \t   WAIT TIME\n");
    printf("\n ********************************************************\n");
    for(i=1;i<=n;i++)
    {
        printf("\n %5d %15d %15d %15d",brust_time[i],start_time[i],end_time[i],wait_time[i]);
    }
    printf("\n ********************************************************\n");
    for(i=1,tot=0;i<=n;i++)
    tot+=wait_time[i];
    avg=(float)tot/n;
    printf("\n\n\n AVERAGE WAITING TIME=%f",avg);
    for(i=1,tot=0;i<=n;i++)
    tot+=end_time[i];
    avg=(float)tot/n;
    printf("\n\n AVERAGE TURNAROUND TIME=%f",avg);
    for(i=1,tot=0;i<=n;i++)
    tot+=start_time[i];
    avg=(float)tot/n;
    printf("\n\n AVERAGE RESPONSE TIME=%f\n\n",avg);
    //getch();
    return 0;
}
