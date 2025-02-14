#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size(),plen = p.size();
        string tmp =p.substr(0,1);
        for(int i=1,j=0;i<plen;i++){
            if(tmp[j]!='*'||p[i]!='*'){
                tmp = tmp+p[i];j++;
            }
        }
        p = tmp;
        int first = 0,first_tmp = 0;
        plen = p.size();
        vector<int> dp(slen+1,-2);dp[0] = -1;
        for(int i=0;i<plen;i++){
            // for(int j=0;j<=slen;j++)cout<<dp[j]<<" ";cout<<endl;
            if(p[i]=='*'&&dp[first] == i-1) for(int j=first;j<=slen;j++)dp[j]=i;
            else for(int j=slen;j>first;j--){
                // cout<<i<<" "<<j<<" "<<p[i]<<" "<<s[j-1]<<" "<<dp[j-1]<<endl;
                if(dp[j-1]==i-1){
                    if(p[i]=='?'||p[i]==s[j-1]){
                        dp[j] = i;first_tmp = j;//cout<<i<<" "<<first<<endl;
                    }
                      
                } 
            }first = first_tmp;
        }
        return dp[slen]==plen-1;
    }
};