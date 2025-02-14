#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        for(int i=0;i<time.size();i++){
            time[i]++;
        }
        vector<long long> dp(time.size()+1,6*1e8);dp[0]=0;
        for(int i=0;i<time.size();i++){
            for(int t=time.size();t;t--){
                if(t-time[i]>=0)dp[t] = min(dp[t-time[i]]+cost[i],dp[t]);
                else dp[t] = min(dp[0]+cost[i],dp[t]);
            }
        }
        return dp[time.size()];
    }
};