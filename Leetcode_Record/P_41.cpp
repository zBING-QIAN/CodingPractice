#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> dp(nums.size()+1,false);
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=nums.size())dp[nums[i]]=true;
        }
        for(int i=1;i<dp.size();i++)if(!dp[i])return i;
        return nums.size()+1;
    }
};