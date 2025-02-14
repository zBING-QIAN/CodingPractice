#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> dp1(nums.size(),0),dp2(nums.size(),0),dp3(nums.size(),0),ksum(nums.size()+1,0);
        vector<int> dp1sum(nums.size(),0),dp2sum(nums.size(),0),dp3sum(nums.size(),0);

        
        for(int i=1;i<ksum.size();i++){ksum[i]=ksum[i-1]+nums[i-1];}
        for(int i=0;i+k<ksum.size();i++){
            ksum[i] = ksum[i+k]-ksum[i];
        }
        ksum.resize(nums.size()-k+1);
        dp1[0] = 0;dp1sum[0] = ksum[0];
        for(int i=1;i<ksum.size();i++){
            if(dp1sum[i-1]>=ksum[i]){
                dp1[i]=dp1[i-1];
                dp1sum[i] = dp1sum[i-1];
            }else{
                dp1[i] = i;
                dp1sum[i] = ksum[i];
            }
        }
        dp2[k] = k;dp2sum[k] = dp1sum[0]+ksum[k];
        for(int i=k+1;i<ksum.size();i++){
            if(dp2sum[i-1]>=ksum[i]+dp1sum[i-k]){
                dp2[i] = dp2[i-1];    
                dp2sum[i] = dp2sum[i-1];
            }else{
                dp2[i] = i;    
                dp2sum[i] = dp1sum[i-k]+ksum[i];
            }
            
            // cout<<"dp2 "<<dp2[i]<<" "<<dp2sum[i]<<endl;
        }
        dp3[2*k] = 2*k;dp3sum[2*k] = dp2sum[k]+ksum[2*k];
        for(int i=2*k+1;i<ksum.size();i++){
            if(dp3sum[i-1]>=ksum[i]+dp2sum[i-k]){
                dp3[i] = dp3[i-1];    
                dp3sum[i] = dp3sum[i-1];
            }else{
                dp3[i] = i;    
                dp3sum[i] = ksum[i]+dp2sum[i-k];
            }
            
            // cout<<"dp3 "<<dp3[i]<<" "<<dp3sum[i]<<endl;
        }
        int idx3 = dp3[ksum.size()-1];
        return {dp1[dp2[idx3-k]-k],dp2[idx3-k],idx3};
        
    }
};