
#include<bits/stdc++.h>
#define MAX 100005
using namespace std;

long long arr[100005];
long long bit[100005];



void update(long long index,long val)
{
  for(long long i=index;i<MAX;i+=i&(-i))
  {
      bit[i]+=val;
  }

}

long long querry(long long index)
{
    long long val=0;

    while(index)
    {
        val+=bit[index];
        index-=index&(-index);
    }

    return val;

}


int main()
{
long long i,j,k,l,r,n;

cin>>n;


for(i=1;i<=n;i++)
{cin>>arr[i];
if(arr[i]%2==0)
update(i,1);
}


long long q;

cin>>q;

while(q--)
{
    long long t;
    cin>>t>>l>>r;

    if(t==0)
    {

        if(r%2==0&&arr[l]%2==1)
         {update(l,1);
         arr[l]=r;
         }
        if(r%2==1&&arr[l]%2==0)
        {update(l,0);
         arr[l]=r;

        }
    }

    else if(t==1)
    {
        cout<<querry(r)-querry(l-1)<<endl;
    }

    else
    {
        cout<<(r-l+1)-(querry(r)-querry(l-1))<<endl;
    }
}

}









