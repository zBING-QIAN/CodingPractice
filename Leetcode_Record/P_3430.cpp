#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long calc(int l,int i,int r,int v,int k){
        long long out = 0;
        out = (long long)(r-i)*(i-max(l,(r-k))+1);
        long long tmp = r-k-l;
        if(tmp>0){
            tmp*=(r-i-1+l+k-i);
            tmp/=2;
            // cout<<"tmp  "<<tmp<<endl;
            out+=tmp;
        }
        // cout<<l<<" "<<i<<" "<<r<<" "<<v<<" "<<k<<" "<<out<<endl;
        return out*v;
    }

    long long minMaxSubarraySum(vector<int>& nums, int k) {
        vector<int> stac;
        int n = nums.size();
        vector<int> max_range_l(n,0);
        long long ans=0;
        for(int i=0;i<n;i++){
            max_range_l[i] = i;
            while(stac.size()&&nums[stac.back()]<nums[i]){
                int r = min(i,stac.back()+k);
                // cout<<r<<" "<<max_range_l[stac.back()]<<" "<<nums[stac.back()]<<endl;
                ans+= calc(max_range_l[stac.back()],stac.back(),r,nums[stac.back()],k);
                stac.pop_back();
            }
            if(stac.size())max_range_l[i] = stac.back()+1;
            else max_range_l[i] = 0;
            max_range_l[i] = max(max_range_l[i],i-k+1);
            stac.push_back(i);
        }
        while(stac.size()){
            int r = min(n,stac.back()+k);
            // cout<<r<<" "<<max_range_l[stac.back()]<<" "<<nums[stac.back()]<<endl;
            ans+= calc(max_range_l[stac.back()],stac.back(),r,nums[stac.back()],k);
            stac.pop_back();
        }
        for(int i=0;i<n;i++){
            max_range_l[i] = i;
            while(stac.size()&&nums[stac.back()]>nums[i]){
                int r = min(i,stac.back()+k);
                // cout<<r<<" "<<max_range_l[stac.back()]<<" "<<nums[stac.back()]<<endl;
                ans+= calc(max_range_l[stac.back()],stac.back(),r,nums[stac.back()],k);
                stac.pop_back();
            }
            if(stac.size())max_range_l[i] = stac.back()+1;
            else max_range_l[i] = 0;
            max_range_l[i] = max(max_range_l[i],i-k+1);
            stac.push_back(i);
        }
        while(stac.size()){
            int r = min(n,stac.back()+k);
                // cout<<r<<" "<<max_range_l[stac.back()]<<" "<<nums[stac.back()]<<endl;
            ans+= calc(max_range_l[stac.back()],stac.back(),r,nums[stac.back()],k);
            stac.pop_back();
        }
        return ans;
    }
};