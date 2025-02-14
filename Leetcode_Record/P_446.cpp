#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<map<long long,pair<int,int>>> rec(nums.size());
        int ans = 0;
        
        for(int i = 0;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                long long dif = (long long)nums[i]- (long long)nums[j];
                if(rec[i].find(dif)==rec[i].end())rec[i][dif] = {0,0};
                if(dif> INT_MAX||dif<INT_MIN||dif==0)continue;
                if(rec[j].find(dif)!=rec[j].end()){
                    int add = rec[j][dif].second+rec[j][dif].first;
                    rec[i][dif].first += add;
                    ans += add;
                    cout<<nums[i]<<" "<<nums[j]<<" dif "<<dif<<" "<<add<<endl;
                }
                    rec[i][dif].second++;
                
            }
        }
        cout<<ans<<" before \n";
        sort(nums.begin(),nums.end());
        int cnt_tmp=0;
        int tmp = nums[0];
        for(auto a:nums){
            if(tmp!=a){
                tmp=a;
                if(cnt_tmp>=3)ans+=((long long)(1)<<cnt_tmp)-1-cnt_tmp-(((cnt_tmp-1)*cnt_tmp)>>1);
                cnt_tmp=1;
                }
            else cnt_tmp++;
        }
        if(cnt_tmp>=3)ans+=((long long)(1)<<cnt_tmp)-1-cnt_tmp-(((cnt_tmp-1)*cnt_tmp)>>1);
        return (int)(ans);
    }
};