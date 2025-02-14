#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int global_xor=0;
    int ans = 1e9;
    vector<vector<int>>edge,rec;
    vector<int> from,xor_value;
    void dfs(int cur,vector<int> &nums){
        xor_value[cur] = nums[cur];
        for(int i=0;i<edge[cur].size();i++){
            int to = edge[cur][i];
            if(from[to]==-1){
                from[to]=cur;
                dfs(to,nums);
                xor_value[cur] ^= xor_value[to];
            }else {rec[cur][i]=1;}
        }
    }
    
    void run(int cur,int local_xor){
        for(int i=0;i<edge[cur].size();i++){
            int to = edge[cur][i];
            if(from[to]==-1){
                from[to] = -2;
                int xor0 = global_xor^local_xor;
                int xor1 = local_xor^rec[cur][i];
                if(xor0<xor1)swap(xor0,xor1);
                xor1 = min(xor1,rec[cur][i]);
                xor0 = max(xor0,rec[cur][i]);
                // cout<<cur<<" "<<to<<" "<<local_xor<<" "<<rec[cur][i]<<" "<<xor1<<" "<<xor0<<endl;
                ans = min(ans,xor0-xor1);
                run(to,local_xor);
            }
        }
    }
    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n= nums.size();
        from.resize(n,-1);xor_value.resize(n,0);
        edge.resize(n,vector<int>());rec.resize(n,vector<int>());   
        for(auto &e:edges){
            edge[e[0]].push_back(e[1]);edge[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++)rec[i].resize(edge[i].size(),0);
        from[0]=-2;
        dfs(0,nums);
        global_xor = xor_value[0];
        for(int i=0;i<n;i++){
            for(int j=0;j<rec[i].size();j++){
                if(rec[i][j]==0){rec[i][j] = xor_value[edge[i][j]];}
                else rec[i][j] = global_xor ^ xor_value[i];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<edge[i].size();j++){
                // cout<<"i j "<<i<<" "<<edge[i][j]<<endl;
                from.clear();from.resize(n,-1);from[edge[i][j]]=-2;from[i]=-2;
                run(edge[i][j],rec[i][j]);
                // cout<<endl;
                from.clear();from.resize(n,-1);from[edge[i][j]]=-2;from[i]=-2;
                run(i,global_xor^rec[i][j]);
            }
        }
        return ans;
    }
};