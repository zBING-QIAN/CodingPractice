#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9+7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        long long ans = 0;
        vector<vector<long long>> dp(grid[0].size(),vector<long long>(k,0));
        dp[0][grid[0][0]%k]=1;
        for(int i=1;i<grid[0].size();i++){
            for(int t=0;t<k;t++){
                int to = (t+grid[0][i])%k;  
                if(i>0)dp[i][to] += dp[i-1][t];
            }
        }
        for(int i=1;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                vector<long long> buf = dp[j];
                for(int t=0;t<k;t++){
                    int to = (t+grid[i][j])%k;  
                    dp[j][to] = buf[t];           
                    if(j>0)dp[j][to] += dp[j-1][t];
                    dp[j][to] %= mod;
                }
            }
        }
        return dp.back()[0];
    }
};