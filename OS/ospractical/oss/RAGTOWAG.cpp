#include<bits/stdc++.h>
using namespace std;

// coded by shubham1402
//Shubham Goel
//CO 6
//111799
int main()
{
    cout<<"Enter the number of processe and resources\n";
    int p,r;
    cin>>p>>r;
    int want[p][r];
    cout<<"Enter the 2-D matrix such that if ith process want jth resource mark the edge 1 otherwise 0\n";
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            cin>>want[i][j];
        }
    }
    int allot[p][r];
    cout<<"Enter the 2-D matrix such that if ith process is alloted jth resource mark the edge 1 otherwise 0\n";
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            cin>>allot[i][j];
        }
    }
    int wforg[p][p];
    for(int  i=0;i<p;i++)
    {
        for(int j=0;j<p;j++)
        {
            wforg[i][j] = 0;
        }
    }
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            if(want[i][j])
            {
                for(int k=0;k<p;k++)
                {
                    if(allot[k][j])
                    {
                        wforg[i][k] = 1;
                    }
                }
            }
        }
    }
    cout<<"Required wait for graph is :\n";
    cout<<"1 at i j represents process i is dependent on j otherwise not\n";
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<p;j++)
        {
            cout<<wforg[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
