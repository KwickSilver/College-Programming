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
}job;

bool comp(job a, job b)
{
    if(a.at > b.at) return true;
    else if(a.at == b.at) return(a.job_no > b.job_no);
    else return false;
}
int main()
{
    int n;
    cout<<"Enter the number of jobs\n";
    cin>>n;
    vector<job> j;
    cout<<"Enter the jobs\n";
    for(int i=0;i<n;i++)
    {
        job temp;
        temp.job_no = i;
        cin>>temp.at>>temp.bt;
        temp.rt = temp.bt;
        j.push_back(temp);
    }
    cout<<"Enter the value of time quanta\n";
    int time;
    cin>>time;
    sort(j.begin(),j.end(),comp);
    int count = 0;
    int t = 0;
    int flag = 1;
    vector<job> v2;
    while(flag)
    {
        //cout<<"t: "<<t<<endl;
        int prev = v2.size();
        while(j.size() > 0 && j.back().at <= t)
        {
            //cout<<"hi\n";
            v2.push_back(j.back());
            j.pop_back();
        }
        int next = v2.size();
        int i;
        if(prev == next)
        i = 0;
        else
        i = prev;
        for(;i<v2.size();i++)
        {
            if(v2[i].rt > time)
            {
                v2[i].rt -= time;
                t += time;
            }
            else if(v2[i].rt != 0)
            {
                //cout<<"rt: "<<v2[i].rt<<endl;
                //cout<<"t: "<<t<<endl;
                //cout<<"no: "<<v2[i].job_no<<endl;
                t += v2[i].rt;
                v2[i].rt = 0;
                v2[i].ct = t;
                count++;
            }
            if(count == n)
            {
                flag = 0;
                break;
            }
        }
    }
    float avgw=0;
    for(int i=0;i<n;i++)
    {
        v2[i].tt = v2[i].ct - v2[i].at;
        v2[i].wt = v2[i].tt - v2[i].bt;
        avgw += v2[i].wt;
        cout<<v2[i].job_no<<" "<<v2[i].at<<" "<<v2[i].bt<<" "<<v2[i].ct<<" "<<v2[i].tt<<" "<<v2[i].wt<<endl;
    }
    cout<<"avg wt : "<<(avgw/(n*1.0));
    return 0;
}
