#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int getLengthOfOptimalCompression(string s, int k) {
        vector<vector<int>> dp(k+1,vector<int>());
        for(int i=0;i<=k;i++)dp[i].resize(s.size()+1,0);
        dp[0][s.size()-1]=1;
        vector<pair<int,int>> link[26];
        for(int i=0;i<26;i++)link[i].push_back({s.size(),(i == s[s.size()-1]-'a')});
        for(int i=s.size()-2;i>=0;i--){
            if(s[i]!=s[i+1]){
                dp[0][i] = dp[0][i+1]+1;//cout<<i<<" "<<dp[0][i]<<endl;
                link[s[i]-'a'].push_back({i+1,1});
            }else {
                int tmp = ++link[s[i]-'a'].back().second;
                dp[0][i] = dp[0][i+1]+(tmp==1||tmp==2||tmp==10||tmp==100);
            }
            int delete_cnt = 0,total_cnt=0;
            for(int d=1;d<=k;d++){dp[d][i]= dp[d-1][i+1];}//cout<<"d i "<<d<<" "<<i<<" "<<dp[d][i]<<endl;}
            for(int j=link[s[i]-'a'].size()-1;j>=0;j--){
                // cout<<" debug  "<<dp[k][0]<<endl;
                auto [pre_pos,cnt] = link[s[i]-'a'][j];
                total_cnt += cnt;
                delete_cnt = pre_pos-i-total_cnt;
                for(int d=0;d+delete_cnt<=k;d++){
                    int tmp =dp[d][pre_pos]+((total_cnt>0)?(total_cnt>1)?(total_cnt>9)?(total_cnt>99)?4:3:2:1:0);
                    // cout<<dp[delete_cnt+d][i]<<" "<<tmp<<endl;
                    dp[delete_cnt+d][i] = min(dp[delete_cnt+d][i],tmp);
                    // cout<<delete_cnt+d<<" "<<i<<" "<<tmp<<" "<<dp[delete_cnt+d][i]<<" prev pos "<<pre_pos<<" "<<d<<" "<<dp[d][pre_pos]<<" "<<total_cnt<<endl;
                }
            }
        }
        return dp[k][0];
    }
};