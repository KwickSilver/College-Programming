
#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int val;
    int ind;
}node;

bool comp(node a, node b)
{
    return (a.val < b.val);
}

int main()
{
    int required[100],ans[100];
    node block[100];
    printf("Enter the number of blocks\n");
    int n;
    scanf("%d",&n);
    printf("enter the block size :\n");
    for(int i=0;i<n;i++)
    {
    	
        scanf("%d",&block[i].val);
        block[i].ind = i;
    }
    printf("Enter the number of processes\n");
    int p;
    scanf("%d",&p);
    printf(" space required :\n ");
    for(int i=0;i<p;i++)
    {
    	
        scanf("%d",&required[i]);
    }
    for(int i=0;i<p;i++)
    {
        sort(block,block+n,comp);
        int j;
        for(j=0;j<n;j++)
        {
            if(block[j].val >= required[i])
            {
                block[j].val -= required[i];
                ans[i] = block[j].ind;
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
