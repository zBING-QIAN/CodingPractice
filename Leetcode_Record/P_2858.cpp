#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> edge,cnt_to;
    vector<vector<bool>> exist;
    vector<int> rec,from;
    int dfs(int cur){
        int sum=0;
        for(int i=0;i<edge[cur].size();i++){
            int to = edge[cur][i];
            if(from[cur]==to)continue;
            from[to] = cur;
            cnt_to[cur][i] = dfs(to)+(1-exist[cur][i]);
            sum+=cnt_to[cur][i];
        }
        rec[cur] = sum;
        return sum;
    } 
    void dfs2(int cur,int cnt){
        rec[cur]+=cnt;
        int sum = rec[cur];
        for(int i=0;i<edge[cur].size();i++){
            int to = edge[cur][i];
            if(from[cur]==to)continue;
            sum-=cnt_to[cur][i];
            dfs2(to,sum+exist[cur][i]);
            sum+=cnt_to[cur][i];
        }

    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        cnt_to.resize(n,vector<int>());
        exist.resize(n,vector<bool>());
        edge.resize(n,vector<int>());
        rec.resize(n,0);
        from.resize(n,-1);
        for(auto &e:edges){
            edge[e[0]].push_back(e[1]);
            edge[e[1]].push_back(e[0]);
            exist[e[0]].push_back(1);
            exist[e[1]].push_back(0);
        }
        for(int i=0;i<n;i++){
            cnt_to[i].resize(edge[i].size(),0);
        }
        dfs(0);
        dfs2(0,0);
        return rec;
    }
};