#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(250,vector<int>(105,0));dp[0][0]=1;
        int ans=0;
        int mod= 1e9+7;
        int m = group.size();
        for(int i=0;i<m;i++){
            for(int p=minProfit+profit[i];p>=profit[i];p--){
                for(int t = n;t>=group[i];t--){
                    int h = (p>=minProfit)?minProfit:p;
                    dp[h][t] = (dp[h][t] + dp[p-profit[i]][t-group[i]])%mod;
                    
                }
            }
        }
        
            for(int t = 0;t<=n;t++){
                ans=(ans+dp[minProfit][t])%mod;
            }
        
        return ans;
    }
};