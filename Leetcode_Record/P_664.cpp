#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int strangePrinter(string s) {
        vector<vector<int>> dp(s.size(),vector(s.size(),0));
        for(int i=0;i<s.size();i++)dp[i][i]=1;
        for(int g=1;g<s.size();g++){
            for(int f = 0;f+g<s.size();f++){
                if(s[f]==s[f+1])dp[f][f+g] = dp[f+1][f+g];
                else if(s[f]==s[f+g])dp[f][f+g] = dp[f][f+g-1];
                else {
                    dp[f][f+g] = 1+dp[f+1][f+g];
                    for(int t = f+1;t<f+g;t++){
                        if(s[f]==s[t]){
                            dp[f][f+g] = min(dp[f][f+g],dp[f+1][t]+dp[t+1][f+g]);
                        }
                    }
                }
            }
        }

        return dp[0][s.size()-1];
    }
};