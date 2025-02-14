#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<long long> dp(s.size()+1,0),dp_tmp(s.size()+1,0),dp_cnt(s.size()+1,0);
        dp[0] = s[0]==t[0];
        for(int i=1;i<s.size();i++){
            dp[i] =dp[i-1]+(s[i]==t[0]);
        }
        dp_tmp = dp;
        for(int i=1;i<t.size();i++){
            
            for(int j=0;j<s.size();j++){
                if(j<i){dp[j]=0;continue;}
                dp[j] = dp[j-1];
                if(s[j] == t[i]&&dp[j]+dp_tmp[j-1] <INT_MAX){
                    dp[j] += dp_tmp[j-1];
                }
            }
            dp_tmp = dp;
        }
        return dp[s.size()-1];
    }
};