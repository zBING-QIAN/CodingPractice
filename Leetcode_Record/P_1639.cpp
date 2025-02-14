#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        vector<long long> dp(1002,0);
        vector<vector<int>> alpha(words[0].size(),vector<int>(26,0));

        int mod = 1e9+7;
        for(auto &w:words){
            for(int i=0;i<w.size();i++){
                alpha[i][w[i]-'a']++;
            }
        }
        dp[0] = 1;
        for(int i=0;i<words[0].size();i++){
        
            for(int j=target.size();j;j--){ 
                for(int a=0;a<26;a++){
                    if(target[j-1]==a+'a'){
                        dp[j]+=dp[j-1]*alpha[i][a];
                        dp[j] %=mod;
                    }
                }
            }
            
        }
        // for(int i=0;i<target.size()+1;i++)cout<<dp[i]<<" ";cout<<endl;
        return dp[target.size()];
    }
};