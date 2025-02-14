#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int round = minutesToTest/minutesToDie;
        vector<vector<long long>> dp(round+1,vector<long long>(11,1));
        long long bar[11];bar[0] = 1;
        for(int i=0;i<=10;i++){
            if(i>0)bar[i] = bar[i-1]*i;
            dp[1][i]=(1<<i);
            if(1==round&&dp[1][i]>=buckets)return i;
        }
        for(int i=2;i<=round;i++){
            
            for(int j=1;j<=10;j++){
                dp[i][j] = 0;
                for(int k = 0;k<=j;k++){
                    long long cjk = bar[j]/(bar[j-k]*bar[k]);    
                    long long  tmp = cjk*dp[i-1][k];
                    dp[i][j] += tmp;
                    if(dp[i][k]>1000){dp[i][k]=1000;break;}
                }
                if(i==round&&dp[i][j]>=buckets)return j;
            }
        }
        return 10;
    }
};