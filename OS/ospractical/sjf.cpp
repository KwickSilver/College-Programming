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
pcb return_min(int n,int *per,float time)
{
   int i=0;
   int index=0;
   for(i=0;i<n;i++)
   if(per[i]==0&&que[i].ar_time<=time)index=i;
   for(i=index+1;i<n;i++)
   if(per[i]==0&&que[i].bt_time&&time>=que[i].ar_time)index=i;
   return que[index];

}
int compare(pcb a,pcb b)
{
    return a.ar_time < b.ar_time;
}
//int compare2(pcb a,pcb b)
//{

//}
main()
{
 //time t=time();
 srand(time(NULL));
 int i,j;
int n=rand()%100+1;
 //int n=6;
 int per[n];
 for(i=0;i<n;i++)per[i]=0;
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
   cout<<"average turnaround  time  = "<<(float)tt_time/n<<endl;

}
