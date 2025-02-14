#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        vector<long long> ans(5,1);
        int mod = 1e9+7;
        for(int i=1;i<n;i++){
            vector<long long> ans_nxt(5,0);
            ans_nxt[0] = (ans[1]+ans[2]+ans[4])%mod;
            ans_nxt[1] = (ans[0]+ans[2])%mod;
            ans_nxt[2] = (ans[1]+ans[3])%mod;
            ans_nxt[3] = ans[2];
            ans_nxt[4] = (ans[2]+ans[3])%mod;
            ans = ans_nxt;
        }
        long long out = 0;
        for(int i=0;i<5;i++)out = (out+ans[i])%mod;
        return out;
    }
};