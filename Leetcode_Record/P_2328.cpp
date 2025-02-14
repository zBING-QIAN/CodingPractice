#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        vector<pair<int,int>> idx;
        vector<vector<int>> idx_pos = grid;
        int h = grid.size(),w=grid[0].size();
        int mod = 1e9+7;
        for(int i=0;i<h;i++){for(int j=0;j<w;j++)idx.push_back({i,j});}
        sort(idx.begin(),idx.end(),[&](auto &a,auto &b){
            return grid[a.first][a.second]<grid[b.first][b.second];
        });
        vector<long long>dp(idx.size(),1);
        for(int i=0;i<idx.size();i++){
            int y=idx[i].first,x = idx[i].second;
            idx_pos[y][x] = i;
        }
        for(int i=0;i<idx.size();i++){
            int y=idx[i].first,x = idx[i].second;
            if(y>0&&grid[y-1][x]<grid[y][x]){
                dp[i]+=dp[idx_pos[y-1][x]];
            }
            if(x>0&&grid[y][x-1]<grid[y][x]){
                dp[i]+=dp[idx_pos[y][x-1]];
            }
            if(y<h-1&&grid[y+1][x]<grid[y][x]){
                dp[i]+=dp[idx_pos[y+1][x]];
            }
            if(x<w-1&&grid[y][x+1]<grid[y][x]){
                dp[i]+=dp[idx_pos[y][x+1]];
            }
            dp[i] = dp[i]%mod;
        }
        long long ans= 0;
        for(int i=0;i<dp.size();i++){
            ans = (ans+dp[i])%mod;
        }
        return ans;
    }
};