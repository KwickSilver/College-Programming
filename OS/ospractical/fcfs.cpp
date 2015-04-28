#include<bits/stdc++.h>
using namespace std;

struct pcb
{
int pid;
float bt_time;
float ar_time;
pcb(int i,float j=0,float k=0){pid =i;bt_time=j;ar_time=k;}
pcb() { }
};

 typedef vector< pcb > vv;
 vector< pcb > que;
int compare(pcb a,pcb b)
{
    return a.ar_time < b.ar_time;
}

main()
{

 //time t=time();
 srand(time(NULL));
 int i,j;
int n=rand()%100+1;
 //int n=6;
 int pr=1;
 for(i=0;i<n;i++)
 {
  int ar=rand()%pr;
  int bt=rand()%10+1;
 if(pr<100) pr+=bt;
  que.push_back(pcb(i,bt,ar));
  }
  sort(que.begin(),que.end(),compare);
  float wt[n+1],wt_time;
  float tt[n+1],tt_time;
  cout<<"no of jobs="<<n<<endl;
for(i=0;i<n;i++)
{
cout<<que[i].pid<<" "<<que[i].ar_time<<" "<<que[i].bt_time<<endl;
}
 float time =0;
for(i=0;i<n;i++)
 {   wt[que[i].pid]=time-que[i].ar_time;
     time+=que[i].bt_time;
     tt[que[i].pid]=time-que[i].ar_time;
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
