#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int head(vector<int> &sid,int cur){
        vector<int> tmp;
        while(cur!=sid[cur]){tmp.push_back(cur); cur= sid[cur];}
        for(auto &t:tmp)sid[t] = cur;
        return cur;
    }

    bool gcdSort(vector<int>& nums) {
        vector<int> new_nums = nums;
        sort(new_nums.begin(),new_nums.end());
        vector<int> sid(new_nums.back()+1,0);
        vector<bool> in_nums(sid.size(),0);
        for(int i=0;i<sid.size();i++){if(i&1)sid[i]=i;else sid[i]=2;}
        for(int i=0;i<nums.size();i++)in_nums[nums[i]]=1;
        for(int i=3;i<sid.size();i++){
            if(sid[i]==i){ // is prime
                for(int j=i*2;j<sid.size();j+=i){
                    if(sid[j]!=j&&in_nums[j]){
                        int tmp0 = head(sid,j);
                        sid[tmp0] = i;
                    }
                    sid[j] = i;
                }
            }
        }
        for(int i=0;i<new_nums.size();i++){
            int tmp0 = head(sid,new_nums[i]);
            int tmp1 = head(sid,nums[i]);
            // cout<<new_nums[i]<<" "<<nums[i]<<" "<<tmp0<<" "<<tmp1<<endl;
            if(tmp0!=tmp1)return 0;
        }
        return 1;
    }
};