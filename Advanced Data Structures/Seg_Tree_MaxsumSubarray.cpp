#include<bits/stdc++.h>

using namespace std;






struct SegmentTreeNode {
	long long sum,non_zero;

	void assignLeaf(long long  value) {
	 sum = value;
	 if(value>0)
	 non_zero=1;
	 else non_zero=0;
	}

	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
		sum = left.sum + right.sum;
		non_zero=left.non_zero+right.non_zero;
	}

	long long  getValue() {

		return sum;
	}
};


// T is the type of input array elements
// V is the type of required aggregate statistic

SegmentTreeNode nodes[4000001];
long long  arr[1000001];
long long  N;







	SegmentTreeNode getValue(long long  stIndex, long long  left, long long  right, long long  lo, long long  hi) {
		if (left == lo && right == hi)
			return nodes[stIndex];

		long long  mid = (left + right) / 2;
		if (lo > mid)
			return getValue(2*stIndex+1, mid+1, right, lo, hi);
		if (hi <= mid)
			return getValue(2*stIndex, left, mid, lo, hi);

		SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
		SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
		SegmentTreeNode result;
		result.merge(leftResult, rightResult);
		return result;
	}


	long long  get_Value(long long  lo, long long  hi) {
		SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
		return result.getValue();
	}

	void updateUtil(long long  stIndex, long long  lo, long long  hi, long long  index, long long  value) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(value);
			return;
		}

		long long  left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		if (index <= mid)
			updateUtil(left, lo, mid, index, value);
		else
			updateUtil(right, mid+1, hi, index, value);

		nodes[stIndex].merge(nodes[left], nodes[right]);
	}

	void update(long long  index, long long  value) {
		updateUtil(1, 0, N-1, index, value);
	}

	void buildTree(long long  arr[], long long  stIndex, long long  lo, long long  hi) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(arr[lo]);
			return;
		}

		long long  left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		buildTree(arr, left, lo, mid);
		buildTree(arr, right, mid + 1, hi);
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
long long  find_kth (long long  v, long long  tl, long long  tr, long long  k) {
	if (k >nodes[v].non_zero)
		return -1;
		//cout<<"Nonzero:"<<nodes[v].non_zero<<endl;

		//cout<<"Tl"<<tl<<endl;
	if (tl == tr)
		return tl;
	long long  tm = (tl + tr) / 2;
	if (nodes[v*2].non_zero >= k)
		return find_kth (v*2, tl, tm, k);
	else
		return find_kth (v*2+1, tm+1, tr, k - nodes[v*2].non_zero);
}





int main()
{long long  test;
//cin>>t;
scanf("%lld",&test);
while(test--)
{

    long long  i,j,k;
long long  M;
scanf("%lld%lld",&N,&M);

//input(N);
for(i=0;i<N;i++)
    scanf("%d",&arr[i]);
buildTree(arr, 1, 0, N-1);

while(M--)
{
    long long  x,y,t;

      //cin>>t;
      scanf("%lld",&t);
      if(t==1)
        {//cin>>x>>y;
            scanf("%lld%lld",&x,&y);
        x=find_kth(1,0,N-1,x);
        y=find_kth(1,0,N-1,y);
        //cout<<"x y:"<<x<<y<<endl;
         printf("%lld\n",get_Value(x,y));}



      else
        {scanf("%lld",&x);
         x=find_kth(1,0,N-1,x);
         update(x,0);

        }


    //if(t==0)
      // update(x-1,y);
    //else



}


}

}
