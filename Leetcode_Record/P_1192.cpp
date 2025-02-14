#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> edge;
    vector<int> state,from;
    vector<vector<int>> ans;
    vector<int> stac;
    void dfs(int cur,int  s){
        for(auto &nxt:edge[cur]){
            if(state[nxt]==-1){
                state[nxt]= ++s;
                from[nxt] = cur;
                dfs(nxt,s);
            }
        }
        stac.push_back(cur);
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        state.resize(n,-1);from.resize(n,0);
        edge.resize(n,vector<int>());
        for(auto &e : connections){
            edge[e[0]].push_back(e[1]);
            edge[e[1]].push_back(e[0]);
        }
        state[0] = 0;
        dfs(0,0);
        for(int i=0;i<n;i++){
            int small = state[stac[i]];
            for(auto &nxt:edge[stac[i]]){
                if(nxt== from[stac[i]])continue;
                if(state[nxt]<=state[stac[i]]){
                    small = min(small,state[nxt]);
                }else {
                    ans.push_back({stac[i],nxt});
                }
            }
            state[stac[i]]=small;
            // cout<<state[stac[i]]<<" "<<stac[i]<<endl;
        }
        return ans;
    }
};