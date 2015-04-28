#include<stdio.h>
struct pair{int size,left,right;};
struct pair firstparr[10];
struct pair bestparr[10];
int main()
{
    firstfit();
    return 0;
}
void firstfit()
{
    int mem[100]={0};
    int n,p=1,ch,pid,size;
    int exitflag=0;
    int i,j,k;
    while(exitflag==0)
    {
        printf("\n1.Allocate Memory to New Process.\n2.Deallocate Memory from a Process.\n3.Print the Memory Map\n4.Running Processes\n5.Exit\n: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: for(i=0;i<10&&firstparr[i].size>0;i++);
                    if(i<10)
                        p=i;
                    printf("Enter the size to be allocated for process with pid %d : ",p+1);
                    scanf("%d",&size);
                    int flag=0;
                    for(j=0;j<100&&flag!=1;j++)
                    {
                        if(mem[j]==0)
                        {
                            k=j;
                            int count=0;
                            while(k<100&&mem[k]==0&&count<size)k++,count++;
                            if(count>=size)
                            {
                                firstparr[p].left=j,firstparr[p].right=k,flag=1;
                                firstparr[p].size=size;
                                for(i=j;i<=k;i++)
                                    mem[i]=1;
                            }
                        }
                    }
                    if(flag==0)
                        printf("Not Enough Memory to Allocate the Process\n");
                    break;
            case 2: printf("Enter the Process id : ");
                    scanf("%d",&pid);
                    i=firstparr[pid-1].left;
                    if(firstparr[pid-1].size>0){
                    while(i<=firstparr[pid-1].right)mem[i++]=0;
                    printf("The memory is deallocated");
                    firstparr[pid-1].size=-1;
                    firstparr[pid-1].left=-1;
                    firstparr[pid-1].right=-1;
                    }
                    else printf("NO such process.");
                    break;
            case 3: printf("+ for Allocated Memory and - for Free Memory\n");
                    for(i=0;i<100;i++)
                    {
                        if(mem[i]==1)
                            printf("+");
                        else printf("-");
                    }
                    break;
            case 4: for(i=0;i<10;i++)
                    {
                        if(firstparr[i].size>0)
                            printf("PID : %d ; Memory : %d\n",i+1,firstparr[i].size);
                    }break;
            case 5: exitflag=1;
                    break;

        }
    }
}
void bestfit()
{
    int mem[100]={0};
    int n,p=1,ch,pid,size;
    int exitflag=0;
    int i,j,k;
    while(exitflag==0)
    {
        printf("\n1.Allocate Memory to New Process.\n2.Deallocate Memory from a Process.\n3.Print the Memory Map\n4.Running Processes\n5.Exit\n: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: for(i=0;i<10&&bestparr[i].size>0;i++);
                    if(i<10)
                        p=i;
                    printf("Enter the size to be allocated for process with pid %d : ",p+1);
                    scanf("%d",&size);
                    int flag=0;
                    int count=0;
                    for(j=0;j<100&&flag!=1;j++)
                    {
                        if(mem[j]==0)
                        {
                            k=j;
                            while(k<100&&mem[k]==0)k++,count++;
                            if(count>=size)
                            {
                                bestparr[p].left=j,bestparr[p].right=j;
                                bestparr[p].size=size;
                            }
                        }
                    }
                    if(flag==0)
                        printf("Not Enough Memory to Allocate the Process\n");
                    break;
            case 2: printf("Enter the Process id : ");
                    scanf("%d",&pid);
                    i=bestparr[pid-1].left;
                    if(bestparr[pid-1].size>0){
                    while(i<=bestparr[pid-1].right)mem[i++]=0;
                    printf("The memory is deallocated");
                    bestparr[pid-1].size=-1;
                    bestparr[pid-1].left=-1;
                    bestparr[pid-1].right=-1;
                    }
                    else printf("NO such process.");
                    break;
            case 3: printf("+ for Allocated Memory and - for Free Memory\n");
                    for(i=0;i<100;i++)
                    {
                        if(mem[i]==1)
                            printf("+");
                        else printf("-");
                    }
                    break;
            case 4: for(i=0;i<10;i++)
                    {
                        if(bestparr[i].size>0)
                            printf("PID : %d ; Memory : %d\n",i,bestparr[i].size);
                    }break;
            case 5: exitflag=1;
                    break;

        }
    }
}
