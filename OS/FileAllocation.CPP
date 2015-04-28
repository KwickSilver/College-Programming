#include<bits/stdc++.h>

using namespace std;



struct file
{
string filename;

long long file_size;
long long file_start;
};

struct file f[1000005];



struct filenode
{
    string name;
    long long file_size;
    long long file_strat;
    filenode* next;

};



/************************************************************
*CONTIGUOS FILE ALLOCATION OR ARRAY ALLOCATION              *
*KEY POINTS:                                                *
1.)Each file occupies a set of contiguous blocks on the disk*
2.)Simple – only starting location (block #) and length     *
  (number of blocks) are required                           *
3.) Random access.                                          *
4.) Wasteful of space (dynamic storage-allocation problem). *
5.)Files cannot grow.                                       *
*************************************************************/




void arrayAllocation(int start)
{

/*****************************************
 * n: number of files to be allocated    *
 * start: starting address of the files  *
 *****************************************/
long long i,j,n,start;

printf("Enter the no. of file:\n");

cin>>n;

printf("Enter details for each file:\n");

for(i=0;i<n;i++)
{   cout<<"File Name: ";
    cin>>f[i].filename;
    cout<<"Enter the no. of block required for file "<<i+1<<":";
    cin>>f[i].file_size;

}

//start=0;

printf("File name\tStart\tSize of file\t\t\n");

start=0;

for(i=0;i<n;i++)
{f[i].file_start=start;
cout<<f[i].filename;
printf("\t\t%lld\t\t%lld\n",f[i].file_start,f[i].file_size);
start+=f[i].file_size;
}





void linkedList( )
{



}



int main()
{





}
}
