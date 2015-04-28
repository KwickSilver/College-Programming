#include  <stdio.h>
#include  <sys/types.h>

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */
int cmpfunc1(int a,int b)
{
    return b>a;
}
int cmpfunc2(int a,int b)
{
    return a>b;
}
void  main(void)
{
     pid_t  pid;

     pid = fork();
     if (pid == 0)
          ChildProcess();
     else
          ParentProcess();
}

void  ChildProcess(void)
{
     int   n,i,j;
     int arr[100];

     cin>>n;
     for(i=0;i<n;i++)
     {
         cin>>arr[i];
     }

     sort(arr,arr+n,cmpfunc1);

     cout<<"Array in sorted order: ";

     for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
     cout<endl;


}

void  ParentProcess(void)
{
     int   n,i,j;
     int arr[100];

     cin>>n;
     for(i=0;i<n;i++)
     {
         cin>>arr[i];
     }

     sort(arr,arr+n,cmpfunc2);

     cout<<"Array in sorted order: ";

     for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
     cout<endl;

}
