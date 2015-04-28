#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct file
{
int inode;
char filename[100];
int size;
char content[100];
};

file arr[11];
file *table[11];
int main()
{
int i;
for(i=1;i<=3;i++)
{
cout<<"enter "<<i<<" file name ";
cin>>arr[i].filename;
cout<<"inode ";
cin>>arr[i].inode;
cout<<"input content";
cin>>arr[i].content;
int l;
l=strlen(arr[i].content);
arr[i].size=l;
table[i]=&arr[i];
}
cout<<"files created \n\n\n";


while(1)
{
int n;
cout<<"\n\nenter inode\n";
cin>>n;
int flag=0;
for(i=1;i<=3;i++)
{

    if(arr[i].inode==n)
    {

        flag=1;
        cout<<"filename is "<<arr[i].filename;
        cout<<"  inode is "<<n;
        cout<<" contents are :"<<arr[i].content;
        cout<<" size of file is "<<arr[i].size<<" bytes";
        cout<<"  address is "<<table[i];
    }

}
if(flag==0)
    {
        cout<<"\ninvalid inode";
    }

}
return 0;
}
