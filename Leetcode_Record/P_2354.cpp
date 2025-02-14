#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[n])nums[++n] =nums[i]; 
        }n++;
        nums.resize(n);
        vector<int> bs(n,0);
        for(int i=0;i<n;i++){
            int tmp = nums[i];
            while(tmp){
                bs[i]+=(tmp&1);tmp>>=1;
            }
        }
        long long ans=0;
        sort(bs.begin(),bs.end());
        for(int i=0,j=n-1;j>=i;j--){
            while(i<=j&&bs[j]+bs[i]<k){
                i++;
            }
            if(i<=j)ans = ans+(j-i+1)+(j-i);
        }
        return ans;
    }
};