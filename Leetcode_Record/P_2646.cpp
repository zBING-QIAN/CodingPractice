#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> edge[51];
    vector<int> node_cnt;
    vector<int> ans0,ans1;
    vector<int> cost;
    vector<bool> visited;
    void bfs(int start,int end){
        for(int i=0;i<visited.size();i++)visited[i]=0;
        vector<int> q,p;q.push_back(start);p.push_back(-1);
        int flag = 0;
        while(flag<q.size()){
            int cur = q[flag];
            if(cur==end){
                node_cnt[cur]++;cur = p[flag];
                while(cur>=0){                
                    node_cnt[q[cur]]++; 
                    cur = p[cur];
                }
                return;
            }
            for(auto &e:edge[cur]){
                if(!visited[e]){
                    visited[e]=1;
                    p.push_back(flag);
                    q.push_back(e);
                }
            }
            flag++;
        }
    }
    void dfs(int cur){
        int sum0=0,sum1=0;
        for(auto nxt:edge[cur]){
            if(visited[nxt]==0){
                visited[nxt] = 1;
                dfs(nxt);
                sum0+=max(ans0[nxt],ans1[nxt]);
                sum1+=ans0[nxt];
            }
        }
        ans0[cur] = sum0;
        ans1[cur] = sum1+cost[cur];
    }
    
    
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        for(auto &e:edges){
            edge[e[0]].push_back(e[1]);
            edge[e[1]].push_back(e[0]);
        }
        visited.resize(n,0);
        cost.resize(n,0);
        node_cnt.resize(n,0);
        ans0.resize(n,0);ans1.resize(n,0);
        for(auto &t:trips){
            bfs(t[0],t[1]);
        }
        int total_cost = 0;
        for(int i=0;i<cost.size();i++){
            cost[i] = price[i]*node_cnt[i];
            total_cost += cost[i];
        }
        for(int i=0;i<n;i++)visited[i]=0;
        visited[0]=1;
        dfs(0);
        int half = max(ans0[0],ans1[0])>>1;
        // cout<<total_cost<<" "<<half<<endl;
        return total_cost-half;
    }
};