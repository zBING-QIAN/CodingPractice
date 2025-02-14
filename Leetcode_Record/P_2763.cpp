#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int ans =0,n = nums.size();
        vector<int> pre(n,0),nxt(n,0);
        map<int,int> rec;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            int ppos = -1,npos=-1,cpos = -1;
            if(rec.find(nums[i]-1)!=rec.end())ppos=rec[nums[i]-1];
            if(rec.find(nums[i]+1)!=rec.end())npos=rec[nums[i]+1];
            if(rec.find(nums[i])!=rec.end())cpos=rec[nums[i]];
            int near = max(ppos,max(npos,cpos));
            sum+=max(i-near-1,0);
            int mpos = min(npos,ppos);
            if(mpos>cpos){sum-=mpos-cpos;}
            
            ans += sum;
            rec[nums[i]] = i;
        }
        return ans;
    }
};