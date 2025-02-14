#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        map<int,int> dpl,dpr;
        vector<int> recl(nums.size(),1),recr(nums.size(),1);
        dpl[nums[0]]=1;
        for(int i=1;i<nums.size();i++){
            auto lb = dpl.lower_bound(nums[i]);if(lb==dpl.begin())lb = dpl.end();else lb--;
            if(lb!=dpl.end()){
                recl[i]=lb->second+1;
                lb=dpl.upper_bound(nums[i]);
                vector<int> erase_v;
                while(lb!=dpl.end()){
                    if(lb->second<=recl[i]){
                        erase_v.push_back(lb->first);lb++;
                    }else break;
                }
                for(auto v:erase_v){dpl.erase(v);}//cout<<i<<" "<<recl[i]<<endl;
            }
            else recl[i] = 1;    
            dpl[nums[i]] = recl[i];
        }
        reverse(nums.begin(),nums.end());
        dpr[nums[0]]=1;
        for(int i=1;i<nums.size();i++){
            auto lb = dpr.lower_bound(nums[i]);if(lb==dpr.begin())lb = dpl.end();else lb--;
            if(lb!=dpr.end()){
                recr[i]=lb->second+1;
                lb=dpr.upper_bound(nums[i]);
                vector<int> erase_v;
                while(lb!=dpr.end()){
                    if(lb->second<=recr[i]){
                        erase_v.push_back(lb->first);lb++;
                    }else break;
                }
                for(auto v:erase_v){dpr.erase(v);}
            }
            else recr[i] = 1;    
            dpr[nums[i]] = recr[i];
        }
        reverse(recr.begin(),recr.end());
        int ans = nums.size(),total = nums.size();
        for(int i=1;i<nums.size()-1;i++){
            // cout<<recr[i]<<" "<<recl[i]<<endl;
            if(recr[i]!=1 && recl[i]!=1)
                ans = min(ans,total-recl[i]-recr[i]+1);
        }
        return ans;
    }
};