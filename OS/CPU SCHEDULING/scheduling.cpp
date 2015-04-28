/*Author:Shantanu Kumar
 *Topic:CPU SCHEDULING ALGORITHMS
 *Date:20th January 2015
 *Copyright Reserved
 *Copy of this code can be done only after seeking permission of the author
 */


#include<bits/stdc++.h>

using namespace std;



/*
 *pcb is a structure of process control block of the processes in CPU
 *pid --> represents process id
 *b_time->represents burst time
 *a_time->represents arrival time of the process
 *priority-->represents priority of the process
 */

struct pcb
{
    int pid;
    float b_time;
    float a_time;
    float strt_time=0.0;
    int priority;

    float wait_time=0.0;

    pcb(int p,float a=0.0,float b=0.0,int k=0){pid=p;a_time=a;b_time=b,priority=k;}
    pcb(){};

};
//q -->is ready Queue
list<pcb> q;

int n_proc=0;
//typedef struct pcb pcb;
int cmpfunc (pcb a, pcb b)
{
   return ( a.a_time < b.a_time );
}

//fcfs is a module that simulates first come first serve scheduler

void fcfs()
{

    if(n_proc>0)
    {q.sort(cmpfunc);// sorts the process in ready queue according to their arrival time

    list<pcb>::iterator it;
   /* for(it=q.begin();it!=q.end();it++)
    {
        cout<<it->pid<<" "<<it->a_time<<" "<<it->b_time<<endl;
    }

    */

    float strt_time=0.0,turn_around=0.0;
    float wait_time=0.0;
    for(it=q.begin();it!=q.end();it++)
    {
        if(strt_time  >= (it->a_time))
            it->wait_time+=(strt_time-it->a_time);
        else
            it->wait_time=0.0;

     if(it->a_time>strt_time)
        turn_around+=it->b_time;
        else
        turn_around+=(strt_time+it->b_time)- (it->a_time);
     if(it->a_time>strt_time)
        strt_time=it->a_time+it->b_time;
     else
        strt_time+=it->b_time;
     wait_time=wait_time+it->wait_time;


    }

cout<<"Total wait time:  "<<wait_time<<endl;
cout<<"Average wait time:  "<<wait_time/n_proc<<endl;
cout<<"Average turn around time:  "<<turn_around/n_proc<<endl;
cout<<endl;

return;
}

else
    cout<<"No Process in the Ready Queue\n"<<endl;

}

//Creating min haep

pair<int,int> heap[1001];
int h_size=0;

int parent(int i)
{if(h_size>1)
    return (i-1)/2;
 else return -1;
}

int left(int i)
{int l=2*i+1;
 if(l<h_size)
    return l;
 else
    return -1;

}

int right(int i)
{int r=2*i+2;
 if(r<h_size)
    return r;
 else
    return -1;

}
void percolate_down(int i)
{
    int l=left(i);
    int r=right(i);
    int min_index=i;
   // cout<<"l r i"<<l<<r<<i<<endl;

    if(l!=-1&&heap[i].first>heap[l].first)
        min_index=l;
    if(r!=-1&&heap[min_index].first>heap[r].first)
        min_index=r;
    if(min_index!=i)
    {pair<int,int> temp=heap[i];
    heap[i]=heap[min_index];
    heap[min_index]=temp;
    percolate_down(min_index);

    }

}


void insertHeap(int data,int index)
{
    h_size+=1;
    int i=h_size-1;
    while(i>0&&data<heap[(i-1)/2].first)
    {
        heap[i]=heap[(i-1)/2];
        i=(i-1)/2;
    }
    pair<int,int> temp;
    temp.first=data;
    temp.second=index;
    heap[i]=temp;
}

int getMin()
{
    if(h_size==0)
        return -1;
    else
        return heap[0].second;

}

int deleteMin()
{
    if(h_size==0)
        return -1;
    else
    {
        pair<int,int> data=heap[0];
        heap[0]=heap[h_size-1];
        h_size--;
        percolate_down(0);
        return data.second;
    }
}

