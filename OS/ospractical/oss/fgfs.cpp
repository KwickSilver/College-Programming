#include<cstdio>
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
#define pii pair<int, int>
#define pit pair <pii, pii>
#define F first
#define S second
vector<pit> person;
int main(){
    int tc,n,comp,s,f,p,time,count,flag,same;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&comp);
        person.resize(n);
        count = 0;
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&s,&f,&p);
            person[i]=pit(pii(p,f),pii(s,f-s));
        }
        sort(person.begin(),person.end());
        if(n==0)
            printf("0\n");
        else{
            int i=0;
            count=1;
            for(int m=1;m<n;m++){
                if(person[m].S.F >= person[i].F.S || person[m].F.F != person[i].F.F){
                    count++;
                    i=m;
                }
            }
            printf("%d\n",count);
        }
    }
    return 0;
}
