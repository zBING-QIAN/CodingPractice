#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxProduct(string s) {
        vector<int> dp(s.size(),1);
        for(int i=1,c=0;i<s.size();i++){
            int r = (c+dp[c]>i)?dp[c-(i-c)]:1;
            r = min(r,dp[c]-(i-c));
            if(r+i>=c+dp[c]){
                for(;i+r<s.size()&&i-r>=0&&s[i+r]==s[i-r];r++);
                dp[i] = r;c = i;
            }else dp[i] = r;
        }
        //for debug
        // cout<<s<<endl;for(auto d:dp)cout<<d<<" ";cout<<endl;
        vector<int> left(s.size(),1),right(s.size(),1);
        for(int i=0;i<s.size();i++){
            int to = dp[i]+i;
            if(to<s.size())left[to] = max(left[to],dp[i]);
        }
        for(int i=s.size()-2,tmp = left.back();i>=0;i--){
            tmp--;
            if(left[i]>tmp){
                tmp = left[i];
            }else {
                left[i] = tmp;
            }
        }
        for(int i=1;i<s.size();i++){
            left[i] = max(left[i],left[i-1]);
        }
        left[0] = 0;

        for(int i=0;i<s.size();i++){
            int to = i-dp[i]+1;
            right[to] = max(right[to],dp[i]);
        }
        for(int i=1,tmp = right[0];i<s.size();i++){
            tmp--;
            if(right[i]>tmp){
                tmp = right[i];
            }else {
                right[i] = tmp;
            }
        }
        for(int i=s.size()-2;i>=0;i--){
            right[i] = max(right[i],right[i+1]);
        }
        long long ans =0;
        for(int i=0;i<s.size();i++){
            long long tmp = (long long)(left[i]*2-1)*(long long)(right[i]*2-1);
            ans = (ans>tmp)?ans:tmp;
        }
        return ans;
    }
};