#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int mod = 1e9+7;
        long long ans=0;
        long long small_sum =0;
        long long sum_tmp=0;
        vector<long long> small_list,small_cnt,dp;
        vector<long long>total,sum;
        for(int i=0;i<strength.size();i++){
            if( i>0){
                sum.push_back((sum.back()+strength[i])%mod);
                total.push_back((total.back()+((long long)(strength[i])*(i+1))%mod)%mod);
            }
            else {
                sum.push_back((strength[i])%mod);
                total.push_back(((strength[i]*(i+1))%mod)%mod);    
            }
            int cnt_tmp = 1;
            while(small_list.size()>0&&strength[i]<=small_list.back()){
                small_sum =  (small_sum - small_list.back()*small_cnt.back())%mod;
                cnt_tmp +=small_cnt.back();
                small_cnt.pop_back();
                small_list.pop_back();
            }
            small_cnt.push_back(cnt_tmp);small_list.push_back(strength[i]);
            long long tmp0 = total[i];
            long long tmp1 = 0;
            long long tmp2 = 0;
            long long tmp3 = 0;
            // cout<<tmp0<<" "<<tmp1<<" "<<cnt_tmp<<endl;
            if(i>=cnt_tmp){
                tmp0 = (tmp0-total[i-cnt_tmp])%mod;
                tmp1 = ((sum[i]-sum[i-cnt_tmp])*(i-cnt_tmp+1))%mod;
                // cout<<" in cond "<<sum[i]<<" "<<sum[i-cnt_tmp]<<endl;
                tmp2 = (dp[i-cnt_tmp]+((sum[i]-sum[i-cnt_tmp])*small_sum)%mod)%mod;
            }
            // cout<<tmp0<<" ,"<<tmp1<<endl;
            tmp0 = (tmp0-tmp1)%mod;
            // cout<<tmp0<<" ,"<<small_sum<<" "<<strength[i]<<endl;
            dp.push_back((tmp0*strength[i]%mod));
            // ans = (ans+tmp0*strength[i])%mod;
            dp.back() = (dp.back()+tmp2)%mod;
            ans = (ans +dp.back())%mod;
            // cout<<ans<<endl;
            small_sum = (small_sum +small_list.back()*small_cnt.back())%mod;

        }
        return ans;
    }
};