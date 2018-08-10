#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
#define MAXX_N 30

int n,ind[MAXX_N+1],visited[MAXX_N+1],finished[MAXX_N+1],check[MAXX_N+1],f;
vector<vector<int>> vt;
priority_queue<int> pq;
vector<int> ans;
string str[101];

void cycle_check(int here){
    visited[here]=1;
    for(int i=0;i<vt[here].size();i++){
        int there=vt[here][i];
        if(visited[there]&&(!finished[there]))
            f=1;
        else if(!visited[there])
            cycle_check(there);
    }
    finished[here]=1;
}

int main(){
    scanf("%d",&n);
    vt.resize(30);
    
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<str[i].size();j++){
            int tmp=str[i][j]-'a';
            check[tmp]=1;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=0;k<11;k++){
                int from=str[i][k]-'a';
                int to=str[j][k]-'a';
                if(str[i][k]==str[j][k]) continue;
                else if(!(str[i][k]==0||str[j][k]==0)){
                    vt[from].push_back(to);
                    ind[to]++;
                    break;
                }
            }
        }
    }
    
    
    for(int i=0;i<30;i++){
        if(!ind[i]&&check[i]){
            pq.push(-i);
        }
    }
    for(int i=0;i<30;i++){
        if(!visited[i])
            cycle_check(i);
    }
    if(f||pq.empty()){
        puts("!");
        return 0;
    }
    
    int flag=0;
    while(!pq.empty()){
        if(pq.size()>1)
            flag=1;
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
    if(flag)
        puts("?");
    else{
        for(int i=0;i<ans.size();i++){
            cout<<char(ans[i]+'a');
        }
    }
}
