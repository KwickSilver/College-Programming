#include<bits/stdc++.h>
using namespace std;

struct pcb
{
int pid;
float bt_time;
float ar_time;
int priority;
pcb(int i,float j=0,float k=0,int p=0){pid =i;bt_time=j;ar_time=k;priority=p;}
pcb() { }
};


typedef vector< pcb > vv;

list< pcb > que;

int compare(pcb a,pcb b)
{
    return a.ar_time < b.ar_time;
}

#define MAX_LENGTH 1024
int id=0;
void frk(){srand(time(NULL));
  id++;
  int ar=rand()%10;
  int bt=rand()%10+1;
  que.push_back(pcb(id,bt,ar));
}
void fcfs()
{
int i,j;
int n=que.size();
  que.sort(compare);
  float wt[n+1],wt_time;
  float tt[n+1],tt_time;
  cout<<"no of jobs="<<n<<endl;
  list< pcb >::iterator it=que.begin();
for(i=0;i<n;i++)
{
cout<<it->pid<<" "<<it->ar_time<<" "<<it->bt_time<<endl;it++;
}
it=que.begin();

 float time =it->ar_time;
for(i=0;i<n;i++)
 {   wt[it->pid]=time-it->ar_time;
     time+=it->bt_time;
     tt[it->pid]=time-it->ar_time;it++;
   }
   wt_time=0;tt_time=0;
   for(i=0;i<n;i++)
   {
       wt_time+=wt[i];
       tt_time+=tt[i];
   }
   cout<<"average wait time  = "<<(float)wt_time/n<<endl;
   cout<<"average turnaround  time  = "<<(float)tt_time/n<<endl;

}

pcb return_min(int n,int *per,float time)
{
   int i=0;
   int index=0;list< pcb >::iterator it=que.begin();
   for(i=0;i<n;i++,it++)
   if(per[i]==0&&it->ar_time<=time)index=i;
   for(i=index+1;i<n;i++)
   if(per[i]==0&&it->bt_time&&time>=it->ar_time)index=i;
   return *it;

}
void sjf()
{
/*
 srand(time(NULL));
 int i,j;
int n=que.size();

 int per[n];
que.sort(compare);
  float wt[n+1],wt_time;
  float tt[n+1],tt_time;
  cout<<"no of jobs="<<n<<endl;
  for(i=0;i<n;i++)
  {
  cout<<que[i].pid<<" "<<que[i].ar_time<<" "<<que[i].bt_time<<endl;
   }
cout<<"order of job performed"<<endl;
float time =0;
for(i=0;i<n;i++)
 {
     pcb m=return_min(n,per,time);
     per[m.pid]=1;
     wt[m.pid]=time-m.ar_time;
     time+=m.bt_time;
     tt[m.pid]=time-m.ar_time;
     cout<<m.pid<<" "<<m.ar_time<<" "<<m.bt_time<<endl;

   }
   wt_time=0;tt_time=0;
   for(i=0;i<n;i++)
   {
       wt_time+=wt[i];
       tt_time+=tt[i];
   }
   cout<<"average wait time  = "<<(float)wt_time/n<<endl;
   cout<<"average turnaround  time  = "<<(float)tt_time/n<<endl;*/

}

int comp(string cmd)
{
    if(cmd=="fcfs")
    return 5;
    else if(cmd=="sjf")
    return 6;
    else if(cmd=="ps")return 1;
    else if(cmd=="fork")return 2;
    else if(cmd=="kill")return 3;
}
int ps()
{
list<pcb>::iterator it=que.begin();
cout<<"processes are "<<endl;
while(it!=que.end())
{
    cout<<it->pid<<" "<<it->ar_time<<" "<<it->bt_time<<" "<<it->priority<<endl;
it++;
};
}


void kll(int pid)
{
list<pcb>::iterator it=que.begin();
for(;it!=que.end();it++)if(it->pid==pid)break;
que.erase(it);
}
int main(int argc, char *argv[]) {
    srand(time(NULL));
  string line;
int pid;
  while (1) {
    printf("$ ");

    cin>>line;

    int c=comp(line);
    switch(c)
    {   case 1:ps();break;
        case 2:frk();break;
        case 3:cin>>pid;kll(pid);break;
        case 5:fcfs();break;
        case 6:sjf();break;
    }

  }

  return 0;
}
