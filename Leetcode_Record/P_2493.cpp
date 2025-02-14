#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int start,vector<vector<int>> &edge, vector<int> &rec,vector<int> &group){
        group.push_back(start);
        rec[start] = 1;
        for(auto to:edge[start]){
            if(rec[to]==0){
                dfs(to,edge,rec,group);        
            }
        }
    }
    int bfs(int start,vector<vector<int>> &edge, vector<int> &dist){
        queue<int> que;
        dist[start]=1;
        que.push(start);
        int out = 1;
        while(que.size()){
            int cur = que.front();
            que.pop();
            for(auto to:edge[cur]){
                if(dist[to]==0){
                    dist[to] = dist[cur]+1;
                    out = dist[to];
                    que.push(to);
                }else if(abs(dist[to]-dist[cur])!=1){
                    return -1;
                }
            }
        }
        return out;
    }

    int run(int start,vector<vector<int>> &edge,vector<int> &rec){
        vector<int> group;
        dfs(start,edge,rec,group);
        int out = -1;
        vector<int> dist(rec.size(),0);
        for(auto g:group){
            dist[g] = 1;
            int tmp =bfs(g,edge,dist);
            if(tmp==-1)return -1;
            out = max(out,tmp);
            for(auto r:group){
                dist[r] = 0;
            }
        }
        return out;
    }


    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> rec(n+1,0);
        int ans = 0;
        vector<vector<int>> edge(n+1,vector<int>());
        for(auto &e:edges){
            edge[e[0]].push_back(e[1]);
            edge[e[1]].push_back(e[0]);
        }
        for(int i=1;i<=n;i++){
            if(rec[i]==0){
                int tmp = run(i,edge,rec);
                if(tmp<=0)return -1;
                ans+=tmp;
            }
        }       
        return ans;     
    }
};