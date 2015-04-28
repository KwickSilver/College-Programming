#include<bits/stdc++.h>
using namespace std;

int arr[1001],heap[1001],h_size=0;

int parent(int i)
{if(h_size>1)
    return (i-1)/2;
 else return -1;
}

int left(int i)
{int l=2*i+1;
 if(l<h_size)
    return l;
 else
    return -1;

}

int right(int i)
{int r=2*i+2;
 if(r<h_size)
    return r;
 else
    return -1;

}
void heapify(int i)
{
    int l=left(i);
    int r=right(i);
    int min_index=i;
   // cout<<"l r i"<<l<<r<<i<<endl;

    if(l!=-1&&heap[i]>heap[l])
        min_index=l;
    if(r!=-1&&heap[min_index]>heap[r])
        min_index=r;
    if(min_index!=i)
    {int temp=heap[i];
    heap[i]=heap[min_index];
    heap[min_index]=temp;
    heapify(min_index);

    }

}

void buildHeap(int n)
{int i;
h_size=n;
for(i=0;i<n;i++)
    heap[i]=arr[i];

for(i=(n-1)/2;i>=0;i--)
{
    heapify(i);
}

}



void insertHeap(int data)
{
    h_size+=1;
    int i=h_size-1;
    while(i>0&&data<heap[(i-1)/2])
    {
        heap[i]=heap[(i-1)/2];
        i=(i-1)/2;
        //cout<<i<<endl;
    }
    heap[i]=data;
}

int getMin()
{
    if(h_size==0)
        return -1;
    else
        return heap[0];

}

int delete_Min()
{
    if(h_size==0)
        return -1;
    else
    {
        int data=heap[0];
        heap[0]=heap[h_size-1];
        h_size--;
        heapify(0);
    }
}


int main()
{
int i,j,n;
cin>>n;
for(i=0;i<n;i++)
    cin>>arr[i];
buildHeap(n);
for(i=0;i<h_size;i++)
    cout<<heap[i]<<" ";
    cout<<endl;
cout<<getMin();
}
