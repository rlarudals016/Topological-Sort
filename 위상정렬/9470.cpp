#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define MAXX_N 1000

int t,t_num,n,m,ind[MAXX_N+1],river_num[MAXX_N+1],check[MAXX_N+1];
vector<vector<int>> vt;
priority_queue<int> pq;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&t_num,&n,&m);
        memset(ind,0,sizeof(ind));
        memset(river_num,0,sizeof(river_num));
        vt.clear();
        vt.resize(n+1);
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            vt[a].push_back(b);
            ind[b]++;
        }
        for(int i=1;i<=n;i++){
            if(!ind[i]){
                pq.push(-i);
                river_num[i]=1;
            }
        }
        int ans=0;
        while(!pq.empty()){
            int here=-pq.top();
            pq.pop();
            if(check[here])
                river_num[here]++;
            ans=max(ans,river_num[here]);
            for(int i=0;i<vt[here].size();i++){
                int there=vt[here][i];
                if(river_num[there]<river_num[here]){
                    river_num[there]=river_num[here];
                    check[there]=0;
                }
                else if(river_num[there]==river_num[here]){
                    check[there]=1;
                }
                ind[there]--;
                if(!ind[there])
                    pq.push(-there);
            }
        }
        printf("%d %d\n",t_num,ans);
    }
}
