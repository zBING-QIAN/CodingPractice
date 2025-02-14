#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        vector<int> stac;
        map<int,int> cnt;
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            while(stac.size()&&stac.back()<nums[i]){
                cnt[stac.back()]=0;
                stac.pop_back();
            }
            cnt[nums[i]]++;
            if(stac.size()==0||stac.back()!=nums[i])stac.push_back(nums[i]);
            ans+=cnt[nums[i]];
        }
        return ans;
    }
};