#include<stdio.h>

#include<conio.h>



int main()
{
int nb,np,i,j,totalwait=0,totalturn=0,quantum=4,flag=1,time=0;

printf("\nEnter The No Of Blocks :");

scanf("%d",&nb);

for(i=0;i<nb;i++){
printf("Enter The Size of Block $ %-3d:",i+1);
scanf("%d",&b[i].size);
b[i].no=i+1;
}

printf("\nEnter The No Of Processes:");

scanf("%d",&np);

for(i=0;i<np;i++){
printf("Enter The Size of process # %-3d:",i+1);

scanf("%d",&p[i].size);
}

for(i=0;i<nb;i++)
for(j=0;j<nb-i-1;j++)
if(b[j].size>b[j+1].size){

b[j].size^=b[j+1].size^=b[j].size^=b[j+1].size;

b[j].no^=b[j+1].no^=b[j].no^=b[j+1].no;
}

for(i=0;i<np;i++){
for(j=0;j<nb;j++){

if(b[j].id==0&&p[i].size<=b[j].size){

b[j].id=i+1;

p[i].id=b[j].no;

flag=1;
break;

}
}
}

printf("Block \n\n-----------");

printf("\nBlock_ID Block_Size Process_ID Process_Size");

for(i=0;i<nb;i++)
//for(j=0;j<nb;j++)
{
//if(j+1==b[j].no){
if(b[i].id)
printf(" \nBlock #%-7d%-10d%-10d%-10d",b[i].no,b[i].size,b[i].id, p[b[i].id-1].size);

else
printf(" \nBlock #%-7d%-10d Empty Empty ",b[i].no,b[i].size);
}
//}
printf("\n\nProcess \n-----------");

printf("\nProcess_ID Process_Size Block_ID Block_Size");

for(i=0;i<np;i++){
if(p[i].id)
printf(" \nProcess $ %-3d%-14d%-10d%-10d ",i+1,p[i].size,p[i].id, b[p[i].id-1].size);

else
printf(" \nProcess $ %-3d%-14dWaiting Waiting ",i+1,p[i].size);
}

printf("\n");
getch(); }
