/*Author:Shantanu Kumar
 *Topic:Shortest Job first-- Non pre-emptive(SJF)
 *Date:20th January 2015
 *
 *
 */


#include<bits/stdc++.h>

using namespace std;




struct pcb
{
    int pid;
    float b_time;
    float a_time;
    int priority;
    float wait_time=0.0;

    //pcb(int p,float a=0.0,float b=0.0,int k=0){pid=p;a_time=a;b_time=b,priority=k;}
    //pcb(){};

};



//typedef struct pcb pcb;
int cmpfunc (pcb a, pcb b)
{
   return ( a.a_time < b.a_time );
}

int n_proc;
int *flag;
int decide()
{int

}

int main()
{
    float avg_wait_time,wait_time,avg_turn_around;

    srand(time(NULL));
    n_proc=10;//rand()%100+1;//number of process in the range 1 to 100
    flag =new int[n_proc];
    memset(flag,0,n_proc);
    pcb *q =new pcb[n_proc];
    int i,j=1;
    for(i=0;i<n_proc;i++)
    {
     q[i].a_time=rand()%100;
     q[i].b_time=rand()%40+1;
     q[i].pid=j;
     q[i].priority=0;
     j++;

    }


    sort(q,q+n_proc,cmpfunc);

    cout<<"hello\n";

    for(i=0;i<n_proc;i++)
    {
        cout<<q[i].pid<<" "<<q[i].a_time<<" "<<q[i].b_time<<endl;
    }

    float strt_time=0.0,turn_around=0.0;
    wait_time=0.0;
    for(i=0;i<n_proc;i++)
    {q[i].wait_time+=(strt_time-q[i].a_time);
    turn_around+=(strt_time+q[i].b_time)-q[i].a_time;
     strt_time=strt_time+q[i].b_time;
     wait_time=wait_time+q[i].wait_time;


    }

cout<<"Total wait time: "<<wait_time<<endl;
cout<<"Average wait time: "<<wait_time/n_proc<<endl;
cout<<"Average turn around time: "<<turn_around/n_proc<<endl;








}


