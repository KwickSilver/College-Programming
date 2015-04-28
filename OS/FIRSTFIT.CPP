#include<stdio.h>

struct process{
int size;
char name[20];
int id;
}p[20]={0,0};

struct block{
int size;
int id;
}b[20]={0,0};

int main()
{
int nb,np,i,j,totalwait=0,totalturn=0,quantum=4,flag=1,time=0;

printf("\nEnter The No Of Blocks :");

scanf("%d",&nb);

for(i=0;i<nb;i++)
    {
        printf("Enter The Size of Block $ %-3d:",i+1);
        scanf("%d",&b[i].size);
    }

printf("\nEnter The No Of Processes:");

scanf("%d",&np);

for(i=0;i<np;i++)
{
    printf("Enter The Name of process # %-3d:",i+1);
    scanf("%s",p[i].name);
    printf("Enter The Size of process # %-3d:",i+1);
    scanf("%d",&p[i].size);
}
for(i=0;i<np;i++){
for(j=0;j<nb;j++){
if(b[j].id==0&&p[i].size<=b[j].size)
{
b[j].id=i+1;
p[i].id=j+1;
flag=1;
break;
}
}
}
printf("Block \n\n-----------");
printf("\nBlock ID Block_Size Process_Name Process_Size");
for(i=0;i<nb;i++){
if(b[i].id)
    printf(" \nBlock #%-7d%-10d%-10s%-10d",i+1,b[i].size,p[b[i].id-1].name, p[b[i].id-1].size);
else
printf(" \nBlock #%-7d%-10dEmpty Empty ",i+1,b[i].size);
}

printf("\n\nProcess \n-----------");

printf("\nProcess_Name Process_Size Block ID Block_Size");

for(i=0;i<np;i++){

if(p[i].id)
printf(" \nProcess $ %-10s%-10d%-10d%-10d ",p[i].name,p[i].size,p[i].id, b[p[i].id-1].size);

else
printf(" \nProcess $ %-10s%-10dWaiting Waiting ",p[i].name,p[i].size);

}

printf("\n");

}

