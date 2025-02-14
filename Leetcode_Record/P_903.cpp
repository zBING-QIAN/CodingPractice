#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numPermsDISequence(string S) {
        int dp[201];
        dp[0]=1;
        for(int i=1;i<201;i++){
            dp[i]=0;               
        }
        for(int i=0;i<S.size();i++){
            if(S[i]=='D'){
                for(int j=i;j>=0;j--){
                    dp[j]=(dp[j+1]+dp[j])%1000000007;
                }
            }
            else{
                int tmp=dp[0];
                dp[0]=0;
                for(int j=1;j<=i+1;j++){
                    swap(tmp,dp[j]);
                    dp[j]=(dp[j-1]+dp[j])%1000000007;
                }
            }
            
        }
        int ans=0;
        for(int i=0;i<201;i++){
            ans+=dp[i];
            ans=ans%1000000007;
        }
        return ans;
    }
};
