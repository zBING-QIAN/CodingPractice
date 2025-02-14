#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans =0;
        long long max_range=0;
        for(auto a:nums){

            if(max_range>=n)return ans;
            while(max_range+1<a){
                ans++;max_range = (max_range<<1)+1;
                if(max_range>=n)return ans;
            }
            max_range+=a;
        }
        while(max_range+1<n){
            ans++;max_range = (max_range<<1)+1;
            if(max_range>=n)return ans;
        }
        return ans;
    }
};