//find_proc return the pointer to the pcb of a process in ready queue given its pid

 list<pcb>::iterator find_proc(int pid)
{list<pcb>::iterator t;
    for(t=q.begin();t!=q.end();t++)
    {
        if(t->pid==pid)
          return t;

    }

}

//priority scheduler

void priority_scheduling()
{
if(n_proc>0)
  {h_size=0;
  q.sort(cmpfunc);
  list<pcb>::iterator it,i;
  int count=0;
  float time=0.0,wait_time=0.0,t;

  it=q.begin();

  insertHeap(it->priority,it->pid);
  t=it->a_time;
  it++;

  for(;it!=q.end();it++)
  {if(t==it->a_time)
  insertHeap(it->priority,it->pid);
  else
    break;
  }

   int id=getMin();
   i=find_proc(id);
   time+=t+i->b_time;
   i->strt_time=i->a_time;

   count++;
   deleteMin();

  while(count<n_proc)
    {//insert all the process in the min Heap which has arrived
      if(it!=q.end())
      {  while(it->a_time<=time&&it!=q.end())
         {insertHeap(it->priority,it->pid);
         it++;
         }
      }
      int id=getMin();
      i=find_proc(id);
      if((i->a_time)<=time)
      {   i->wait_time=time-(i->a_time);
          i->strt_time=time;
          time=time+i->b_time;
          deleteMin();
          count++;
      }

      else if(h_size!=0)
      {
           i->wait_time=0.0;
           i->strt_time=i->a_time;
           time=i->strt_time+i->b_time;
          deleteMin();
          count++;
      }
  }
  float tot_WaT=0.0,avgWaT,TaT=0.0,avgTaT;
  for(it=q.begin();it!=q.end();it++)
  {
      tot_WaT+=it->strt_time-it->a_time;
      TaT+=it->strt_time+it->b_time-it->a_time;
  }

  cout<<"Total Waiting Time------>"<<tot_WaT<<endl;
  cout<<"Average waiting time---->"<<tot_WaT/n_proc<<endl;
  cout<<"Total Turn Around Time-->"<<TaT<<endl;
  cout<<"Avg. Turn Around Time--->"<<TaT/n_proc<<endl;
  cout<<endl;

}

else
    cout<<"No Process in the Ready Queue\n"<<endl;
}


//Shortest Job First Non Preemptive scheduler

void sjf_np()
{
  if(n_proc>0)
  {h_size=0;
 q.sort(cmpfunc);
  list<pcb>::iterator it,i;
  int count=0;
  float time=0.0,wait_time=0.0,t;

  it=q.begin();

  insertHeap(it->b_time,it->pid);
  t=it->a_time;
  it++;

  for(;it!=q.end();it++)
  {if(t==it->a_time)
  insertHeap(it->b_time,it->pid);
  else
    break;
  }

   int id=getMin();
   i=find_proc(id);
   time+=t+i->b_time;
   i->strt_time=i->a_time;

   count++;
   deleteMin();

  while(count<n_proc)
    {
     if(it!=q.end())
      {  while(it->a_time<=time&&it!=q.end())
         {insertHeap(it->b_time,it->pid);
         it++;
         }
      }
      int id=getMin();
      i=find_proc(id);
      if((i->a_time)<=time)
      {  // cout<<"time:"<<time<<endl;
          //cout<<"Atime:"<<i->a_time<<endl;

          i->wait_time=time-(i->a_time);
          //cout<<"waitTime:"<<i->wait_time<<endl;
          i->strt_time=time;
          time=time+i->b_time;
          deleteMin();
          count++;
      }

      else if(h_size!=0)
      {
           i->wait_time=0.0;
           i->strt_time=i->a_time;
           time=i->strt_time+i->b_time;
          deleteMin();
          count++;
      }
  }
  float tot_WaT=0.0,avgWaT,TaT=0.0,avgTaT;
  for(it=q.begin();it!=q.end();it++)
  {
      tot_WaT+=it->strt_time-it->a_time;
      TaT+=it->strt_time+it->b_time-it->a_time;
  }

  cout<<"Total Waiting Time------>"<<tot_WaT<<endl;
  cout<<"Average waiting time---->"<<tot_WaT/n_proc<<endl;
  cout<<"Total Turn Around Time-->"<<TaT<<endl;
  cout<<"Avg. Turn Around Time--->"<<TaT/n_proc<<endl;
  cout<<endl;

  }
  else
  {
      cout<<"No process in the Ready Queue\n"<<endl;
  }



}



