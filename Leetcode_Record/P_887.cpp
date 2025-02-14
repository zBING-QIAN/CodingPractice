#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<int> dp(n+1,0);for(int i=1;i<=n;i++)dp[i]=i;
        for(int i=2;i<=k;i++){
            vector<int> nxt(n+1,0);
            nxt[1]=1;
            // cout<<"******\n";
            for(int j=2,t=0;j<=n;j++){
                int  a = dp[j]+1;
                int tmp;//cout<<"dpj "<<a<<endl;
                for(t= max(0,t-1);t<j;t++){
                    int tmp_v =1+max(dp[j-t-1],nxt[t]); 
                    if(a>=1+max(dp[j-t-1],nxt[t])){a = 1+max(dp[j-t-1],nxt[t]);tmp =t;}
                    else break;
                  //  cout<<tmp<<" "<<t<<" "<<a<<" "<<tmp_v<<endl;
                }
                // cout<<tmp<<" "<<a<<endl;
                nxt[j] = a;
            }
            dp = nxt;
            // for(auto d :dp)cout<<d<<" ";cout<<endl;
        }
        return dp[n];
    }
};