#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int ans = 0;
        vector<vector<bool>> dpl(k+1,vector<bool>(128,0)),dpr(k+1,vector<bool>(128,0));dpl[0][0]=1;dpr[0][0]=1;
        vector<vector<bool>> l(nums.size(),vector<bool>(128,0)),r(nums.size(),vector<bool>(128,0));
        for(int i=0;i<nums.size();i++){
            for(int j=min(i+1,k);j>0;j--){
                for(int t=0;t<128;t++){
                    if(dpl[j-1][t])dpl[j][t|nums[i]] = 1;
                }
            }
            l[i]=dpl[k];
            for(int j=min(i+1,k);j>0;j--){
                for(int t=0;t<128;t++){
                    if(dpr[j-1][t])dpr[j][t|nums[nums.size()-1-i]] = 1;
                }
            }
            r[nums.size()-1-i]=dpr[k];
        }
        for(int i=0;i<nums.size()-1;i++){
            for(int j=0;j<128;j++){
                if(l[i][j])
                for(int t=0;t<128;t++){
                    if(r[i+1][t])ans=max(ans,j^t);
                }    
            }
        }
        return ans;
    }
};