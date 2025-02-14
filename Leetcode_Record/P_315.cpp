#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> rec(3e4,0),ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){nums[i]+=1e4+1;} 
        for(int i=nums.size()-1;i>=0;i--){
            int tmp = nums[i]-1,cnt = 0;
            while(tmp){
                cnt+=rec[tmp];
                tmp^=(tmp&(-tmp));
            }
            ans[i] = cnt;
            tmp = nums[i];
            while(tmp<3e4){
                rec[tmp]++;
                tmp+=(tmp&(-tmp));
            }
        }
        return ans;
    }
};