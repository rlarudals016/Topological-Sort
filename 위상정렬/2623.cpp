#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define MAXX_N 1000

int n,m,ind[MAXX_N+1];
vector<vector<int>> vt;
priority_queue<int> pq;
vector<int> ans;

int main(){
    scanf("%d%d",&n,&m);
    vt.resize(n+1);
    while(m--){
        int num;
        scanf("%d",&num);
        int prev,next;
        scanf("%d",&prev);
        num--;
        while(num--){
            scanf("%d",&next);
            vt[prev].push_back(next);
            ind[next]++;
            prev=next;
        }
    }
    for(int i=1;i<=n;i++){
        if(!ind[i])
            pq.push(-i);
    }
    while(!pq.empty()){
        int here=-pq.top();
        pq.pop();
        ans.push_back(here);
        for(int i=0;i<vt[here].size();i++){
            int there=vt[here][i];
            ind[there]--;
            if(!ind[there])
                pq.push(-there);
        }
    }
    if(ans.size()!=n){
        puts("0");
        return 0;
    }
    for(int i=0;i<ans.size();i++)
        printf("%d\n",ans[i]);
}
