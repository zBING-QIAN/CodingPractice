#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        long long ans=0,pre0=1,pre1=1;
        int mod = 1e9+7;
        bool contain0=0;
        for(int i=binary.size()-1;i>=0;i--){
            if(binary[i]=='1'){
                ans+=pre1;
                pre0+=pre1;
                ans%=mod;pre0%=mod;
            }else{
                contain0=1;
                pre1+=pre0;
                pre1%=mod;
            }
        }
        return ans+contain0;
    }
};