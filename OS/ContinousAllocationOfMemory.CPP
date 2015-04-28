#include<bits/stdc++.h>

using namespace std;




struct process{
int size;
int id;
char name[30];
};

struct process p[1000005];

struct block{
int no;
int size;
int id;
};


struct block b[1000005];

int nb,np,indicator=0;

void worst_fit()
{



}

void best_fit()
{
int i,j,flag=0;
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
{

if(b[i].id)
printf(" \nBlock #%-7d%-10d%-10d%-10d",b[i].no,b[i].size,b[i].id, p[b[i].id-1].size);

else
printf(" \nBlock #%-7d%-10d Empty Empty ",b[i].no,b[i].size);
}

printf("\n\nProcess \n-----------");

printf("\nProcess_ID Process_Size Block_ID Block_Size");

for(i=0;i<np;i++){
if(p[i].id)
printf(" \nProcess $ %-3d%-14d%-10d%-10d ",i+1,p[i].size,p[i].id, b[p[i].id-1].size);

else
printf(" \nProcess $ %-3d%-14dWaiting Waiting ",i+1,p[i].size);
}

printf("\n");

}



int first_fit()
{

int i,j,flag=0;
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


void init()
{


    int i,j;
    indicator=1;

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
    cin>>p[i].name;
    printf("Enter The Size of process # %-3d:",i+1);
    scanf("%d",&p[i].size);
}
}
int main()
{

string choice;

cout<<"Continuos file Allocation Methods.........\n";

cout<<"Enter Help to get command directory.......\n";

while(1)
{

    cin>>choice;
    if(choice=="init")
    {
        init();
    }
    else if(choice=="bestfit")
      {if(indicator)
          best_fit();
       else
         cout<<"disk empty\n";

      }
    else if(choice=="firstfit")
      {if(indicator)
        first_fit();
      else
        cout<<"disk empty\n";
      }
    else if(choice=="worstfit")
    {
     if(indicator)
        worst_fit();
      else
        cout<<"disk empty\n";
    }

    else if(choice=="exit")
    {
        exit(0);
    }

    else if(choice=="Help")
    {
        cout<<"----------------------------------------------------------\n";
        cout<<"bestfit --->Enter bestfit for BestFit memory allocation\n";
        cout<<"worstfit -->Enter worstfit for WorstFit memory allocation\n";
        cout<<"firstfit -->Enter firstfit for FirstFit memory allocation\n";
        cout<<"exit ------>Enter exit to Exit\n";
        cout<<"init ------>Enter init to initialise the Disk...\n";
        cout<<"Help ------>Enter Help to get command directory\n";
        cout<<"-----------------------------------------------------------\n";

    }


}



}
