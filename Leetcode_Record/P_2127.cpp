#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    set<pair<int,int>> epoints;
    vector<int> longest_circle,longest_path,longest_out;
    vector<int> state;
    void dfs(int cur,vector<int> &edge){
        int to = edge[cur];
        if(state[to]==-1) {
            state[to]=state[cur]+1;
            dfs(to,edge);
            
        }else if(state[to]>=0){
            longest_circle[cur] = state[cur]-state[to]+1;
        }
        state[cur] = -2;
    }
    void dfs2(int cur,vector<int> &edge,int dep=1){
        int to = edge[cur];
        if(to ==-1)return;
        else if(state[to]==-1){
            state[to] = -2;
            dfs2(to,edge,dep+1);
        }
        state[cur] = state[to];
        if(state[cur]>=0){
            longest_path[cur] = longest_path[to]+1;
            // cout<<cur<<" "<<to<<" "<<state[cur]<<" "<<longest_path[to]<<" "<<dep<<endl;
            longest_out[state[cur]] = max(longest_out[state[cur]], longest_path[to]+dep);
        }
    }
    int maximumInvitations(vector<int>& favorite) {
        int ans =0,n = favorite.size();
        longest_circle.resize(n,0);
        longest_path.resize(n,0);
        longest_out.resize(n,0);
        state.resize(n,-1);
        for(int i=0;i<n;i++){
            if(state[i]==-1){state[i] = 0;dfs(i,favorite);}
            // cout<<longest_circle[i]<<endl;
            ans = max(longest_circle[i],ans);
        }
        state.clear();state.resize(n,-1);
        for(int i=0;i<n;i++){
            if(favorite[i]!=-1&&favorite[favorite[i]]==i){
                epoints.insert({i,favorite[i]});
                state[i]=i;state[favorite[i]]=favorite[i];
                longest_path[i]=  1;
                longest_path[favorite[i]] = 1;
                longest_out[i]=1;
                longest_out[favorite[i]] = 1;
                favorite[favorite[i]]=-1;
                favorite[i] = -1;
            }
        }

        for(int i=0;i<n;i++){
            if(state[i]==-1){state[i]=-2;dfs2(i,favorite);}
        }
        int ans2 =0;
        for(auto &p:epoints){
            ans2 += longest_out[p.first]+longest_out[p.second];
        }
        return max(ans2,ans);
    }
};