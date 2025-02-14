#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>edge;
    set<array<int,2>>  guess;vector<int> pre;
    int ss,ans,K;
    void dfs(int cur){
        for(auto &to:edge[cur]){
            if(pre[cur]!=to){
                if(guess.find({cur,to})!=guess.end())ss++;
                pre[to] = cur;
                dfs(to);        
            }
        }
    }
    void dfs_2(int cur){
        // cout<<cur<<" "<<ss<<endl;
        if(ss>=K)ans++;
        for(auto &to:edge[cur]){
            if(pre[cur]!=to){
                int pres = ss;
                if(guess.find({cur,to})!=guess.end())ss--;
                if(guess.find({to,cur})!=guess.end())ss++;
                // cout<<ss<<endl;
                dfs_2(to);        
                ss = pres;
            }
        }
    }
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        K=k;
        ss = 0;ans =0;int n = edges.size()+1;
        pre.resize(n,-1);
        edge.resize(n,vector<int>());
        for(auto &e:edges){
            edge[e[1]].push_back(e[0]);
            edge[e[0]].push_back(e[1]);
        }
        for(auto &g:guesses)guess.insert({g[0],g[1]});
        dfs(0);
        dfs_2(0);
        return ans;
    }
};