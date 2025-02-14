#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        
        vector<int> dp(ring.size(),1e9),predp(ring.size(),1e9);
        int idx = 0;
        for(int i=0;i<ring.size();i++){
            if(ring[i]==key[idx])predp[i]=min(i,int(ring.size()-i));
        }idx++;
        dp = predp;
        for(;idx<key.size();idx++){
            for(int i=0;i<ring.size();i++){
                if(ring[i] == key[idx]){
                    int tmp =1e9;
                    for(int j=0;j<ring.size();j++){
                        int d = abs(i-j);
                        d = min(d,int(ring.size()-d));
                        // cout<<"idx,i,j "<<idx<<" "<<i<<" "<<j<<" "<<d<<" "<<predp[j]<<endl;
                        tmp = min(tmp,predp[j]+d);
                    }
                    dp[i]=tmp;
                }else {dp[i]=1e9;}
            }
            predp = dp;
        }
        int ans = 1e9;
        for(auto a:dp){ans = min(ans,a);}//cout<<a<<" ";}cout<<endl;
        // cout<<ans;
        return ans + key.size();
        
    }
};