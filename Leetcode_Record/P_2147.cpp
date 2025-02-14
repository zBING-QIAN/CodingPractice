#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        int S = 0,P=0;
        long long pre=1,ans = 0;
        int mod = 1e9+7;
        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S'){
                if(S==2){S=0;ans=(pre*(P+1))%mod;pre = ans;}
                S++;P=0;
            }else {
                if(S==2){
                    P++;
                }
            }
        }
        if(S!=2)return 0;
        if(ans==0)ans=1;
        return ans;
    }
};