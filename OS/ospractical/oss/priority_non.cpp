#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct job
{
    int job_no;
    int at;
    int ct;
    int bt;
    int rt;
    int wt;
    int tt;
    int p;
}job;

bool comp(job a, job b)
{
    if(a.at > b.at) return true;
    else if(a.at == b.at) return(a.job_no > b.job_no);
    else return false;
}
bool comp2(job a, job b)
{
    if(a.p > b.p) return true;
    else if(a.p == b.p) return comp(a,b);
    else return false;
}
int main()
{
    int n;
    cout<<"Enter the number of jobs\n";
    cin>>n;
    vector<job> j;
    cout<<"Enter the jobs \n aarival time , burst time , priority \n";
    for(int i=0;i<n;i++)
    {

        job temp;
        temp.job_no = i;
        cin>>temp.at>>temp.bt>>temp.p;
        temp.rt = temp.bt;
        j.push_back(temp);
    }
    sort(j.begin(),j.end(),comp);
    vector<job> v2;
    vector<job> ans;
    int t = 0;
    while(1)
    {
        //cout<<"size "<<j.size()<<endl;
        while(j.size() >0 && j.back().at <= t)
        {
            v2.push_back(j.back());
            j.pop_back();
        }
        sort(v2.begin(),v2.end(),comp2);
        t += v2.back().bt;
        v2.back().ct = t;
        ans.push_back(v2.back());
        v2.pop_back();
        if(v2.size() == 0 && j.size() == 0)
        break;
    }

    float avgw=0;
    for(int i=0;i<ans.size();i++)
    {
        ans[i].tt = ans[i].ct - ans[i].at;
        ans[i].wt = ans[i].tt - ans[i].bt;
        avgw += ans[i].wt;
        cout<<ans[i].job_no<<"  "<<ans[i].at<<"   "<<ans[i].bt<<"  "<<ans[i].p<<"  "<<ans[i].ct<<"  "<<ans[i].tt<<"  "<<ans[i].wt<<endl;
    }
    cout<<"avg wt : "<<(avgw/(n*1.0));
    return 0;
}
