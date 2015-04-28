#include<bits/stdc++.h>

using namespace std;


struct SegmentTreeNode {
	int prefixMaxSum, suffixMaxSum, maxSum, sum;

	void assignLeaf(int value) {
		prefixMaxSum = suffixMaxSum = maxSum = sum = value;
	}

	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
		sum = left.sum + right.sum;
		prefixMaxSum = max(left.prefixMaxSum, left.sum + right.prefixMaxSum);
		suffixMaxSum = max(right.suffixMaxSum, right.sum + left.suffixMaxSum);
		maxSum = max(prefixMaxSum, max(suffixMaxSum, max(left.maxSum, max(right.maxSum, left.suffixMaxSum + right.prefixMaxSum))));
	}

	int getValue() {
		return maxSum;
	}
};


// T is the type of input array elements
// V is the type of required aggregate statistic

SegmentTreeNode nodes[200001];
int arr[100001];
int N;






	SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi) {
		if (left == lo && right == hi)
			return nodes[stIndex];

		int mid = (left + right) / 2;
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


	int get_Value(int lo, int hi) {
		SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
		return result.getValue();
	}



	void buildTree(int arr[], int stIndex, int lo, int hi) {
		if (lo == hi) {

			return;
		}
		int count=0;
		for(int i=lo;i<=hi;i++)
        {
            for(j=lo;j<i;j++)
            {int flag=0;
              if(arr[i]==arr[j])
              {flag=1;
                  break;
              }
            }
            count++;

        }
        nodes[stIndex].val=count;
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		buildTree(arr, left, lo, mid);
		buildTree(arr, right, mid + 1, hi);

	}



int main()
{



}
