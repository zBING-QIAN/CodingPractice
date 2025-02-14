#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumScores(string s) {
        vector<int> fp(s.size()+1,-1);
        for(int i=0;i<s.size();i++){
            int p = fp[i];
            while(p>=0&&s[p]!=s[i]){p=fp[p];}
            fp[i+1] = p+1;    
        }
        for(int i=0;i<s.size();i++)fp[i] = fp[i+1];fp[s.size()]=0;
        long long ans=0;
        vector<int> dp(s.size()+1,0);
        int j=1;
        for(;j<s.size()&&s[j]==s[j-1];j++);
        for(int i=1;i<j;i++){
            dp[i] = j-i;
        }
        int tmp = 0;
        for(int i=j+1,pre= j+1;i<=s.size();i++){
            if(i<s.size()&&fp[i])dp[i-fp[i]+1] = fp[i];
            // cout<<pre<<" "<<i-fp[i]+1<<" "<<fp[i]<<endl;
            if(i==s.size()||i-fp[i]+1>pre){
                // for(int h=pre,k=0;h<=s.size();h++,k++)if(h==s.size()||s[h]!=s[k]){tmp = k;break;}
                // cout<<"error at "<<pre<<" "<<dp[pre]<<" "<<tmp<<" "<<i<<endl;
                pre++;
                int nxt_pre = (i==s.size())?s.size():i-fp[i]+1;
                for(int j=1;pre<nxt_pre;pre++,j++){
                    dp[pre] = min(dp[j],fp[i-1]-j);
                    
                    // for(int h=pre,k=0;h<=s.size();h++,k++)if(h==s.size()||s[h]!=s[k]){tmp = k;break;}
                    // cout<<"error at "<<pre<<" "<<dp[pre]<<" "<<tmp<<endl;
                }
            }
        }
        for(int i=1;i<dp.size();i++)ans+=dp[i];
        ans+=s.size();
        return ans;
    }
};