#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rec;
    
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        int n = nums.size(),m = target.size();
        rec.resize(m,vector<int>());
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rec[j].push_back(
                    (target[j]-(nums[i]%target[j]))%target[j]
                    );
            }
        }
        vector<int> dp(1<<m,2e9);
        dp[0] = 0;
        for(int i=0;i<n;i++){
            map<int,int> check;
            for(int j=0;j<m;j++){
                check[rec[j][i]]|=(1<<j);
            }
            for(int j=0;j<m;j++){
                for(auto &c:check){
                    if((c.first+nums[i])%target[j]==0){
                        c.second |=(1<<j);
                        // cout<<i<<" "<<nums[i]<<" "<<c.first<<" "<<target[j]<<endl;
                    }
                }
            }
            vector<int> dp_tmp = dp;
            for(int k=0;k<dp.size();k++){
                for(auto &c:check){
                    if((k|c.second)!=k){
                        dp_tmp[k|c.second] =min(dp_tmp[k|c.second],dp[k]+c.first);
                    }
                }
            }
            // for(int k=0;k<dp.size();k++)cout<<dp[k]<<" ";cout<<endl;
            dp = dp_tmp;
            // for(int k=0;k<dp.size();k++)cout<<dp[k]<<" ";cout<<endl;
        }
    
        return dp.back();
    }
};