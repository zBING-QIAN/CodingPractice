#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> l(n-1),r(n-1),idxl(n-1),idxr(n-1);
        for(int i=0;i<nums.size()-1;i++){
            l[i] = min(nums[i],nums[i+1]);
            r[i] = max(nums[i],nums[i+1]);
        } 
        for(int i=0;i<n-1;i++){
            idxl[i] = i;idxr[i]=i;
        }
        // cout<<"after init\n";
        sort(idxr.begin(),idxr.end(),[&](auto &a, auto &b){
            return r[a]<r[b];
        });
        sort(idxl.begin(),idxl.end(),[&](auto &a, auto &b){
            return l[a]<l[b];
        });
        // cout<<"after sort\n";
        int tmp = l[idxl[n-2]]-r[idxr[0]];
        int ltmp = 0;
        for(int i=1;i<n-1;i++){
            int t0 = abs(nums[0]-nums[i+1]),t1 = abs(nums[i]-nums[i+1]);
            if(t0>t1&&ltmp<t0-t1)ltmp = t0-t1;
        }
        int rtmp = 0;
        for(int i=1;i<n-1;i++){
            int t0 = abs(nums[i-1]-nums[n-1]),t1 = abs(nums[i-1]-nums[i]);
            if(t0>t1&&rtmp<t0-t1)rtmp = t0-t1;
        }
        // cout<<"after change\n";
        tmp=max(tmp*2,max(rtmp,ltmp));
        int ans=tmp;
        for(int i=0;i<nums.size()-1;i++){
            ans+= abs(nums[i]-nums[i+1]);
        }
        
        return ans;
    }
};