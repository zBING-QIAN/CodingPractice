#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        vector<int> coin_leaf;
        adj.resize(coins.size(),vector<int>());
        for(auto &e:edges){adj[e[0]].push_back(e[1]);adj[e[1]].push_back(e[0]);}
        
        vector<int> leaf,dep(coins.size(),0),rec(coins.size(),0),score(coins.size(),0);
        
        for(int i=0;i<adj.size();i++){
            if(adj[i].size()==1){
                if(coins[i])coin_leaf.push_back(i);
                else leaf.push_back(i);
            }
        }
        int flag = 0;
        //reduce map
        while(flag<leaf.size()){
            int cur = leaf[flag];
            for(auto &to:adj[cur]){
                rec[to]++;
                if(adj[to].size()-rec[to]==1){
                    if(coins[to]){coin_leaf.push_back(to);}
                    else leaf.push_back(to);
                }
            }
            flag++;
        }
        flag=0;
        int ans=0;
        while(flag<coin_leaf.size()){
            int cur = coin_leaf[flag];
            for(auto &to:adj[cur]){
                rec[to]++;
                dep[to] = max(dep[to],dep[cur]+1);
                score[to] += (dep[cur]>1)?score[cur]+2:0;
                if(adj[to].size() - rec[to]==1){
                     coin_leaf.push_back(to);
                }
            }
            flag++;
        }
        // for(int i=0;i<rec.size();i++){
        //     cout<<rec[i]<<" ";
        // }cout<<endl;
        // for(int i=0;i<rec.size();i++){
        //     cout<<adj[i].size()<<" ";
        // }cout<<endl;
        // cout<<coin_leaf.size()+leaf.size()<<" "<<coins.size()<<endl;
        if(coin_leaf.size()==0)return 0;
        return score[coin_leaf.back()];
        // int root = coin_leaf.back();
        // return dfs(root);
    }
};