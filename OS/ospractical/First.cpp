#include<bits/stdc++.h>
using namespace std;

int main()
{
    int block[100],required[100],ans[100];
    printf("Enter the number of blocks\n");
    int n;
    scanf("%d",&n);
    printf(" enter size of blocks \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&block[i]);
    }
    printf("Enter the number of processes\n");
    int p;
    scanf("%d",&p);
    printf("size required : \n");
    for(int i=0;i<p;i++)
    {
        scanf("%d",&required[i]);
    }
    for(int i=0;i<p;i++)
    {
        int j;
        for(j=0;j<n;j++)
        {
            if(block[j] >= required[i])
            {
                block[j] -= required[i];
                ans[i] = j;
                break;
            }
        }
        if(j == n)
        ans[i] = -1;
    }
    for(int i=0;i<p;i++)
    {
        if(ans[i] == -1)
        {
            printf("Process no %d, block can not be allocated\n",i);
        }
        else
        printf("Process no %d, block alloted: %d\n",i,ans[i]);
    }
    return 0;
}
