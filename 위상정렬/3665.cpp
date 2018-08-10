#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAXX_N 500

vector<vector<int>> vt;
priority_queue<int> pq;
int t_case,n,m,flag,ind[MAXX_N+1],visited[MAXX_N+1],finished[MAXX_N+1];
vector<int> tmp,ans;

void cycle_check(int here){
    visited[here]=1;
    for(int i=0;i<vt[here].size();i++){
        int there=vt[here][i];
        if(!there)
            continue;
        if(visited[there]&&(!finished[there])){
            flag=1;
            break;
        }
        else if(!visited[there]){
            cycle_check(there);
        }
    }
    finished[here]=1;
}

int main(){
    scanf("%d",&t_case);
    while(t_case--){
        memset(ind,0,sizeof(ind));
        memset(visited,0,sizeof(visited));
        memset(finished,0,sizeof(finished));
        scanf("%d",&n);
        tmp.clear();
        ans.clear();
        vt.clear();
        vt.resize(n+1);
        flag=0;
        for(int i=0;i<n;i++){
            int num;
            scanf("%d",&num);
            tmp.push_back(num);
        }
        for(int i=0;i<tmp.size();i++){
            for(int j=i+1;j<tmp.size();j++){
                int from=tmp[i];
                int to=tmp[j];
                vt[from].push_back(to);
                ind[to]++;
            }
        }
        scanf("%d",&m);
        while(m--){
            int info1,info2;
            int check=0;
            scanf("%d%d",&info1,&info2);
            for(int i=0;i<vt[info1].size();i++){
                if(vt[info1][i]==info2){
                    vt[info1][i]=0;
                    vt[info2].push_back(info1);
                    ind[info2]--;
                    ind[info1]++;
                    check=1;
                }
            }
            if(check) continue;
            
            for(int i=0;i<vt[info2].size();i++){
                if(vt[info2][i]==info1){
                    vt[info2][i]=0;
                    vt[info1].push_back(info2);
                    ind[info1]--;
                    ind[info2]++;
                }
            }
        }
        int stpoint=0;
        for(int i=1;i<=n;i++){
            if(!ind[i]){
                pq.push(-i);
                stpoint=i;
            }
        }
        cycle_check(stpoint);
        if(flag||pq.empty()){
            puts("IMPOSSIBLE");
            while(!pq.empty())
                pq.pop();
            continue;
        }
        int ok=1;
        while(!pq.empty()){
            if(pq.size()>1)
                ok=0;
            int here=-pq.top();
            pq.pop();
            ans.push_back(here);
            for(int i=0;i<vt[here].size();i++){
                int there=vt[here][i];
                if(!there)
                    continue;
                ind[there]--;
                if(!ind[there])
                    pq.push(-there);
            }
        }
        if(!ok){
            puts("?");
            continue;
        }
        for(int i=0;i<ans.size();i++)
            printf("%d ",ans[i]);
        puts("");
    }
}
