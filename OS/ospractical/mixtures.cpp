#include<bits/stdc++.h>
using namespace std;
int a[105];
int sum[105];
int ans[105][105];
int suma(int i,int j,int n)
{
    if(i==j)return a[i];else if(i==0)return sum[j]%100;else return (sum[j]-sum[i-1])%100;
}
main()
{
int n;
int l;

while(scanf("%d",&n)>0)
{
    int i,j,k;
    int can,res;
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++)ans[i][i]=0;
    sum[0]=a[0];
    for(i=1;i<n;i++)sum[i]=(sum[i-1]+a[i]);
    for(l=2;l<=n;l++)
    {
        for(i=0;i<n-l+1;i++)
        {   res=INT_MAX;
            j=i+l-1;
            for(k=i+1;k<=j;k++)
            {
              can=ans[i][k-1]+ans[k][j] + suma(i,k-1,n)*suma(k,j,n);
           //   cout<<suma(i,k-1,n)<<" "<<suma(k,j,n)<<" "<<can<<" "<<l<<" "<<endl;
              if(can<res)res=can;
            }
            ans[i][j]=res;
        }
    }
  //  for(i=0;i<n;i++){for(j=0;j<n;j++)cout<<ans[i][j]<<" ";cout<<endl;}
    cout<<ans[0][n-1]<<endl;
}
}
