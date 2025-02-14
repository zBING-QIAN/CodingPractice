#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubstrings(string s) {
        vector<vector<int>> dp(10,vector<int>(10,0));
        long long ans = 0;
        for(int i=0;i<s.size();i++){
            int tmp = s[i]-'0';
            vector<vector<int>> dpt(10,vector<int>(10,0));
            for(int j=1;j<10;j++){
                dpt[j][tmp%j]=1;
                for(int k=0;k<j;k++){
                    int r = (k*10+tmp)%j;
                    dpt[j][r]+=dp[j][k];
                }
            }
            dp = dpt;
            if(tmp)ans += dp[tmp][0];
        }
        return ans;
    }
};