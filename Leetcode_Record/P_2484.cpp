#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromes(string s) {
        int mod =1e9+7;
        long long ans =0;
        long long dp_m[300],*dp2[10],*dp3[10],*dp4[10],fcnt[10];
        memset(dp_m,0,sizeof(dp_m));
        for(int i=0;i<10;i++)dp2[i] = &dp_m[i*10];
        for(int i=10;i<20;i++)dp3[i-10] = &dp_m[i*10];
        for(int i=20;i<30;i++)dp4[i-20] = &dp_m[i*10];

        for(int i=0;i<10;i++)fcnt[i]=0;
        
        for(int i=0;i<s.size();i++){
            int c = s[i]-'0';
            for(int j=0;j<10;j++){
                ans = (ans+dp4[c][j])%mod;
            }

            for(int j=0;j<10;j++){
                dp4[j][c]=(dp4[j][c]+dp3[j][c])%mod;
            }
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    dp3[j][k]=(dp3[j][k]+dp2[j][k])%mod;
                }
            }

            for(int j=0;j<10;j++){
                dp2[j][c]=(dp2[j][c]+fcnt[j])%mod;
            }
            fcnt[c]++;
        }
        return ans;
    }
};