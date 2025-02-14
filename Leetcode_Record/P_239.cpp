#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int ans =0,pos=0;
        map<int,int> rec;
        vector<int> out;
        for(int i=0;i<k;i++){rec[nums[i]]++;}
        out.push_back(rec.rbegin()->first);
        for(int i=0,tmp=ans;i+k<nums.size();i++){
            rec[nums[i+k]]++;
            if(--rec[nums[i]] == 0)rec.erase(nums[i]);
            out.push_back((*rec.rbegin()).first);
        }
        return out;
    }
};