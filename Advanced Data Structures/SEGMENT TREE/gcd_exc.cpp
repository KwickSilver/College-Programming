#include<bits/stdc++.h>

using namespace std;

long long arr[100001],pre[100001],post[100001];
inline void input(long long &x)
{register long long c = getchar_unlocked();
    x = 0;
    int neg = 0;
    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
    if(c=='-') {
            neg = 1;
    c = getchar_unlocked();
    }
    for(; c>47 && c<58 ; c = getchar_unlocked())//use getchar instead of getchar_unlocked to test on pc
        {
            x = (x<<1) + (x<<3) + c - 48;
    }
if(neg)
x = -x;
}


long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    else
        gcd(b,a%b);
}


void preprocess(long long n)
{pre[1]=arr[1];
 post[1]=arr[n];

for(long long i=2;i<=n;i++)
{
pre[i]=gcd(pre[i-1],arr[i]);
post[i]=gcd(post[i-1],arr[n-i+1]);
}

}




int main()
{
 long long num,querry,test;
 input(test);

while(test--)
{long long i;
   input(num);
   input(querry);


    for(i=1;i<=num;i++)
       input(arr[i]);
    preprocess(num);
    while(querry--)
    {long long left,right;

        input(left);
        input(right);

        if(left==1)
        printf("%d\n",post[num-right]);
        else if(right==num)
            printf("%d\n",pre[left-1]);


        else
            printf("%d\n",gcd(pre[left-1],post[num-right]));
    }
}

}
