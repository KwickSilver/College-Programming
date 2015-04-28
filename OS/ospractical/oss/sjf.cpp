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
    if(a.at > b.at)
    return true;
    else if(a.at == b.at) return (a.job_no > b.job_no);
    else return false;
}

bool comp2(job a, job b)
{
    if(a.bt > b.bt)
    return true;
    else if (a.bt == b.bt) { if(a.at == b.at) return(a.job_no > b.job_no); else return(a.at > b.at);}
    else return false;
}

int main()
{
    int n;
    cout<<"Enter the number of jobs\n";
    cin>>n;
    vector<job> j;
    cout<<"Enter the input in form job_no arrival time burst time\n";
    for(int i=0;i<n;i++)
    {
        job temp;
        cin>>temp.job_no>>temp.at>>temp.bt;
        j.push_back(temp);
    }
    sort(j.begin(),j.end(),comp);
    vector<job> ans;
    int t = 0;
    vector<job> temp;
    int flag = 0;
    while(1)
    {
       while(j.back().at <= t && j.size() >= 1)
       {
           temp.push_back(j.back());
           j.pop_back();
           //cout<<"hi\n";
       }
       sort(temp.begin(),temp.end(),comp2);
       t += temp.back().bt;
       if(temp.size() == 1 && j.size() == 0)
       flag = 1;
       ans.push_back(temp.back());
       temp.pop_back();
       //cout<<"size: "<<temp.size()<<endl;
       //cout<<"ans size: "<<ans.size()<<endl;
       if(flag)
       break;
    }
    //cout<<"size: "<<temp.size()<<endl;
    for(int i=temp.size();i>0;i--)
    {
        ans.push_back(temp[i]);
    }
    int c = ans[0].at;
    for(int i=0;i<ans.size();i++)
    {
        c += ans[i].bt;
        ans[i].ct = c;
        ans[i].ta = c - ans[i].at;
        ans[i].wt = ans[i].ta - ans[i].bt;
    }
    int a,b;
    a = b = 0;
    for(int i=0;i<ans.size();i++)
    {
        cout<<"job no. "<<ans[i].job_no<<" at: "<<ans[i].at<<" bt: "<<ans[i].bt<<" ct: "<<ans[i].ct<<" ta: "<<ans[i].ta<<" wt: "<<ans[i].wt<<endl;
        a+=ans[i].wt;
        b+=ans[i].ta;
    }
    cout<<"avg. wt: "<<(float)(a*1.0/ans.size())<<endl;
    return 0;
}
