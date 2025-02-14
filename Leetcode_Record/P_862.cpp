#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int ans=nums.size()+1,sum = 0;
        vector<int> pos;
        for(int i=0,prev = 0;i<nums.size();i++){
            if(nums[i]>0){pos.push_back(i);}
            else {
                int tmp = nums[i];
                while(pos.size()>prev){
                    if(nums[pos.back()]+tmp<=0){tmp+=nums[pos.back()];nums[pos.back()]=0;pos.pop_back();}
                    else {nums[pos.back()]+=tmp;break;}
                }
                if(pos.size()<prev){pos.clear();sum=0;prev=0;}
            }
            sum += nums[i];
            // cout<<sum<<" "<<nums[i]<<" "<<i<<" "<<prev<<endl;
            // for(auto p:pos)cout<<nums[p]<<" ";cout<<endl;
            while(prev<pos.size()&&sum-nums[pos[prev]]>=k){
                sum-=nums[pos[prev]];prev++;
            }
            if(sum>=k)ans = min(i-pos[prev]+1,ans);
            sum = max(sum,0);
        }
        if(ans>nums.size())return -1;
        return ans;
    }
};