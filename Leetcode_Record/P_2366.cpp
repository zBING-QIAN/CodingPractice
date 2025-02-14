#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]<nums[i-1]){
                long long tmp = nums[i-1]/nums[i];
                if(nums[i-1]-nums[i]*tmp>0){
                    tmp++;
                }
                nums[i-1]= nums[i-1]/tmp;ans += tmp-1;
            }
        }
        return ans;
    }
};