#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct job
{
    int at;
    int bt;
    int ta;
    int ct;
    int wt;
    int job_no;
}job;

bool comp(job a, job b)
{
    if(a.at < b.at)
    return true;
    else if(a.at == b.at) return (a.job_no < b.job_no);
    else return false;
}
int main()
{
    int n;
    cout<<"Enter the number of jobs\n";
    cin>>n;
    vector<job> j;
    cout<<"Enter the input in form job_no , arrival time , burst time\n";
    for(int i=0;i<n;i++)
    {
        job temp;
        cin>>temp.job_no>>temp.at>>temp.bt;
        j.push_back(temp);
    }
    sort(j.begin(),j.end(),comp);
    queue<job> myqueue;
    for(int i=0;i<j.size();i++)
    {
        myqueue.push(j[i]);
    }
    int c = j[0].at;
    vector<job> ans;
    while(!myqueue.empty())
    {
        job temp = myqueue.front();
        myqueue.pop();
        c += temp.bt;
        temp.ct = c;
        temp.ta = c - temp.at;
        temp.wt = temp.ta - temp.bt;
        ans.push_back(temp);
    }
    int a,b;
    a = b = 0;
    for(int i=0;i<ans.size();i++)
    {
        cout<<"job no. "<<ans[i].job_no<<" arrival time : "<<ans[i].at<<" burst time: "<<ans[i].bt<<" completion time : "<<ans[i].ct<<" total arrival : "<<ans[i].ta<<" weighting time: "<<ans[i].wt<<endl;
        a+=ans[i].wt;
        b+=ans[i].ta;
    }
    cout<<"avg. weighting time : "<<(float)(a*1.0/ans.size())<<endl;
    return 0;
}
