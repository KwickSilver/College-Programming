#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

typedef struct job
{
    int at;
    int bt;
    int ta;
    int ct;
    int wt;
    int rt;
    int job_no;
}job;
bool comp(job a, job b)
{
    if(a.at > b.at)
    return true;
    else if(a.at == b.at) return (a.job_no > b.job_no);
    else return false;
}
bool comp2(job a, job b)
{
    if(a.rt > b.rt)
    return true;
    else if (a.rt == b.rt) { if(a.at == b.at) return(a.job_no > b.job_no); else return(a.at > b.at);}
    else return false;
}
int main()
{
    int n;
    cout<<"Enter the number of jobs :\n";
    cin>>n;
    vector<job> j;
    cout<<"Enter the input in form job_no, arrival time, burst time\n";
    for(int i=0;i<n;i++)
    {
        job temp;
        cin>>temp.job_no>>temp.at>>temp.bt;
        temp.rt = temp.bt;
        j.push_back(temp);
    }
    sort(j.begin(),j.end(),comp);
    int cp = 0;
    int t = 0;
    vector<job> temp;
    vector<job> ans;
    while(1)
    {
       while(j.back().at <= t && j.size()>=1)
       {
           temp.push_back(j.back() );
           j.pop_back();
       }
       sort(temp.begin(),temp.end(),comp2);
       t++;
       temp.back().rt -= 1;
       if(temp.back().rt == 0)
       {
           temp.back().ct = t;
           ans.push_back(temp.back());
           temp.pop_back();
       }
       if(temp.size()== 0 && j.size() == 0)
       break;
    }
    for(int i=0;i<ans.size();i++)
    {
        ans[i].ta = ans[i].ct - ans[i].at;
        ans[i].wt = ans[i].ta - ans[i].bt;
    }
    int a,b;
    a = b = 0;
    cout<<"jobno. arrival time  burst time completion time total arrival time  weighting time\n";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].job_no<<"\t"<<ans[i].at<<"\t"<<ans[i].bt<<"\t"<<ans[i].ct<<"\t"<<ans[i].ta<<"\t"<<ans[i].wt<<endl;
        a+=ans[i].wt;
        b+=ans[i].ta;
    }
    cout<<"avg. wt: "<<(float)(a*1.0/ans.size())<<endl;
    return 0;
}

