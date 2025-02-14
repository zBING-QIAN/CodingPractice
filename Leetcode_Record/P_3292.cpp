#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int minValidStrings(vector<string>& words, string target) {
        vector<vector<int>> dp(words.size(),vector<int>()),
            run_dp(words.size(),vector<int>(target.size(),-1));
        for(int m=0;m<words.size();m++){
            auto w = words[m];
            dp[m].resize(w.size(),-1);
            for(int i=1;i<w.size();i++){
                int p = dp[m][i-1];
                while(p>=0&&w[p+1]!=w[i]){
                    p=dp[m][p];
                }
                if(w[p+1]==w[i])dp[m][i] = p+1;
                
            }
            // for(int i=0;i<dp[m].size();i++)cout<<dp[m][i]<<" ";cout<<endl;
        }
        for(int m=0;m<words.size();m++){
            auto w=words[m];
            for(int i=0,cur=-1;i<target.size();i++){
                while(cur>=0&&target[i]!=w[cur+1]){cur=dp[m][cur];}
                if(target[i]==w[cur+1])run_dp[m][i] = ++cur;            
                if(cur==w.size()-1)cur=dp[m][cur];
            }
        }
        vector<int>ans(target.size()+1,target.size()+1);ans.back()=0;
        for(int i=target.size()-1;i>=0;i--){
            for(int m=0;m<words.size();m++){
                if(run_dp[m][i]>=0){
                    ans[i-run_dp[m][i]]=min(ans[i-run_dp[m][i]],1+ans[i+1]);
                }   
            }
        }
        // for(int i=0;i<target.size();i++)cout<<ans[i]<<" ";cout<<endl;
        // for(int m=0;m<words.size();m++){for(int i=0;i<target.size();i++)cout<<run_dp[m][i]<<" ";cout<<endl;}
        if(ans[0]==target.size()+1)return -1;
        return ans[0];
    }
};