#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9+7;
    map<pair<int,int>,int> dp;
    int solve(string &s,int a,int b){//cout<<a<<" "<<b<<endl;
        if(dp.find({a,b})!=dp.end()){
            return dp[{a,b}];
        }
        char cur= s[a];
        for(;b>a;b--)if(s[b]==cur)break;
        if(a==b)return 1;
        if(b-a==1)return 2;
        int f[4],t[4];
        long long ans = 0;
        for(int k =0;k<4;k++){
            f[k]=-1;
            for(int i=a+1;i<b;i++){
                if(s[i]=='a'+k){f[k]=i;break;}
            }
            if('a'+k==s[a])ans+=2;
            if(f[k]==-1){ continue;}
            t[k]=f[k];
            for(int i=b-1;i>f[k];i--){
                if(s[i]=='a'+k){t[k]=i;break;}
            }
            ans = (ans+solve(s,f[k],t[k]))%mod;
        }
        dp[{a,b}] = ans;//cout<<a<<" "<<b<<" "<<ans<<endl;
        return ans;
    }
    int countPalindromicSubsequences(string s) {
        int f[4],t[4];
        long long ans = 0;
        for(int k =0;k<4;k++){
            f[k]=-1;
            for(int i=0;i<s.size();i++){
                if(s[i]=='a'+k){f[k]=i;break;}
            }
            if(f[k]==-1)continue;
            t[k] = f[k];
            //cout<<"k pass "<<k<<endl;
            for(int i=s.size()-1;i>f[k];i--){
                if(s[i]=='a'+k){t[k]=i;break;}
            }
            ans = (ans+solve(s,f[k],t[k]))%mod;
        }
        return ans;
    }
};