#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define MAXX_N 32000

vector<vector<int>> vt;
int n,m,ind[MAXX_N+1];
priority_queue<int> pq;

int main(){
    scanf("%d%d",&n,&m);
    vt.resize(n+1);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        vt[a].push_back(b);
        ind[b]++;
    }
    for(int i=1;i<=n;i++){
        if(!ind[i])
            pq.push(-i);
    }
    while(!pq.empty()){
        int here=-pq.top();
        pq.pop();
        printf("%d ",here);
        for(int i=0;i<vt[here].size();i++){
            int there=vt[here][i];
            ind[there]--;
            if(!ind[there])
                pq.push(-there);
        }
    }
    return 0;
}
