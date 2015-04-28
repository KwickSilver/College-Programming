#include<bits/stdc++.h>

using namespace std;

vector<int> ans;
int isSafe(int Max[][200], int Allot[][200], int Need[][200],int Avail2[200], int p, int r)
{
    int Avail[200];
    for(int i=0;i<r;i++)
    {
        Avail[i] = Avail2[i];
    }
    int flag[p];
    for(int i=0;i<p;i++)
    {
        flag[i] = 0;
    }

    int cnt = 0;
    int f3 = 0;
    while(cnt < p)
    {
        int f2 = 0;
        for(int i=0;i<p;i++)
        {

            if(flag[i] == 0)
            {
                int f = 0;
                for(int j=0;j<r;j++)
                {
                    if(Need[i][j] > Avail[j])
                    f = 1;
                }
                if(f == 0)
                {
                    //cout<<"p: "<<i<<endl;
                    f2 = 1;
                    flag[i] = 1;
                    cnt++;
                    for(int k=0;k<r;k++)
                    {
                        Avail[k] += Allot[i][k];
                    }
                    ans.push_back(i);
                }
            }
        }
        if(f2 == 0)
        {
            f3 = 1;
            break;
        }
    }
    if(f3 == 1)
    return 0;
    else
    return 1;
}

int main()
{
    cout<<"Enter the number of processes ans resources\n";
    int p,r;
    cin>>p>>r;
    int Max[200][200], Allot[200][200],Need[200][200],Avail[200],OAvail[200];
    printf("Enter the Max Matrix\n");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            cin>>Max[i][j];
        }
    }

    printf("Enter the Alloted Matrix\n");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            cin>>Allot[i][j];
        }
    }

    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            Need[i][j] = Max[i][j] - Allot[i][j];
        }
    }

    printf("Enter the Available resopurces\n");
    for(int i=0;i<r;i++)
    {
        cin>>Avail[i];
        OAvail[i] = Avail[i];
    }


    if(!isSafe(Max,Allot,Need,Avail,p,r))
    {
        cout<<"System is not in safe state\n";
    }
    else
    {
        cout<<"One of the possible order of processes\n";
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    ans.clear();
    int choice;
    cout<<"Enter 1 if any process want to request some resources else enter 0\n";
    cin>>choice;
    if(choice == 1)
    {
        int pno;
        cout<<"Enter the process number\n";
        cin>>pno;
        int temp[200];
        cout<<"Enter the request vector\n";
        for(int i=0;i<r;i++)
        {
            cin>>temp[i];
        }
        int flag = 0;
        for(int i=0;i<r;i++)
        {
            if(temp[i] > Need[pno][i])
            {
                flag = 1;
                break;
            }
        }

        for(int i=0;i<r;i++)
        {
            if(temp[i] > OAvail[i])
            {
                flag = 2;
                break;
            }
        }
        if(flag == 1)
        {
            cout<<"Request invalid ... More than needed by process\n";
        }
        else if(flag == 2)
        {
            cout<<"Request invalid ... More than Available \n";
        }
        else
        {
            for(int i=0;i<r;i++)
            {
                Allot[pno][i] += temp[i];
                Need[pno][i] -= temp[i];
                OAvail[i] -= temp[i];
            }
            if(!isSafe(Max,Allot,Need,OAvail,p,r))
            {
                cout<<"Request cannot be granted\n";
                for(int i=0;i<r;i++)
                {
                    Allot[pno][i] -= temp[i];
                    Need[pno][i] += temp[i];
                    OAvail[i] += temp[i];
                }
            }
            else
            {
                cout<<"Request can be granted and One of the possible order of processes\n";
                for(int i=0;i<ans.size();i++)
                {
                    cout<<ans[i]<<" ";
                }
                cout<<endl;
            }
        }
    }
    ans.clear();
    return 0;
}
