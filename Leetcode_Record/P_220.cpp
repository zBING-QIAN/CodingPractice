#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        map<int,int> rec;
        for(int i=0;i<nums.size();i++){
            auto lb = rec.lower_bound(nums[i]);
            if(lb!=rec.end()&&abs(lb->first-nums[i])<=valueDiff){
                return 1;
            }
            if(lb!=rec.begin()){
                lb = prev(lb);
                if(lb!=rec.end()&&abs(lb->first-nums[i])<=valueDiff){
                    return 1;
                }
            }
            rec[nums[i]]=i;
            if(i>=indexDiff){
                if(rec[nums[i-indexDiff]]==i-indexDiff)rec.erase(nums[i-indexDiff]);
            }
            
        }
        return 0;
    }
};