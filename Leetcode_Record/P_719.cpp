#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,r=2e6;
        while(l<r){
            int mid = (l+r)>>1;
            int cnt =0;
            for(int i=0,j=1;i<nums.size();i++){
                while(j<nums.size()&&nums[j]-nums[i]<=mid)j++;
                cnt+=j-i-1;
            }
            if(cnt<k)l = mid+1;
            else r = mid;
        }
        return l;
    }
};