//Shows all details regarding the processes in the Ready Queue

void show_processes()
{
    cout<<"No. of processes in queue: "<<n_proc<<endl;

    list<pcb>::iterator it;

    if(n_proc)
    {cout<<"PID      "<<"Burst time    "<<"Arrival time   \n";
    for(it=q.begin();it!=q.end();it++)
        cout<<it->pid<<setw(15)<<it->b_time<<setw(15)<<it->a_time<<endl;
        cout<<endl;
    return ;
    }
}


//to add process with given arrival time,burst time and process id in the ready queue

void add_process(float a,float b,int p)
{
    pcb temp;
    n_proc=n_proc+1;
    temp.pid=n_proc;
    temp.a_time=a;
    temp.b_time=b;
    temp.priority=p;

    q.push_back(temp);
    cout<<"Process had been added to the ready queue\n";
    cout<<"No. of processes :"<<n_proc<<endl;
    cout<<endl;

}
//rem_process removes the process with given pid from the ready queue



void rem_process(int pid)
{
list<pcb>::iterator t;
    for(t=q.begin();t!=q.end();t++)
    {
        if(t->pid==pid)
          break;
    }
    q.erase(t);
    n_proc--;
}
// init initialises the pcb of processes in the ready queue

void init()
{
    list<pcb>::iterator it;
    for(it=q.begin();it!=q.end();it++)
    {
        it->strt_time=0.0;
        it->wait_time=0.0;
    }

}
int main()
{
    float avg_wait_time,wait_time,avg_turn_around;

    int i;
    srand(time(NULL));
    //n_proc=10 ;//rand()%100+1;//number of process in the range 1 to 100
    cout<<"********************************************************************************\n";
   printf("                                 CPU SCHEDULER                                  \n");
    cout<<"********************************************************************************\n";

    cout<<"\n                   Enter help To Get Command Directory\n\n";

    /*int j=1;
    for(i=0;i<n_proc;i++)
    {pcb test;
    test.a_time=rand()%100;
    test.b_time=rand()%40+1;
    test.pid=j;
    test.priority=0;

    q.push_back(test);
    j++;
    }
    */


    while(1)
    { cout<<"$";
      int i,j,k;
      float a=0.0,b=0.0;
      char cmd[1001];

      cin>>cmd;




    if(!strcmp(cmd,"ps"))
        {show_processes();
        }
    if(!strcmp(cmd,"fork"))
    {
      float a,b;
      int p;
      cin>>a>>b>>p;

     add_process(a,b,p);
    }

    if(!strcmp(cmd,"kill"))
    {
        cin>>k;
      rem_process(k);
    }

    if (!strcmp(cmd,"fcfs"))
        { init();
        fcfs();
        }
    if(!strcmp(cmd,"PSchedule"))
        {    init();
            priority_scheduling();
        }
    if(!strcmp(cmd,"SJFNP"))
        {    init();
            sjf_np();
        }
    if(!strcmp(cmd,"help"))
    {
        cout<<"ps -------->To show the processes present in the ready queue\n";
        cout<<"fork ------>To add process to the ready queue\n";
        cout<<"kill ------>To remove a process with given pid from ready queue\n";
        cout<<"fcfs ------>For FirstComeFirstServe CPU Scheduling\n";
        cout<<"PSchedule ->For Priority Scheduling\n";
        cout<<"SJFNP ----->For Shortest Job First Non Preemptive Scheduling\n";
        cout<<"help ------>For listing commands\n\n";
    }



}











}

