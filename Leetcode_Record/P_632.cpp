#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int small= 1e9,left=0,right=0;
        set<array<int,3>> rec;
        for(int i=0;i<nums.size();i++){
            rec.insert({nums[i][0],i,0});
        }
        left = (*rec.begin())[0],right = (*rec.rbegin())[0];
        small = right-left;
        int k = nums.size(),len = nums[0].size();
        while(true){
            auto [a,b,c] = (*rec.begin());
            if(c>=nums[b].size()-1)break;
            rec.erase(rec.begin());
            rec.insert({nums[b][c+1],b,c+1});
            int tmp =(*rec.rbegin())[0] - (*rec.begin())[0];
            if(tmp<small){
                small=tmp;
                left = (*rec.begin())[0];right=(*rec.rbegin())[0];
            }

        }
        return {left,right};
    }
};