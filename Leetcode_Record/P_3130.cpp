#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<long long>> dp0(zero+1,vector<long long>(one+1,0)),dp1(zero+1,vector<long long>(one+1,0));
        int mod = 1e9+7;
        limit++;
        for(int i=0;i<=zero&&i<limit;i++){
            dp0[i][0]=1;
        }
        for(int i=0;i<=one&&i<limit;i++){
            dp1[0][i] = 1;
        }
        for(int i=1;i<=zero;i++){
            for(int j=1;j<=one;j++){
                dp0[i][j] = dp0[i-1][j]+dp1[i-1][j];
                if(i-limit>=0)dp0[i][j]-=dp1[i-limit][j];
                dp1[i][j] += dp1[i][j-1]+dp0[i][j-1];
                if(j-limit>=0)dp1[i][j]-=dp0[i][j-limit];
                dp0[i][j] %= mod;dp1[i][j] %= mod;
            }
        }
        long long ans = (dp0[zero][one]+dp1[zero][one])%mod;
        if(ans<0)ans+=mod;
        return ans;
    }
};